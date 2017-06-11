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
    int *Jorge;
    tNode no;
    for(i = 1; i<nVertices; i++){
       for(j = i+1; j<nVertices; j++){
            if(NULO != existeAresta(g, i,j)){
                no.v = i;
                no.u = j;
                recuperaAdj(g, i, j , Jorge, &(no.dist));
                pushNode(h, no);
            }
       }
    }
}


void doKruskal(tGrafo *g, int **classes, tHeap *q, int nVertices, tGrafo *krusk, int k){
    int c = 1;
    int n = 0;

    K_insereHeap(g , q ,nVertices);

    while(n < nVertices - k){
        K_union(classes,q, &c, &n, nVertices, krusk);
        if(isEmpty(q)){
            printf("Erro, a heap chegou ao fim e não foi possível gerar os clusters\n");
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

    // v não tem classe
    if(*classes[node.v] == 0){
        // se u não tem classe, ambos recebem uma classe nova
        if(K_find(classes , node.u) == 0){
            *classes[node.v] = (*c);
            *classes[node.u] = (*c);
            (*c)++;
        }
        // se u já tiver classe, v recebe a sua classe
        else{
            *classes[node.v] = *classes[node.u];
        }
        (*n)++;
        insereAresta(krusk, node.v, node.u, node.dist);
    }
    // se ambos os vertices tiverem classes diferentes, todos os
    // vertices que possuirem a mesma classe de u recebem a classe de v
    else if(K_find(classes , node.v) != K_find(classes , node.u)){
        for(i=0; i<nVertices; i++){
            if(K_find(classes , i) == K_find(classes , node.v)){
                *classes[i] = *classes[node.u];
            }
        }
    }
    // se as classes de u e v forem a mesma, nada acontece.
}

int K_find(int **classes, int pos){
    return *classes[pos];
}
//
//void K_ArquivoClasses(int **classes, FILE* out, int nVertices){
//    int i;
//    for (i=0; i<nVertices; i++){
//        fprintf()
//    }
//}
