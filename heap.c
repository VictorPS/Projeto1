#include "heap.h"

void inicializaHeap(tHeap* heap, int tam){

	heap->fila = (tNode*)malloc(tam*sizeof(tNode));

	heap->numNos = tam;
	heap->ultimo = -1;

}

void liberaHeap(tHeap* heap){
	free(heap->fila);
	heap->numNos = 0;
	heap->ultimo = -1;
}

void pushNode (tHeap *q, tNode node){

	int i, pai;

	tNode aux;

	q->ultimo += 1;

	i = q->ultimo;

	q->fila[i] = node;

	if(i%2 == 0 && i>0)
		pai = (i/2)-1;

	else
		pai = (i/2);

	while(q->fila[i].dist < q->fila[pai].dist && i > 0){	

		aux = q->fila[i];
		q->fila[i] = q->fila[pai];
		q->fila[pai] = aux;

		i = pai;

		
		if(i%2 == 0)
			pai = (i/2)-1;

		else
			pai = (i/2);
	}

};

tNode popNode (tHeap *q){
	
	int pai, dir, esq, menor, fim=0;
	
	tNode aux, toRet;

	toRet = q->fila[0];

	q->fila[0] = q->fila[q->ultimo];
	q->ultimo -= 1;

	pai = 0;

	while(!fim){

		esq = (2*pai)+1;
		dir = (2*pai)+2;

		if(esq > q->ultimo)
			fim = 1;

		else{
			if(dir > q->ultimo){
			
				if(q->fila[esq].dist <= q->fila[dir].dist)
					menor = esq;

				else
					menor = dir;
				
				printf("O menor eh %d\n", menor);

				if(q->fila[pai].dist > q->fila[menor].dist){
					aux = q->fila[pai];
					q->fila[pai] = q->fila[menor];
					q->fila[menor] = aux;
					pai = menor;
				}
				
				else
					fim = 1;
			
			}

			else{
				if(q->fila[pai].dist > q->fila[esq].dist){
					aux = q->fila[pai];
					q->fila[pai] = q->fila[esq];
					q->fila[esq] = aux;
					pai = esq;
				}
				
				else
					fim = 1;
			}
		}	
	}

	return toRet;

};

int isEmpty (tHeap *q){

	return (q->ultimo == -1);

};

void printQueue (tHeap *q){
	
	int i;

	for(i=0; i<=q->ultimo; i++)
		printf("%.2f\n", q->fila[i].dist);

};


