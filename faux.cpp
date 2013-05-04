
#include <string>
#include "pareja.h"
#include "faux.h"
#include "TADs/lista.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <cfloat>
#include <math.h>
#include "mezcla.h"

using namespace std;

Solucion solucionDirecta(Lista<Punto> &puntos, int n);


Lista<Punto> merge(Lista<Punto> &l1, Lista<Punto> &l2);


Lista<Punto> filtraBanda(Lista<Punto> &l, double d, double x)
{
    Lista<Punto> resultado;
    Lista<Punto>::Iterador it = l.principio();

    while (it  != l.final())
    {
        // Valor absoluto de (punto.x - valor_de_x) al cuadrado tiene que ser menor que la distancia d
       if (abs(pow(it.elem().x-x,2)) <= d)
       {
           resultado.ponDr(it.elem());
       }
       it.avanza();
    }
    return resultado;

}
// Recorre una lista l de puntos , comparando cada uno con los 7
// siguientes si los hubiera . Devuelve el par de puntos con menor
// distancia , y dicha distancia.Si l tiene un punto o ninguno ,
// devuelve una distancia +infinito.
void recorreBanda(Lista<Punto> &l, Punto &p1, Punto &p2, double &d)
{
   double distancia_minima= DBL_MAX;
    double p1aux, p2aux,aux;
    Punto punto1,punto2;
    Solucion s1;
    for(int i=0; i < 7; i++)
    {
        punto1=l.elem(i);
        for(int j=i+1; j < i+7; j++)
        {
            punto2=l.elem(j);
            p1aux= pow(punto1.x-punto2.x,2);
            p2aux= pow(punto1.y-punto2.y,2);
            aux= sqrt(p1aux+p2aux);
            if(aux<distancia_minima )
            {
                distancia_minima=aux;
                s1.p1=punto1;
                s1.p2=punto2;
                s1.delta=aux;
            }
        }
    }
    p1=s1.p1;
    p2=s1.p2;
    d=s1.delta;
}
// Dadas tres soluciones , cada una consistente en un par de puntos y su
// distancia , devuelve el par mas cercano de los tres y su distancia .
Solucion eligeMinimo(const Solucion &s1, const Solucion &s2,const Punto &p1, const Punto &p2, double d)
{
    Solucion resultado;
    //s1 es el mas pequeño
    if (s1.delta < s2.delta && s1.delta < d)
    {
        resultado.p1=s1.p1;
        resultado.p2=s1.p2;
        resultado.delta=s1.delta;
    }
    //s2 es el mas pequeño
    else if( s2.delta < s1.delta && s2.delta < d)
    {
        resultado.p1=s2.p1;
        resultado.p2=s2.p2;
        resultado.delta=s2.delta;
    }
    else // La solucion por parametros es la mas pequeña
    {
        resultado.p1=p1;
        resultado.p2=p2;
        resultado.delta=d;
    }

    return resultado;
}


Lista<Punto> generarListaDePuntos(int n)
{
    Lista<Punto> resultado;
    Punto p1;
    for(int i=0; i < n ; i++)
    {
        p1.x=(rand() % 100000) / 100.0f;
        p1.y=(rand() % 100000) / 100.0f;
        resultado.ponDr(p1);
    }
    return resultado;
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

Solucion solucionDirecta(Lista<Punto> &l, int n)
{
    double distancia_minima= DBL_MAX;
    double p1aux, p2aux,aux;
    Punto p1,p2;
    Solucion s1;
    for(int i=0; i < n; i++)
    {
        p1=l.elem(i);
        for(int j=i+1; j < n ; j++)
        {
            p2=l.elem(j);
            p1aux= pow(p1.x-p2.x,2);
            p2aux= pow(p1.y-p2.y,2);
            aux= sqrt(p1aux+p2aux);
            if(aux<distancia_minima )
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

Solucion parMasCercano(Lista<Punto> puntos, int n)
{
    Solucion sol;
    Punto p1;
    Punto p2;
    double dist;
    if (n <= 3)   // Casos base
    {
        sol = solucionDirecta(puntos,n);
    }
    else /// n >= 4    // Dividimos la nube en dos

       {
            int m1 = n / 2;
            int m2 = n - m1;

            Lista<Punto> I = partirLista(puntos,0,m1);
            Lista<Punto> D = partirLista(puntos,m1+1,n-1);
            // Resolvemos recursivamente las dos nubes



            Solucion sol1 = parMasCercano(I,m1);
            Solucion sol2 = parMasCercano(D,m2);
                // Calculamos la coordenada x de la linea divisoria
            double xl = (I.primero().x + D.primero().x) / 2;
            // Ordenamos por la coordenada y la nube de puntos
            Lista<Punto> lista = mezcla(sol1.lista,sol2.lista,menorX);
            double delta = min(sol1.delta,sol2.delta);
            // Filtramos los puntos de la banda y la recorremos
            Lista<Punto> B = filtraBanda(lista,delta,xl);
            recorreBanda(B,p1,p2,dist);
            // Elegimos la mejor solucion de las tres
            sol = eligeMinimo(sol1,sol2,p1,p2,dist);
            sol.lista = lista;
        }


        return sol;

}

