#include "grafosM.h"

void inicializaGrafo(tGrafo *g, tVertice numVertices)
{
	int i;

	g->mat = (tPeso**)malloc(numVertices*sizeof(tPeso*));
	
	for (i = 0; i < numVertices; i++)
		g->mat[i] = (tPeso*)calloc(numVertices, sizeof(tPeso));

	g->numVertices = numVertices;
}

void insereAresta(tGrafo *g, tVertice v, tVertice u, tPeso peso)
{
	g->mat[v][u] = peso;
}

int existeAresta(tGrafo *g, tVertice v, tVertice u)
{
//	if (g->mat[v][u] != 0)
//		return 1;
//	else
//		return 0;

	return g->mat[v][u] != 0;
}

void retiraAresta(tGrafo *g, tVertice v, tVertice u)
{
	g->mat[v][u] = 0;	
}

void liberaGrafo(tGrafo *g)
{
	int i;
	
	for(i=0; i<g->numVertices; i++)
		free(g->mat[i]);

	free(g->mat);
}

int existeAdj(tGrafo *g, tVertice v)
{
	tVertice i;

	for (i = 0; i < g->numVertices; i++)
	 	if (g->mat[v][i] != 0)
			return 1;
	return 0;
}

tVertice primeiroAdj(tGrafo *g, tVertice v)
{
	tVertice i;

	for (i = 0; i < g->numVertices; i++)
	 	if (g->mat[v][i] != 0)
			return i;
	return NULO;
}

tVertice proximoAdj(tGrafo *g, tVertice v, tApontador u)
{
	tVertice aux = u + 1;
	for (; aux < g->numVertices; aux++)
	 	if (g->mat[v][aux] != 0)
			return aux;
	return NULO;		
}

void recuperaAdj(tGrafo *g, tVertice v, tVertice p, tApontador *u, tPeso *peso)
{
	*u = p;
	*peso = g->mat[v][p];
}

void imprimeGrafo(tGrafo *g)
{
	int i, j;

	for (i = 0; i < g->numVertices; i++)
	{
		for (j = 0; j < g->numVertices; j++)
			printf("%.2f ", g->mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
