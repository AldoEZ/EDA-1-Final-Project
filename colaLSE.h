#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#include "muestra.h"

typedef struct nodoC{
  Muestra info;
  struct nodoC *sig; //APUNTADOR AL SIG NODO DE LA COLA
}NodoC;

typedef struct {
  NodoC *h,*t;
} Cola;

//FUNCIONES
void insertar(Cola *cola, Muestra dato);
Muestra borrar(Cola *cola);
//FUNCIONES AUXILIARES
Cola *crearCola();
int colaVacia(Cola cola);
void inicializarCola(Cola *cola);
void listarCola(Cola cola);
int numeroElementos(Cola cola);

#endif // COLADINAMICA_H_INCLUDED
