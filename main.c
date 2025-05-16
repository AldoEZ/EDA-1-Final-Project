#include <stdio.h>
#include <stdlib.h>

#include "laboratorio.h"

int main() {
  // variables locales
  Cola *muestrasDeEntrada = crearCola();
  ColaCircular *muestrasAnalizadas = crearColaCircular();
  Pila *muestrasPorEntregar = crearPila(MAX);
  
  // codigo principal
  printf("\n\n\t\t===========================\n\t\tLaboratorio Quimico Forense\n\t\t===========================\n\n");
  system("pause");
  recepcionMuestras(muestrasDeEntrada, muestrasAnalizadas, muestrasPorEntregar);
  return 0;
}
