
// struct com os vértices e a distância entre eles
typedef struct{

	int v, u;
	float dist;

}tNode;

// struct com a fila de prioridades, o número de nós máximo (número de arestas)
// e a posição para o ultimo nó da fila
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
