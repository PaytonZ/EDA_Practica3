#ifndef MEZCLA_H
#define MEZCLA_H


#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cfloat>
#include <cmath>
#include "faux.h"


// Definimos el tipo Comparador como un puntero a una función
// que recibe dos puntos por referencia constante y devuelve
// un booleano
typedef bool (*Comparador) (const Punto &, const Punto &);
void mezclam(Punto array_puntos[], int a, int m, int b,Comparador menor);

// Función que compara dos puntos por su abscisa. Su definición
// es compatible con el tipo Comparador
bool menorX(const Punto &p1, const Punto &p2);


bool menorigualX(const Punto &p1, const Punto &p2);

bool menorY(const Punto &p1, const Punto &p2);


// Función de mezcla que recibe la función que compara dos puntos
Lista<Punto> mezcla(Lista<Punto> &l1, Lista<Punto> &l2, Comparador menor);

void mergeSort(Punto array_puntos[], int a, int b);


void OrdenacionMergeSort(Lista<Punto> &l,Comparador menor);


// Transforma un punto a una lista de arryays.
void deListaAarray(Lista<Punto> &l, Punto array_puntos[]);

void deArrayALista(Lista<Punto> &l, Punto array_puntos[]);

void mezclam(Punto array_puntos[], int a, int m, int b,Comparador menor);

void partirListam(Lista<Punto> &original, int medio , Lista<Punto> &izquierda , Lista<Punto> &derecha);


Lista<Punto> partirListam(Lista<Punto> &original);


#endif
