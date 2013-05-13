
#include <string>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <cfloat>
#include <cmath>
#include "faux.h"
#include "mezcla.h"


using namespace std;
// Función que compara dos puntos por su abscisa. Su definición
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



// Función de mezcla que recibe la función que compara dos puntos
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
    deListaAarray(l,array_puntos);


    mergeSort(array_puntos, 0, l.numElems());

    deArrayALista(l,array_puntos);
}



void deListaAarray(Lista<Punto> &l, Punto array_puntos[])
{

    Lista<Punto>::Iterador it = l.principio();

    int i=0;
    while (it  != l.final())
    {
        array_puntos[i]=it.elem();
        it.avanza();
        i++;

    }

}


void deArrayALista(Lista<Punto> &l, Punto array_puntos[])
{
    int n= l.numElems();
    Lista<Punto> lista_de_puntos;
    for(int i=0; i<n; i++)
    {
        lista_de_puntos.ponDr(array_puntos[i]);
    }
    l=lista_de_puntos;

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
/*
Lista<Punto> partirListam(Lista<Punto> &original,int medio)
{
    Lista<Punto> I;
    Lista<Punto>::Iterador it= original.principio();

    for(int i=0;i<medio;i++)
    {
        it.avanza();
    }

    original=it;

    return I;
}*/
