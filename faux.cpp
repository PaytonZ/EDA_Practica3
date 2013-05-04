
#include <string>
#include "pareja.h"
#include "faux.h"
#include "TADs/lista.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <cfloat>
#include <math.h>

using namespace std;

Solucion solucionDirecta(Lista<Punto> &puntos, int n);


Lista<Punto> merge(Lista<Punto> &l1, Lista<Punto> &l2);


Lista<Punto> filtraBanda(Lista<Punto> &l, double d, double x);


void recorreBanda(Lista<Punto> &l, Punto &p1, Punto &p2, double &d);


Solucion eligeMinimo(const Solucion &s1, const Solucion &s2,const Punto &p1, const Punto &p2, double d);


void generarListaDePuntos(Lista<Punto> &l,int n)
{
    Punto p1;
    for(int i=0; i < n ; i++)
    {
        p1.x=(rand() % 100000) / 100.0f;
        p1.y=(rand() % 100000) / 100.0f;
        l.ponDr(p1);
    }
}
void imprimeListadePuntos(Lista<Punto> &l)
{
    Lista<Punto>::Iterador it = l.principio();
    Punto p1;
    while (it  != l.final())
    {
        p1= it.elem();
        imprimeUnicoPunto(p1);
        it.avanza();
    }
}

void imprimeUnicoPunto(const Punto &p1)
{
      cout << "(" << p1.x << "," << p1.y << ")"<< endl;
}

Solucion parMasCercanoFuerzaBruta(Lista<Punto> &l)
{
    double distancia_minima= DBL_MAX;
    double p1aux, p2aux,aux;
    Punto p1,p2;
    Solucion s1;
    for(int i=0; i < l.numElems(); i++)
    {
        p1=l.elem(i);
        for(int j=i+1; j < l.numElems() ; j++)
        {
            p2=l.elem(j);
            p1aux= pow(p1.x-p2.x,2);
            p2aux= pow(p1.y-p2.y,2);
            aux= sqrt(p1aux+p2aux);
            if(aux!=distancia_minima )
            {
                distancia_minima=aux;
                s1.p1=p1;
                s1.p2=p2;
                s1.delta=aux;
            }
        }
    }
    return s1;
}

