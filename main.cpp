#include <string>
#include "pareja.h"
#include "faux.h"
#include "TADs/lista.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>

#define MAX_PUNTOS 10
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

    parMasCercano(lista_de_puntos,MAX_PUNTOS);

    return 0;
}
