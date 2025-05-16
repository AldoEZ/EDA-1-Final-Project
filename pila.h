#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "muestra.h"

typedef struct {
  Muestra *arrPila;
  int max;
  int tope;
} Pila;

Pila *crearPila(int max);
int pilaLLena(Pila *pila);
void push(Muestra dato, Pila *pila);
void listarPila(Pila pila);
int pilaVacia(Pila *pila);
Muestra pop(Pila *pila);
void inicializarPila(Pila *pila);
void liberarMemoriaPila(Pila *pila);

#endif // PILA_H_INCLUDED
