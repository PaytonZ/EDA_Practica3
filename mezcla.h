#ifndef MEZCLA_H
#define MEZCLA_H


#include <string>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <cfloat>
#include <math.h>
#include "faux.h"


using namespace std;
// Definimos el tipo Comparador como un puntero a una funci�n
// que recibe dos puntos por referencia constante y devuelve
// un booleano
typedef bool (*Comparador) (const Punto &, const Punto &);
void mezclam(Punto array_puntos[], int a, int m, int b,Comparador menor);

// Funci�n que compara dos puntos por su abscisa. Su definici�n
// es compatible con el tipo Comparador
bool menorX(const Punto &p1, const Punto &p2)
{
    return p1.x < p2.x;
}
bool menorigualX(const Punto &p1, const Punto &p2)
{
    return p1.x <= p2.x;
}

bool menorY(const Punto &p1, const Punto &p2)
{
    return p1.y < p2.y;
}



// Funci�n de mezcla que recibe la funci�n que compara dos puntos
Lista<Punto> mezcla(Lista<Punto> &l1, Lista<Punto> &l2, Comparador menor)
{

    Lista<Punto> resultado;
    Lista<Punto>::Iterador it_l1 = l1.principio();
    Lista<Punto>::Iterador it_l2 = l2.principio();


    while((it_l1 != l1.final()) && (it_l2 != l2.final()))
    {
        if(menor(it_l1.elem(),it_l2.elem()))
        {
            resultado.ponDr(it_l1.elem());
            it_l1.avanza();

        }
        else
        {
            resultado.ponDr(it_l2.elem());
            it_l2.avanza();

        }
    }
    while (it_l1 != l1.final())
    {
        resultado.ponDr(it_l1.elem());
        it_l1.avanza();


    }
    while (it_l2 != l2.final())
    {
        resultado.ponDr(it_l2.elem());
        it_l2.avanza();

    }


    return resultado;
}



void mergeSort(Punto array_puntos[], int a, int b)
{
    int m;
    if (a < b)
    {
        m = (a + b) / 2;
        mergeSort(array_puntos, a, m);
        mergeSort(array_puntos, m + 1, b);
        mezclam(array_puntos, a, m, b,menorigualX);
    }
}


void OrdenacionMergeSort(Lista<Punto> &l)
{

    Punto array_puntos[l.numElems()];


    mergeSort(array_puntos, 0, l.numElems());
}



void deListaAarray(Lista<Punto> &l, Punto array_puntos[])
{

    Lista<Punto>::Iterador it = l.principio();
    Punto p1;
    int i;
    while (it  != l.final())
    {
        array_puntos[i]=it.elem();
        it.avanza();

    }

}

void mezclam(Punto array_puntos[], int a, int m, int b,Comparador menor)
{
    Punto *u = new Punto[b - a + 1];
    int i, j, k;
    for (k = a; k <= b; k++) u[k - a] = array_puntos[k];
    i = 0;
    j = m - a + 1;
    k = a;
    while ((i <= m - a) && (j <= b - a))
    {
        if (menor(u[i],u[j]))
        {
            array_puntos[k] = u[i];
            i = i + 1;
        }
        else
        {
            array_puntos[k] = u[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= m - a)
    {
        array_puntos[k] = u[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= b - a)
    {
        array_puntos[k] = u[j];
        j = j + 1;
        k = k + 1;
    }
    delete[] u;
}


// Esta funcion devuelve la lista entre los parametros a y b
Lista<Punto> partirLista(Lista<Punto> &original, int a , int b)
{
    Lista<Punto> lista_nueva;
    for(int i=a; i <=b; i ++)
    {
        lista_nueva.ponDr(original.elem(i));
    }
    assert(lista_nueva.numElems()>0);
    return lista_nueva;
}
#endif
