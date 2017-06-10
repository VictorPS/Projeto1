
// struct com os v�rtices e a dist�ncia entre eles
typedef struct{

	int v, u;
	float dist;

}tNode;

// struct com a fila de prioridades, o n�mero de n�s m�ximo (n�mero de arestas)
// e a posi��o para o ultimo n� da fila
typedef struct{

	tNode *fila;
	int numNos;
	int ultimo;

}tHeap;


void inicializaHeap(tHeap* heap, int tam);
void liberaHeap(tHeap* heap);

void pushNode (tHeap *q, tNode node);
tNode popNode (tHeap *q);

int isEmpty (tHeap *q);
void printQueue (tHeap *q);
