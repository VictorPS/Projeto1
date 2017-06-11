#include <stdlib.h>
#include <math.h>
#include "grafosM.c"
#include "heap.c"
#include "kruskal.c"
//#include "prim.c"

typedef struct {

	float x;
	float y;

} tPonto;

int main(int argc, char** argv){

    int k =6;
	int v = 0, i, j;
	float data;
	FILE *in, *out;

	tGrafo g;
	tGrafo minima;
	tHeap heap;
	tPonto *cont;
	tNode aux;
	int *classes;

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
	inicializaGrafo(&minima, v);

	inicializaHeap(&heap, v*v);

    classes = (int*)malloc(sizeof(int)*v);


    // Calcula as distancias entre todos os vertices criando um
    // grafo fortemente conexo.
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			if(i!=j){
				data = powf((cont[j].x - cont[i].x), 2);
				data += powf((cont[j].y - cont[i].y), 2);
				data = sqrtf(data);
				insereAresta(&g, i, j, data);
			}
		}
	}

	// faz o algoritmo de kruskall
    doKruskal(&g, &classes, &heap, v, &minima, k);
    // coloca no arquivo de saida as classes
    K_criaArquivoClasses(&classes, out, v, k);


//	printQueue(&heap);
//
///*	while(!isEmpty(&heap)){*/
//		aux = popNode(&heap);
//		printf("Informacoes dos elementos: %d, %d, %.2f\n", aux.u, aux.v, aux.dist);
///*	}*/
//
//	printf("Ultimo = %d\n", heap.ultimo);
//
//	printQueue(&heap);

	liberaGrafo(&g);
	liberaGrafo(&minima);
	liberaHeap(&heap);

	free (cont);
    free (classes);

	fclose (in);
	fclose (out);

	return EXIT_SUCCESS;
}
