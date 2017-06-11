#ifndef KRUSKAL_H
#define KRUSKAL_H
/* Todo
    -   criar o vetor de classes na main
    -   criar a arvore minima na main (e inicializar)
    -
*/

void K_insereHeap(tGrafo *g, tHeap *h, int nVertices);
void doKruskal(tGrafo *g, int **classes, tHeap *q, int nVertices, tGrafo *krusk, int k);
void K_union(int **classes, tHeap *q, int* c, int *n, int nVertices, tGrafo *krusk);
int K_find(int **classes, int pos);


#endif
