#include <string>
#include "pareja.h"
#include "faux.h"
#include "TADs/lista.h"
#include<stdlib.h>
#include<time.h>
#include <iostream>

using namespace std;

int main()
{
    //Inicialiacion de una semilla para generar numeros aleatorios
    srand(time(NULL));
    Lista<Punto> lista_de_puntos;
    Solucion s1;
    generarListaDePuntos(lista_de_puntos,10);
    imprimeListadePuntos(lista_de_puntos);
    s1 = parMasCercanoFuerzaBruta(lista_de_puntos);

    imprimeUnicoPunto(s1.p1);
    imprimeUnicoPunto(s1.p2);
    cout << s1.delta << endl;

    return 0;
}
