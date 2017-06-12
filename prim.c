#include <stdlib.h>
#include "prim.h"

void inicializaPrim(tNode **prim, int v){

	(*prim) = (tNode*)calloc(v, sizeof(tNode));

}

void primAlgorithm(tGrafo *g, tNode **prim){

	int i;
	int t_size = 1, origem, jorge, retira = 1;

	char *t;

	float dist_aux;

	tHeap my_heap;
	tNode aux;

	t = (char*)calloc(g->numVertices, sizeof(char));

	t[0] = 1;
	origem = 0;

	inicializaHeap(&my_heap, g->numVertices*g->numVertices);

	while(t_size < g->numVertices){
		for(i=0; i<g->numVertices; i++){
			if(t[i] == 0){
				recuperaAdj(g, origem, i, &jorge, &dist_aux);
				aux.v = origem;
				aux.u = i;
				aux.dist = dist_aux;

				pushNode(&my_heap, aux);
			}
		}

		while(retira){

			aux = popNode(&my_heap);

			if(t[aux.u] == 0){
				retira = 0;
				t[aux.u] = 1;
				origem = aux.u;
				(*prim)[t_size-1] = aux;
				t_size++;

			}

		}

		retira = 1;

	}
	
	liberaHeap(&my_heap);
	free (t);
}

void primClasses(int **classes, tNode **prim, int total, int clusters){

	int i, j, aux = 1, quebra = 0;

	tNode *local_list;

	local_list = (tNode*)malloc(total*sizeof(tNode));

	for(i=0; i<total; i++)
		local_list[i] = (*prim)[i];
	
	qsort(local_list, total, sizeof(tNode), compare);

	for(i=0; i<total; i++){
		for(j=0; j<clusters; j++){

			if((*prim)[i].v == local_list[j].v && (*prim)[i].u == local_list[j].u){
				
				quebra = 1;
				break;

			}

		}

		if(!quebra){
			(*classes)[(*prim)[i].u] = (*classes)[(*prim)[i].v];
		}

		else{

			if((*classes)[(*prim)[i].v] == 0)
				(*classes)[(*prim)[i].v] = aux;
			aux++;
			(*classes)[(*prim)[i].u] = aux;

			quebra = 0;

		}

	}

	free(local_list);

}

int compare (const void *a, const void *b){

	tNode *fa = (tNode *) a;
	tNode *fb = (tNode *) b;
  
	return (fa->dist < fb->dist) - (fa->dist > fb->dist);
}




















