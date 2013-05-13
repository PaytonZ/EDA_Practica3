#include <string>

#include "pareja.h"
#include "faux.h"
#include "TADs/Lista.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "mezcla.h"


#define MAX_PUNTOS 100
using namespace std;

Solucion inicioAlgoritmoDirecto(Lista<Punto> &lista_de_puntos);
Solucion inicioAlgoritmoDYV(Lista<Punto> &lista_de_puntos);
bool iguales(Solucion &s,Solucion &s1)
{
    return s1.delta == s.delta;
}

int main()
{
    //Inicialiacion de una semilla para generar numeros aleatorios
    srand(time(NULL));
    int casos_correctos=0;
    int casos_totales=10;

    for(int i=0; i < casos_totales ; i++)
    {

    cout << "PRUEBA NUM " << i << endl;

    Lista<Punto> lista_de_puntos =  generarListaDePuntos(MAX_PUNTOS);

    Solucion s1,s2;

    s1=inicioAlgoritmoDirecto(lista_de_puntos);


    OrdenacionMergeSort(lista_de_puntos);

    s2=inicioAlgoritmoDYV(lista_de_puntos);

    cout << "CORRECTO.... " << iguales(s1,s2) << endl;

    if(iguales(s1,s2)) casos_correctos++;

    }

    cout << "TEST : " << casos_correctos *100/casos_totales  << "%" << endl;
    return 0;
}

Solucion inicioAlgoritmoDirecto(Lista<Punto> &lista_de_puntos)
{
    Solucion s1;

    clock_t tiempoInicio1;
    clock_t tiempoFinal1;
    float tiempo;

    tiempoInicio1=clock();

    s1 = solucionDirecta(lista_de_puntos,MAX_PUNTOS);

    tiempoFinal1=clock();

   /* cout << "-----DIRECTA" << endl;
    imprimeUnicoPunto(s1.p1);
    imprimeUnicoPunto(s1.p2);
    cout << s1.delta << endl;

    tiempo = ((float) (tiempoFinal1 - tiempoInicio1)) / CLOCKS_PER_SEC;
    cout << "El algoritmo Directo con " << MAX_PUNTOS << " puntos tardo " <<  tiempo << " segundos" << endl;
    */
    return s1;
}

Solucion inicioAlgoritmoDYV(Lista<Punto> &lista_de_puntos)
{

    clock_t tiempoInicio1;
    clock_t tiempoFinal1;
    float tiempo;

    tiempoInicio1=clock();
    Solucion s2 = parMasCercano(lista_de_puntos,MAX_PUNTOS);
    tiempoFinal1=clock();

    /*cout << "-----DYV" << endl;
    imprimeUnicoPunto(s2.p1);
    imprimeUnicoPunto(s2.p2);
    cout << s2.delta << endl;
    tiempo = ((float) (tiempoFinal1 - tiempoInicio1)) / CLOCKS_PER_SEC;
    cout << "El algoritmo DYV con " << MAX_PUNTOS << " puntos tardo " <<  tiempo << " segundos" << endl;*/

    return s2;
}


