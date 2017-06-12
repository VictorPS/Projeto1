#ifndef PRIM_H
#define PRIM_H

#include "heap.h"
#include "grafosM.h"

void inicializaPrim(tNode **prim, int v);

void primAlgorithm(tGrafo *g, tNode **prim);

void primClasses(int **classes, tNode **prim, int total, int clusters);

int compare (const void *a, const void *b);

#endif
