#ifndef LABORATORIO_H_INCLUDED
#define LABORATORIO_H_INCLUDED

#include "muestra.h"
#include "colaLSE.h"
#include "colaCircularLSE.h"
#include "pila.h"

// m (Muestras), me (Muestras de Entrada), ma (Muestras Analizadas), mp (Muestras por Entregar)) 

// prototipos
void recepcionMuestras(Cola *me, ColaCircular *ma, Pila *mpe);
void procesadoAnalisis(Cola *me, ColaCircular *ma, Pila *mpe);
void reporteEntrega(Cola *me, ColaCircular *ma, Pila *mpe);

#endif // LABORATORIO_H_INCLUDED
