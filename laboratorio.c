#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "laboratorio.h"

void recepcionMuestras(Cola *me, ColaCircular *ma, Pila *mpe) {
  int n = rand()%100;
  system("cls");
  printf("\n\n///////////////////////////\n// Recepcion de Muestras //\n///////////////////////////\n\n");
  if(n <= 50) {
    for(int i = 0; i < 5; i++) {
      Muestra *nuevaMuestra = crearMuestra();
      registrarMuestra(nuevaMuestra);
      listarMuestra(*nuevaMuestra);
      insertar(me, *nuevaMuestra);
      system("pause");
    }
    system("cls");
    listarCola(*me);
    system("pause");
  } else {
    printf("\nNo se han registrado muestras.\n");
    system("pause");
  }
  system("cls");
  return procesadoAnalisis(me, ma, mpe);
}

void procesadoAnalisis(Cola *me, ColaCircular *ma, Pila *mpe) {
  Muestra unaMuestra, muestrasAnalizadas;
  int e = numeroElementos(*me), n;
  n = rand()%e;
  printf("\n\n//////////////////////////\n// PROCESADO Y ANALISIS //\n//////////////////////////\n\n");
  
  printf("\nEl numero de muestras que se analizaran es %i\n\n", n);
  system("pause");
  
  for(int i = 0; i < n; i++) {
    listarCola(*me);
    unaMuestra = borrar(me);
    system("pause");
    system("cls");
    
    printf("\nProcesando la muestra con clave %i\n", unaMuestra.clave);
    Insertar(ma, unaMuestra);
    
    Listar(*ma);
    system("pause");
    system("cls");
  }
  for(int j = 0; j < n; j++) {
    muestrasAnalizadas = Borrar(ma);
    push(muestrasAnalizadas, mpe);
  }
  system("cls");
  listarPila(*mpe);
  system("pause");
  system("cls");
  return reporteEntrega(me, ma, mpe);
}

void reporteEntrega(Cola *me, ColaCircular *ma, Pila *mpe) {
  Muestra otraMuestra;
  int e = mpe->tope, n;
  n = rand()%e;
  printf("\n\n///////////////////////\n// REPORTE Y ENTREGA //\n///////////////////////\n\n");
  
  printf("\nEl numero de muestras a entregar es %i\n", n);
  system("pause");
  
  for(int i = 0; i < n; i++) {
    listarPila(*mpe);
    otraMuestra = pop(mpe);
    system("pause");
    system("cls");
    
    printf("\nLa muestra %s de clave %i se devolvio al departamento %s\n", 
      otraMuestra.nombre, otraMuestra.clave, otraMuestra.nombreDep);
    system("pause");
    system("cls");
  }
  system("cls");
  listarCola(*me);
  Listar(*ma);
  listarPila(*mpe);
  system("pause");
  system("cls");
  return recepcionMuestras(me, ma, mpe);
}
