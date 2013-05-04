
#include "faux.h"
#include "TADs/lista.h"
#include<stdlib.h>
#include<time.h>

Solucion solucionDirecta(Lista<Punto> &puntos, int n);


Lista<Punto> merge(Lista<Punto> &l1, Lista<Punto> &l2);


Lista<Punto> filtraBanda(Lista<Punto> &l, double d, double x);


void recorreBanda(Lista<Punto> &l, Punto &p1, Punto &p2, double &d);


Solucion eligeMinimo(const Solucion &s1, const Solucion &s2,const Punto &p1, const Punto &p2, double d);


void generarListaDePuntos(Lista<Puntos> &l,int n)
{
    Punto p1;
    for(int i=0; i < n ; i++)
    {
        p1.x=(rand() % 100000) / 100.0d;
        p1.y=(rand() % 100000) / 100.0d;
        l.pondr(p1);
    }
}
