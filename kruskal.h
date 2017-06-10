#indef KRUSKAL.H
#define KRUSKAL.H
/* Todo - criar o vetor de classes na main


*/

// insere todas as arestas na heap
void K_insere(tGrafo *g, int numVertices, tHeap *h);
void K_geraArvore(tHeap *h, );
void K_union(int **classes, int classeFixa, int classeAtual);
int K_find(int **classes, int pos);


#endif
