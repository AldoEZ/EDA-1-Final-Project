#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila *crearPila(int n){
  Pila *nuevaPila;
  //1. crear la pila y el arreglo de la pila
  nuevaPila = (Pila *)malloc(1 *sizeof(Pila)); //CREA LA ESTRUCTURA PILA CON TODOS SUS ELEMENTOS
  if(nuevaPila == NULL){
    printf("Error: No hay espacio...");
    exit(0);
  }
  nuevaPila->arrPila = (Muestra *)calloc(n , sizeof(Muestra));//CREANDO EL ARREGLO DE LA PILA
  if(nuevaPila->arrPila == NULL){
    printf("Error: No hay espacio...");
    exit(0);
  }
  //2. INICIALIZA VALORES
  nuevaPila->tope =-1;
  nuevaPila->max = n;
  return nuevaPila;
}

int pilaLLena(Pila *pila){
  return (pila->tope >= pila->max-1);
}

void push(Muestra dato,Pila *pila){
  pila->tope++;
  pila->arrPila[pila->tope] = dato;
}

void listarPila(Pila pila){
  printf("\n=====================\nMUESTRAS POR ENTREGAR\n=====================\n");
  for (int i = pila.tope; i >= 0; i--)
    listarMuestra(pila.arrPila[i]);
}

int pilaVacia(Pila *pila){
  return (pila->tope == -1);
}

Muestra pop(Pila *pila){
  Muestra aux = pila->arrPila[pila->tope];
  pila->tope--;
  return aux;
}

void inicializarPila(Pila *pila){
  pila->tope = -1;
}

void liberarMemoriaPila(Pila *pila){
  free(pila->arrPila);
  free(pila);
  pila = NULL;
}
