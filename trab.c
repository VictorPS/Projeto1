#include <stdlib.h>
#include <math.h>
#include "grafosM.c"
#include "heap.c"

typedef struct {

	float x;
	float y;

} tPonto;

int main(int argc, char** argv){

	int n = 0, i, j;
	float data;
	FILE *in, *out;

	tGrafo g;
	tPonto *cont;
	
	in = fopen ("data.txt", "r");
	out = fopen ("out.txt", "w");

	while(!feof(in)){
		if (getc(in) == '\n')
			n++;
	}

	rewind(in);

	cont = (tPonto*)malloc(n*sizeof(tPonto));

	for(i=0; i<n; i++)
		fscanf(in, "%f %f", &cont[i].x, &cont[i].y);
	
	inicializaGrafo(&g, n);

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i!=j){
				data = powf((cont[j].x - cont[i].x), 2);
				data += powf((cont[j].y - cont[i].y), 2);
				data = sqrtf(data);
				insereAresta(&g, i, j, data);
			}
		
		}
	}

	liberaGrafo(&g);
	
	free (cont);
	
	fclose (in);
	fclose (out);

	return EXIT_SUCCESS;
}
