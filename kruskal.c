#include "kruskal.h"
#ifndef HEAP_H
#include "heap.h"
#endif // HEAP_H
#ifndef GRAFOSM_H
#include "grafosM.c"
#endif // GRAFOSM_H
#include <stdlib.h>
#include <stdio.h>


// A função K_insereHeap insere todas as arestas do grafo na heap
// Variaveis:
// g - contem o grafo
// h - contem a fila de prioridades/ heap
// nVertices - número de vertices do grafo
// i,j - contadores para percorrer o grafo
// Jorge - variável criada apenas como parametro para utilizar a
// função recuperaAdj , ou seja não é utilizada para nada.
// no - variável que recebe os valores do grafo e é inserido na heap
void K_insereHeap(tGrafo *g, tHeap *h, int nVertices){
    int i, j;
    int Jorge;
    tNode no;
    for(i = 0; i<nVertices; i++){
       for(j = i+1; j<nVertices; j++){
            if(existeAresta(g, i,j)){
                no.v = i;
                no.u = j;
                recuperaAdj(g, i, j , &Jorge, &(no.dist));
                pushNode(h, no);
            }
       }
    }
}

// gera a arvore mínima utilizando o algoritmo de kruskal
// Variaveis:
// g - contem o grafo
// classes - vetor que possui as classes dos vertices, sendo cada
// posição no vetor a chave que identifica o vértice
// q - contem a fila de prioridades/ heap
// nVertices - número de vértices do grafo
// krusk - grafo que contem a arvore mínima gerada por kruskal quando k = 0
// k - numero de arestas retiradas para formar os clusteres
void doKruskal(tGrafo *g, int **classes, int nVertices, tGrafo *krusk, int k){
    tHeap q;
    int c = 1;
    int n = 0;
    int i;

    inicializaHeap(&q, nVertices*nVertices);

    for(i=0; i<nVertices;i++){
        (*classes)[i] = 0;
    }

    K_insereHeap(&(*g) , &q ,nVertices);

    while(n < nVertices - k - 1){
        K_union(classes, &q, &c, &n, nVertices, krusk);
        if(isEmpty(&q)){
            printf("Erro, a heap chegou ao fim e nao foi possivel gerar os clusters\n");
            break;
        }
    }
}

// A função K_union realiza a união de conjuntos ao classificar os vertices com
// a mesma classe
// classes - vetor de classes sendo cada posição um vértice.
// q - contem a fila de prioridades/ heap
// c - valor de classe a qual não pertence a nenhum vertice
// nVertices - número de vértices
// krusk - grafo que contem a arvore mínima gerada por kruskal quando k = 0
// node.v - vértice atual
// node.u - vértice ligado a v
void K_union(int **classes, tHeap *q, int* c, int *n, int nVertices, tGrafo *krusk){
    tNode node = popNode (q);
    int i;
    // caso v e u não possuam uma classe, ambos recebem a mesma classe c
    if(K_find(classes, node.v) == 0 && K_find(classes, node.u) == 0){
        (*classes)[node.v] = (*c);
        (*classes)[node.u] = (*classes)[node.v];
        (*c)++;
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
    // caso v possua uma classe e u não possua, u recebe a classe de v
    else if(K_find(classes, node.v) != 0 && K_find(classes, node.u) == 0){
        (*classes)[node.u] = (*classes)[node.v];
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
    // caso u possua uma classe e v não possua, v recebe a classe de u
    else if(K_find(classes, node.v) == 0 && K_find(classes, node.u) != 0){
        (*classes)[node.v] = (*classes)[node.u];
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
    // caso ambos possuam classe e são classes diferentes todos os vertices que
    // possuirem a mesma classe de u recebem a classe de v
    else if(K_find(classes, node.v) != 0 && K_find(classes, node.u) != 0 &&
            K_find(classes, node.v) != K_find(classes, node.u)){
        for(i=0; i<nVertices; i++){
            if(K_find(classes , i) == K_find(classes , node.u) && i != node.u){
                (*classes)[i] = (*classes)[node.v];
            }
        }
        (*classes)[node.u] = (*classes)[node.v];
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
}

// Função K_find retorna a classe do vértice de chave pos
int K_find(int **classes, int pos){
    return (*classes)[pos];
}

// Função K_criaArquivoClasses cria o arquivo de classes atribuindo novos valores
// para as classes sendo este valor entre 1 e k+1.
// classes - vetor que contém as classes dos vértices
// out - arquivo de saida que irá conter as classes de cada vertice
// nVertices - numero de vértices
// k - numero de arestas retiradas para formar os clusteres
void K_criaArquivoClasses(int **classes, FILE* out, int nVertices, int k){
    int *c;
    int i, j;
    c = (int*) malloc(sizeof(int)*(k+1));
    for(i = 0; i<k+1; i++){
        c[i] = -1;
    }
    // reclassifica os vértices para que a sua classe
    // varie entre 1 e k+1;
    for(i = 0; i<nVertices; i++){
        for(j=0; j<= k+1; j++){
            if((*classes)[i] == c[j] || c[j] == -1){
                c[j] = (*classes)[i];
                (*classes)[i] = j+1;
                break;
            }
        }
    }

    for (i=0; i<nVertices; i++){
        fprintf(out, "%d\n", (*classes)[i]);
    }
    free (c);
}
