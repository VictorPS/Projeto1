#include "heap.h"

void inicializaHeap(tHeap* heap, int tam){

	heap->fila = (tNode*)malloc(tam*sizeof(tNode));

	heap->numNos = tam;
	heap->ultimo = 0;

}

void liberaHeap(tHeap* heap){
	free(heap->fila);
}
