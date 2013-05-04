#ifndef MEZCLA_H
#define MEZCLA_H


#include <string>
#include "pareja.h"
#include "faux.h"
//#include "TADs/lista.h"
#include "Lista.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cfloat>
#include <math.h>



using namespace std;
// Definimos el tipo Comparador como un puntero a una función
// que recibe dos puntos por referencia constante y devuelve
// un booleano
typedef bool (*Comparador) (const Punto &, const Punto &);


// Función que compara dos puntos por su abscisa. Su definición
// es compatible con el tipo Comparador
bool menorX(const Punto &p1, const Punto &p2)
{
    return p1.x < p2.x;
}
bool menorY(const Punto &p1, const Punto &p2)
{
    return p1.y < p2.y;
}

void mergeSort(Lista<Punto> &lista);
void mergeSort(Lista<Punto> &lista,int a, int b);
Lista<Punto> partirLista(Lista<Punto> &original, int a , int b);
Lista<Punto> mezcla(Lista<Punto> &l1, Lista<Punto> &l2, Comparador menor);

// Función de mezcla que recibe la función que compara dos puntos
Lista<Punto> mezcla(Lista<Punto> &l1, Lista<Punto> &l2, Comparador menor)
{

    Lista<Punto> resultado;
    Lista<Punto>::Iterador it_l1 = l1.principio();
    Lista<Punto>::Iterador it_l2 = l2.principio();


    while( (it_l1 != l1.final()) && (it_l2 != l2.final()) )
    {
        if( menor(it_l1.elem(), it_l2.elem()) )
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

void mergeSort(Lista<Punto> &lista)
{
    mergeSort(lista,0,lista.numElems()-1);
}

void mergeSort(Lista<Punto> &lista,int a, int b)
{

    int m;
    //cout << "a---" << a << "    b---" << b;
    if ( a < b )
    {
        m = (a+b) / 2;
        // cout << "     m---" << m << endl;
        Lista<Punto> lista1, lista2;
        
        lista1 = partirLista(lista, a, m);
        mergeSort( lista1, a, m );
        
        lista2 = partirLista(lista, m+1, b);
        mergeSort( lista2, m+1, b );
        
        lista = mezcla( lista1, lista2, menorY);
    }

}
// Esta funcion devuelve la lista entre los parametros a y b
Lista<Punto> partirLista(Lista<Punto> &original, int a , int b)
{
    cout << "Estoy creando una lista desde " << a << " hasta " << b << endl;
    Lista<Punto> lista_nueva;
        
    for(int i=a; i < b; i ++)
    {
        lista_nueva.ponDr(original.elem(i));
    }
    
    assert(lista_nueva.numElems()>0);
    return lista_nueva;
}

#endif
