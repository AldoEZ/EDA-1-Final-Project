#ifndef MUESTRA_H_INCLUDED
#define MUESTRA_H_INCLUDED

#define MAX 100000
#define MAX_TEXTO 50

// estructuras
typedef struct{
  int clave;
  char *nombre;
  char *nombreDep;
} Muestra;

// prototipos
Muestra *crearMuestra();
void registrarMuestra(Muestra *unaMuestra);
void listarMuestra(Muestra unaMuestra);

#endif // MUESTRA_H_INCLUDED
