#include <stdlib.h>
#include <math.h>
#include "grafosM.c"
#include "heap.c"
//#include "kruskal.c"
#include "prim.c"

typedef struct {

	float x;
	float y;

} tPonto;

int main(int argc, char** argv){

	int v = 0, i, j;
	float data;
	FILE *in, *out;

	tGrafo g;
	tHeap heap;
	tPonto *cont;
	tNode aux;
	
	in = fopen ("data.txt", "r");
	out = fopen ("out.txt", "w");

	while(!feof(in)){
		if (getc(in) == '\n')
			v++;
	}

	rewind(in);

	cont = (tPonto*)malloc(v*sizeof(tPonto));

	for(i=0; i<v; i++)
		fscanf(in, "%f %f", &cont[i].x, &cont[i].y);
	
	inicializaGrafo(&g, v);
	inicializaHeap(&heap, 10);

	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			if(i!=j){
				data = powf((cont[j].x - cont[i].x), 2);
				data += powf((cont[j].y - cont[i].y), 2);
				data = sqrtf(data);
				insereAresta(&g, i, j, data);
			}
			if(i == 0 && j<11 && j>0){
				aux.v = i;
				aux.u = j;
				aux.dist = g.mat[i][j];
				pushNode(&heap, aux);
			}
		
		}
	}

//	printQueue(&heap);

/*	while(!isEmpty(&heap)){*/
		aux = popNode(&heap);
		printf("Informacoes dos elementos: %d, %d, %.2f\n", aux.u, aux.v, aux.dist);

/*	}*/
	
	printf("Ultimo = %d\n", heap.ultimo);

	printQueue(&heap);

	liberaGrafo(&g);
	liberaHeap(&heap);
	
	free (cont);
	
	fclose (in);
	fclose (out);

	return EXIT_SUCCESS;
}
