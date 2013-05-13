#ifndef FAUX_H
#define FAUX_H

#include "pareja.h"

// Dada una lista con dos o tres puntos , devuelve los dos puntos mas
// cercanos , su distancia y una lista con los puntos ordenados
// crecientemente por su coordenada y
Solucion solucionDirecta(Lista<Punto> &puntos, int n);

// Dadas dos listas de puntos ordenadas por la coordenada y ,devuelve
// otra lista con su mezcla ordenada tambien por la coordenada y
Lista<Punto> merge(Lista<Punto> &l1, Lista<Punto> &l2);

// Dada una lista l de puntos , una distancia d y una abcisa x ,
// devuelve la lista de los puntos de l cuya abcisa diste a lo
// sumo d de x en valor absoluto
Lista<Punto> filtraBanda(Lista<Punto> &l, double d, double x);

// Recorre una lista l de puntos , comparando cada uno con los 7
// siguientes si los hubiera . Devuelve el par de puntos con menor
// distancia , y dicha distancia.Si l tiene un punto o ninguno ,
// devuelve una distancia +infinito.
void recorreBanda(Lista<Punto> &l, Punto &p1, Punto &p2, double &d);

// Dadas tres soluciones , cada una consistente en un par de puntos y su
// distancia , devuelve el par mas cercano de los tres y su distancia .
Solucion eligeMinimo(const Solucion &s1, const Solucion &s2,const Punto &p1, const Punto &p2, double d);

//Rellena una lista con N puntos aleatorios
Lista<Punto> generarListaDePuntos(int n);

//Imprime una lista de puntos de forma adecuada

void imprimeListadePuntos(Lista<Punto> &l);

//Solucion 'fuerzabruta' del algoritmo de la nube de puntos

Solucion parMasCercanoFuerzaBruta(Lista<Punto> &l);

//Funcion que muestra un punto de forma adecuada  -- Auxiliar
void imprimeUnicoPunto(const Punto &p1);

Solucion parMasCercano(Lista<Punto> puntos, int n);
#endif
