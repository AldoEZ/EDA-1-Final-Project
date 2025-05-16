#ifndef COLACIRCULARLSE_H_INCLUDED
#define COLACIRCULARLSE_H_INCLUDED

#include "muestra.h"

typedef struct nodoCC NodoCC;
struct nodoCC{
  Muestra info;
  NodoCC *sig;
};

typedef struct{
  NodoCC *h, *t;
} ColaCircular;

ColaCircular *crearColaCircular();
int vacia(ColaCircular colaCir);
void Insertar(ColaCircular *colaCir, Muestra dato);
void Listar(ColaCircular colaCir);
Muestra Borrar (ColaCircular *colaCir);
void inicializarColaCircular(ColaCircular *cc);
int elemtos(ColaCircular cc);


#endif // COLACIRCULARLSE_H_INCLUDED