#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "muestra.h"

// variable global para llenar las muestras
char nombresMuestras[20][MAX_TEXTO] = {"Sangre", "Orina", "Tejidos", "Saliva", "Pelo","Huellas dactilares", "Fragmentos de vidrio", "Residuos de Polvora", 
                                      "Tintas y papel", "Fibras textiles", "Pinturas y pigmentos", "Tierra y suciedad", "Cenizas y residuos de incendios", 
                                      "Fragmentos de explosivos", "Armas de fuego y municiones", "Vidrios y ventanas", "Muestras de suelo y agua", 
                                      "Muestras de alimentos y bebidas", "Objetos personales", "Productos quimicos y sustancias sinteticas"};
char nombresDepartamentos[10][MAX_TEXTO] = {"Toxicologia Forense", " Identificacion de Drogas", "Analisis de Fluidos Corporales", "Quimica de Explosivos", 
                                            "Analisis de Incendios", "Serologia Forense", "Balistica Forense", "Quimica de Documentos", 
                                            "Analisis de Pinturas y Fibras", "Quimica Forense Ambiental"};

Muestra *crearMuestra() {
  Muestra *nuevaMuestra = (Muestra *) calloc(1, sizeof(Muestra));
  if (nuevaMuestra == NULL) {
    printf("\nError: No se pudo asignar memoria para el arreglo de libros.\n");
    exit(0);
  }
  nuevaMuestra->nombre = (char *) malloc(MAX_TEXTO * sizeof(char));
  nuevaMuestra->nombreDep = (char *) malloc(MAX_TEXTO * sizeof(char));
  return nuevaMuestra;
}

void registrarMuestra(Muestra *unaMuestra) {
  srand(time(NULL));
  unaMuestra->clave = rand()%1000;
  strcpy(unaMuestra->nombre, nombresMuestras[rand()%20]);
  strcpy(unaMuestra->nombreDep, nombresDepartamentos[rand()%10]);
}

void listarMuestra(Muestra unaMuestra) {
  printf("\nClave: %d\n", unaMuestra.clave);
  printf("Nombre: %s\n", unaMuestra.nombre);
  printf("Nombre del departamento: %s\n", unaMuestra.nombreDep);
}
