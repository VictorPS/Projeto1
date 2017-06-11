#include "kruskal.h"
#ifndef HEAP_H
#include "heap.h"
#endif // HEAP_H
#ifndef GRAFOSM_H
#include "grafosM.c"
#endif // GRAFOSM_H
#include <stdlib.h>
#include <stdio.h>

// insere todas as arestas na heap
// Jorge - variável criada para utilizar a função recuperaAdj, ou seja
// não é utilizada para nada
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
void doKruskal(tGrafo *g, int **classes, tHeap *q, int nVertices, tGrafo *krusk, int k){
    int c = 1;
    int n = 0;
    int i;

    for(i=0; i<nVertices;i++){
        (*classes)[i] = 0;
    }

    K_insereHeap(&(*g) , &(*q) ,nVertices);

    while(n < nVertices - k - 1){
        K_union(classes,q, &c, &n, nVertices, krusk);
        if(isEmpty(q)){
            printf("Erro, a heap chegou ao fim e nao foi possivel gerar os clusters\n");
            break;
        }
    }
}
// classes - vetor de classes sendo cada posição um vértice.
// v - vértice atual
// u - vértice ligado a v
void K_union(int **classes, tHeap *q, int* c, int *n, int nVertices, tGrafo *krusk){
    tNode node = popNode (q);
    int i;

    if(K_find(classes, node.v) == 0 && K_find(classes, node.u) == 0){
        (*classes)[node.v] = (*c);
        (*classes)[node.u] = (*classes)[node.v];
        (*c)++;
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
    else if(K_find(classes, node.v) != 0 && K_find(classes, node.u) == 0){
        (*classes)[node.u] = (*classes)[node.v];
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
    else if(K_find(classes, node.v) == 0 && K_find(classes, node.u) != 0){
        (*classes)[node.v] = (*classes)[node.u];
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
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

int K_find(int **classes, int pos){
    return (*classes)[pos];
}

// cria o arquivo de classes
void K_criaArquivoClasses(int **classes, FILE* out, int nVertices, int k){
    int *c;
    int i, j;
    c = (int*) malloc(sizeof(int)*(k+1));
    for(i = 0; i<k+1; i++){
        c[i] = -1;
    }
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
