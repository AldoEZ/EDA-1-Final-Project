#include <stdio.h>
#include <stdlib.h>
#include "colaCircularLSE.h"

ColaCircular *crearColaCircular(){
  ColaCircular *cc;
  cc = (ColaCircular *)malloc(sizeof(ColaCircular));
  if(cc == NULL){
    printf("\nError al crear la cola...\n");
    exit(0);
  }
  cc->h = NULL;
  cc->t = NULL;
  return cc;
}

int vacia(ColaCircular colaCir){
  return colaCir.h == NULL;
}

void Insertar(ColaCircular *colaCir, Muestra dato){
  //CREAR NODO
  NodoCC *nuevo = (NodoCC *)malloc(sizeof(NodoCC));
  if (nuevo == NULL){
    printf("\nError al crear el nodo...");
    exit(0);
  }
  nuevo->info = dato;
  nuevo->sig = colaCir->h; //LIGADURA CIRCULAR

  //INSERTAR NODO
  if(vacia(*colaCir)){
    colaCir->h = nuevo;
    colaCir->t = nuevo;
    colaCir->t->sig = colaCir->h; //LIGADURA CIRCULAR
    return;
  }
  colaCir->t->sig = nuevo;
  colaCir->t = nuevo;
}

void Listar(ColaCircular colaCir){
  NodoCC *q;
  q = colaCir.h;
  printf("\n");
  printf("\n===================\nMUESTRAS ANALIZADAS\n===================\n");
  if (q != NULL) {
    do {
      listarMuestra(q->info);
      q = q->sig;
    }while(q != colaCir.h);
    printf("\n");
  }
  else
    printf("\nNo hay datos...\n");
}

Muestra Borrar(ColaCircular *colaCir){
  Muestra dato;
  NodoCC *q = colaCir->h;
  if(! vacia(*colaCir)) {
    dato = q->info;
    if (colaCir->h == colaCir->t)
      colaCir->h = colaCir->t = NULL;
    else {
      colaCir->h = colaCir->h->sig;
      colaCir->t->sig = colaCir->h;
    }
    q->sig = NULL;
    free(q);
  }
  else
    printf("\nNo hay datos registrados...\n");
  return dato;
}

void inicializarColaCircular(ColaCircular *cc){
  NodoCC *q = cc->h;
  if (!vacia(*cc)){
    //LIBERA MEMORIA
    while (q != cc->t->sig){
      cc->h =  cc->h->sig;
      q->sig = NULL;
      free(q); //LIBERA LA MEMORIA
      q = cc->h;
    }
    //INICIALIZA APUNTADORES COLA
    cc->h = cc->t = NULL;
  }
}

int elemtos(ColaCircular cc){
  NodoCC *q = cc.h;
  int n = 0;
  printf("\n");
  if (q != NULL) {
    do {
      n++;
      q = q->sig;
    }while(q != cc.h);
  }
  return n;
}
