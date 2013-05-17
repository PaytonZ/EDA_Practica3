#include <string>
#include "pareja.h"
#include "faux.h"
#include "TADs/Lista.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cfloat>
#include <math.h>
#include "mezcla.h"

using namespace std;





Lista<Punto> filtraBanda(Lista<Punto> &l, double d, double x)
{
    Lista<Punto> resultado;
    Lista<Punto>::Iterador it = l.principio();

    while (it != l.final())
    {
        // Valor absoluto de (punto.x - valor_de_x) al cuadrado tiene que ser menor que la distancia d
        // Antonio: la distancia no se calcula así
        if ((abs(it.elem().x - x)) <= d)
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
/*void recorreBanda(Lista<Punto> &l, Punto &p1, Punto &p2, double &d)
{
    double distancia_minima= DBL_MAX;
    double p1aux, p2aux,aux;
    Punto punto1,punto2;

    int max_iterable;

    if (l.numElems()<=1)
    {
        d=DBL_MAX;
    }
    else
    {
        int i=0;
        Lista<Punto>::Iterador it = l.principio();

        // Antonio: tienes que comparar cada punto con los 7 siguientes
        // Antonio: mejor con iteradores

        while(it != l.final())
        {
            punto1=it.elem();
            Lista<Punto>::Iterador it2 = it;
            i=0;
            while(it2 != l.final() && i < 7)
            {

                punto2=it2.elem();
                p1aux= pow(punto1.x-punto2.x,2);
                p2aux= pow(punto1.y-punto2.y,2);
                aux= sqrt(p1aux+p2aux);
                if(aux<distancia_minima )
                {
                    distancia_minima=aux;
                    p1=punto1;
                    p2=punto2;
                    d=aux;

                }
                i++;
                it2.avanza();
            }
            it.avanza();
        }
    }

}*/

void recorreBanda(Lista<Punto> &l, Punto &p1, Punto &p2, double &d)
{
    double distancia_minima= DBL_MAX;
    double p1aux, p2aux,aux;
    Punto punto1,punto2;



    if (l.numElems()<=1)
    {
        d=DBL_MAX;
    }
    else
    {

        // Antonio: tienes que comparar cada punto con los 7 siguientes
        // Antonio: mejor con iteradores
        for(int i=0; i< l.numElems(); i++)
        {
            punto1=l.elem(i);
            for(int j=i+1; j < i+7 && j < l.numElems(); j++)
            {
                assert(j<l.numElems());
                punto2=l.elem(j);
                p1aux= pow(punto1.x-punto2.x,2);
                p2aux= pow(punto1.y-punto2.y,2);
                aux= sqrt(p1aux+p2aux);
                if(aux<distancia_minima )
                {
                    distancia_minima=aux;
                    p1=punto1;
                    p2=punto2;
                    d=aux;

                }
            }
        }

    }
}


// Dadas tres soluciones , cada una consistente en un par de puntos y su
// distancia , devuelve el par mas cercano de los tres y su distancia .
Solucion eligeMinimo(const Solucion &s1, const Solucion &s2,const Punto &p1, const Punto &p2, double d)
{
    Solucion resultado;
    //s1 es el mas peque�o
    if (s1.delta < s2.delta && s1.delta < d)
    {
        resultado.p1=s1.p1;
        resultado.p2=s1.p2;
        resultado.delta=s1.delta;
    }
    //s2 es el mas peque�o
    else if( s2.delta < s1.delta && s2.delta < d)
    {
        resultado.p1=s2.p1;
        resultado.p2=s2.p2;
        resultado.delta=s2.delta;
    }
    else // La solucion por parametros es la mas peque�a
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

// Antonio : la solución directa O(n^2) no tiene que devolver una lista de puntos
// ordenados por la y (no es necesario)
Solucion solucionDirecta(Lista<Punto> &l, int n)
{
    double distancia_minima= DBL_MAX;
    double p1aux, p2aux,aux;
    Punto p1,p2;
    Solucion s1;

    // Antonio: cambiarlo a iteradores
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
    s1.lista=l;
    return s1;
}


// Antonio: pasar puntos por referencia
Solucion parMasCercano(Lista<Punto> &puntos, int n)
{
    Solucion sol;
    Punto p1;
    Punto p2;
    double dist;
    if (n <= 3)   // Casos base
    {
        sol = solucionDirecta(puntos,n);
        OrdenacionMergeSort(sol.lista,menorY);

        // Antonio: ordenar los n puntos por la y y devolverlo como parte de la solución
    }
    else /// n >= 4    // Dividimos la nube en dos

    {
        int m1 = n / 2;
        int m2 = n - m1;

        // Antonio: devolver las dos listas con una única llamada
        Lista<Punto> I = partirLista(puntos,0,m1-1);
        Lista<Punto> D = partirLista(puntos,m1,n-1);
        // Resolvemos recursivamente las dos nubes

        Solucion sol1 = parMasCercano(I,m1);
        Solucion sol2 = parMasCercano(D,m2);

        // Calculamos la coordenada x de la linea divisoria
        double xl = (I.primero().x + D.primero().x) / 2;

        // Ordenamos por la coordenada y la nube de puntos
        Lista<Punto> lista = mezcla(sol1.lista,sol2.lista,menorY);

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

