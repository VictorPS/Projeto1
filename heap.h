

typedef struct{

	int v, u;
	float dist;

}tNode;

typedef struct{

	tNode *fila;
	int numNos;
	int ultimo;

}tHeap;


void inicializaHeap(tHeap* heap, int tam);
void liberaHeap(tHeap* heap);
