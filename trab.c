#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "grafosM.h"
#include "heap.h"
//#include "kruskal.h"
#include "prim.h"

typedef struct {

	float x;
	float y;

} tPonto;

int main(int argc, char** argv){

	int v = 0, i, j, clusters = 6;
	float data;
	
	int *classes;

	FILE *in, *out;

	tGrafo g;
	tHeap heap;
	tPonto *cont;
	tNode aux;
	tNode *prim;
	

	in = fopen ("data.txt", "r");
	out = fopen ("out.txt", "w");

	while(!feof(in)){
		if (getc(in) == '\n')
			v++;
	}

	rewind(in);

	cont = (tPonto*)malloc(v*sizeof(tPonto));
	classes = (int *)calloc(v, sizeof(int));

	for(i=0; i<v; i++)
		fscanf(in, "%f %f", &cont[i].x, &cont[i].y);

	inicializaGrafo(&g, v);

	inicializaPrim(&prim, v-1);

	for(i=0; i<v; i++){
		for(j=i+1; j<v; j++){
			data = powf((cont[j].x - cont[i].x), 2);
			data += powf((cont[j].y - cont[i].y), 2);
			data = sqrtf(data);
			insereAresta(&g, i, j, data);
			insereAresta(&g, j, i, data);
		}
	}

	primAlgorithm(&g, &prim);
	primClasses(&classes, &prim, g.numVertices-1, clusters);

	for(i=0; i<v; i++)
		fprintf(out, "%d\n", classes[i]);

//	printQueue(&heap);

/*	while(!isEmpty(&heap)){*/
//		aux = popNode(&heap);
//		printf("Informacoes dos elementos: %d, %d, %.2f\n", aux.u, aux.v, aux.dist);

/*	}*/

//	printf("Ultimo = %d\n", heap.ultimo);

//	printQueue(&heap);

	liberaGrafo(&g);

	free(cont);
	free(classes);
	free(prim);

	fclose (in);
	fclose (out);

	return EXIT_SUCCESS;
}
