#ifndef GRAFOSM_H
#define GRAFOSM_H

#define NULO -1

typedef float tPeso;
typedef int tVertice;

typedef struct {
	tPeso **mat;
	tVertice numVertices;
} tGrafo;

typedef tVertice tApontador;

void inicializaGrafo(tGrafo *g, tVertice numVertices);
void insereAresta(tGrafo *g, tVertice v, tVertice u, tPeso peso);
int existeAresta(tGrafo *g, tVertice v, tVertice u);
void retiraAresta(tGrafo *g, tVertice v, tVertice u);
void liberaGrafo(tGrafo *g);
int existeAdj(tGrafo *g, tVertice v);
tApontador primeiroAdj(tGrafo *g, tVertice v);
tApontador proximoAdj(tGrafo *g, tVertice v, tApontador u);
void recuperaAdj(tGrafo *g, tVertice v, tApontador p, tVertice *u, tPeso *peso);
void imprimeGrafo(tGrafo *g);
#endif // GRAFOSM


