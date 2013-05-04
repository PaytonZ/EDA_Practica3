
#ifndef PAREJA_H
#define PAREJA_H
#include "TADs/lista.h"

typedef struct
{
    double x;
    double y;
} Punto;

typedef struct
{
    Punto p1;
    Punto p2;
} Pareja;

//typedef Pareja<double,double> Punto;
typedef struct
{
    Punto p1;
    Punto p2;
    double delta;
    Lista<Punto> lista;
} Solucion;

#endif
