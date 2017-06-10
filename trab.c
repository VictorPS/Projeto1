#include <stdlib.h>
#include <math.h>
#include "grafosM.c"
#include "heap.c"

// Struct de pontos
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
<<<<<<< HEAD
	tNode aux;
	
=======

>>>>>>> 0ea10f71177f589c1ff6189853672289a4c76123
	in = fopen ("data.txt", "r");
	out = fopen ("out.txt", "w");

// conta o numero de linhas do arquivo pois é o número de vértices
	while(!feof(in)){
		if (getc(in) == '\n')
			v++;
	}

	rewind(in);

<<<<<<< HEAD
	cont = (tPonto*)malloc(v*sizeof(tPonto));

	for(i=0; i<v; i++)
		fscanf(in, "%f %f", &cont[i].x, &cont[i].y);
	
	inicializaGrafo(&g, v);
	inicializaHeap(&heap, 10);

	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
=======
//  vetor com o número de pontos
	cont = (tPonto*)malloc(n*sizeof(tPonto));

// leitura do arquivo e atribuição dos valores de x e y de cada ponto no vetor
	for(i=0; i<n; i++)
		fscanf(in, "%f %f", &cont[i].x, &cont[i].y);


	inicializaGrafo(&g, n);

    // insere o valor de cada aresta como a distancia entre os pontos (vértices)
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
>>>>>>> 0ea10f71177f589c1ff6189853672289a4c76123
			if(i!=j){
				data = powf((cont[j].x - cont[i].x), 2);
				data += powf((cont[j].y - cont[i].y), 2);
				data = sqrtf(data);
				insereAresta(&g, i, j, data);
			}
<<<<<<< HEAD
			if(i == 0 && j<11 && j>0){
				aux.v = i;
				aux.u = j;
				aux.dist = g.mat[i][j];
				pushNode(&heap, aux);
			}
		
=======

>>>>>>> 0ea10f71177f589c1ff6189853672289a4c76123
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
<<<<<<< HEAD
	liberaHeap(&heap);
	
=======

>>>>>>> 0ea10f71177f589c1ff6189853672289a4c76123
	free (cont);

	fclose (in);
	fclose (out);

	return EXIT_SUCCESS;
}
