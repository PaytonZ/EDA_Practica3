#ifndef FAUX_H
#define FAUX_H

#include "pareja.h"



//Rellena una lista con N puntos aleatorios
Lista<Punto> generarListaDePuntos(int n);

//Imprime una lista de puntos de forma adecuada

void imprimeListadePuntos(Lista<Punto> &l);


//Funcion que muestra un punto de forma adecuada  -- Auxiliar
void imprimeUnicoPunto(const Punto &p1);

bool iguales(Solucion &s,Solucion &s1);

#endif
