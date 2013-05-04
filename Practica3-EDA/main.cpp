#include <string>
#include "pareja.h"
#include "faux.h"
//#include "TADs/lista.h"
#include "Lista.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "mezcla.h"

using namespace std;

int main()
{
    //Inicialiacion de una semilla para generar numeros aleatorios
    srand(time(NULL));
    Lista<Punto> lista_de_puntos =  generarListaDePuntos(10);
    Solucion s1;
    imprimeListadePuntos(lista_de_puntos);
    s1 = parMasCercanoFuerzaBruta(lista_de_puntos);

    cout << "-----" << endl;
    imprimeUnicoPunto(s1.p1);
    imprimeUnicoPunto(s1.p2);
    cout << s1.delta << endl;

    mergeSort(lista_de_puntos);

    return 0;
}
