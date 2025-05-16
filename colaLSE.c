#include <stdio.h>
#include <stdlib.h>
#include "colaLSE.h"

Cola *crearCola(){
  Cola *nuevaCola;
  //CREACIoN DINaMICA DE LA ESTRUCTURA COLA
  nuevaCola = (Cola *)malloc(1*sizeof(Cola));
  if (nuevaCola == NULL){
    printf("Error: Espacio insuficiente...");
    exit(0);
  }
  //INICIALIZANDO h y t
  nuevaCola->h = NULL;
  nuevaCola->t = NULL;
  return  nuevaCola;
}

void insertar(Cola *cola, Muestra dato){
  NodoC *nuevoNodo;
  //CREA EL NODO
  nuevoNodo = (NodoC *)malloc(sizeof(NodoC));
  if (nuevoNodo == NULL){
    printf("Error: memoria insuficiente...");
    exit(0);
  }
  //1.ASIGNA VALORES AL NODO
  nuevoNodo->info  = dato;
  nuevoNodo->sig  = NULL;
  //2.INSERTA EL NODO EN LA COLA
  if (colaVacia(*cola))
    cola->h = cola->t = nuevoNodo;
  else {
    cola->t->sig = nuevoNodo;
    cola->t = nuevoNodo;
  }
}

void listarCola(Cola cola){
  NodoC *q;
  printf("\n");
  printf("\n===================\nMUESTRAS DE ENTRADA\n===================\n");
  if (colaVacia(cola))
    printf("\nNo hay datos en la fila...\n");
  else{
    for(q = cola.h; q != NULL; q = q->sig)
      listarMuestra(q->info);
  }
  printf("\n");
}

int colaVacia(Cola cola){
  return cola.h == NULL;
}

Muestra borrar(Cola *cola){
  Muestra dato;
  NodoC *q = cola->h;
  //BORRA EL DATO
  if (!colaVacia(*cola)){
    if(cola->h == cola->t)
      cola->h = cola->t = NULL;
    else
      cola->h =  cola->h->sig;
    dato = q->info; // EXTRAE LA INFORMACI�N
    q->sig = NULL; // DESENLACE DE LA VARIABLE Q
    free(q); // LIBERA LA MEMORIA
  }
  else
    printf("\nNo hay datos registrados...");
  return dato;
}

void inicializarCola(Cola *cola){
  NodoC *q = cola->h;
  if (!colaVacia(*cola)){
    //LIBERA MEMORIA
    while (q != NULL){
      cola->h =  cola->h->sig;
      q->sig = NULL;
      free(q); //LIBERA LA MEMORIA
      q = cola->h;
    }
    //INICIALIZA APUNTADORES COLA
    cola->h = cola->t = NULL;
  }
}

int numeroElementos(Cola cola){
  int num = 0;
  NodoC *q;
  if (!colaVacia(cola)){
    for(q = cola.h; q != NULL; q = q->sig)
      num++;
  }
  return num;
}
