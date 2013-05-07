#include <string>
#include "mezcla.h"
#include "pareja.h"
#include "faux.h"
#include "TADs/lista.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


#define MAX_PUNTOS 5
using namespace std;

int main()
{
    //Inicialiacion de una semilla para generar numeros aleatorios
    srand(time(NULL));
    Lista<Punto> lista_de_puntos =  generarListaDePuntos(MAX_PUNTOS);
    Solucion s1;
    imprimeListadePuntos(lista_de_puntos);
    s1 = solucionDirecta(lista_de_puntos,MAX_PUNTOS);

    cout << "-----" << endl;
    imprimeUnicoPunto(s1.p1);
    imprimeUnicoPunto(s1.p2);
    cout << s1.delta << endl;


    OrdenacionMergeSort(lista_de_puntos);
    Solucion s2 = parMasCercano(lista_de_puntos,MAX_PUNTOS);
    cout << "-----" << endl;
    imprimeUnicoPunto(s2.p1);
    imprimeUnicoPunto(s2.p2);
    cout << s2.delta << endl;

    return 0;
}
