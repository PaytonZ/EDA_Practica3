#include <string>
#include "pareja.h"
#include "faux.h"
#include "TADs/lista.h"
#include<stdlib.h>
#include<time.h>


int main()

{
    //Inicialiacion de una semilla para generar numeros aleatorios
    srand(time(NULL));
    Lista<Punto> lista_de_puntos;
    generarListaDePuntos(lista_de_puntos,10);

    return 0;
}
