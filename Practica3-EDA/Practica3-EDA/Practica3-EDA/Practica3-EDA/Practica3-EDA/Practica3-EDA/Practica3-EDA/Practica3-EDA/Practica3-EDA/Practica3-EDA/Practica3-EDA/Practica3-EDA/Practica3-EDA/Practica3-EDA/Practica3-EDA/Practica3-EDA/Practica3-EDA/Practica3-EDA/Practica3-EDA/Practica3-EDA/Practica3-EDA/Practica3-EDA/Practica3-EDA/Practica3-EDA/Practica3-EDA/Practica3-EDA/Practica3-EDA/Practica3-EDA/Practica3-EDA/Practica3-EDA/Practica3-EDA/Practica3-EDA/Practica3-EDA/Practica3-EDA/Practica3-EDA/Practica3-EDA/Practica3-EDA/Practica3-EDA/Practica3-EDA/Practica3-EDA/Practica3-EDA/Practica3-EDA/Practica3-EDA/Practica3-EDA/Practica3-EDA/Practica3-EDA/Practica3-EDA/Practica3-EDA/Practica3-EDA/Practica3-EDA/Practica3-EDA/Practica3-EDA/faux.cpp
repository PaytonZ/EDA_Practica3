#include <string>
#include "pareja.h"
#include "faux.h"
#include "Lista.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cfloat>
#include <math.h>
#include "mezcla.h"

using namespace std;


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

bool iguales(Solucion &s,Solucion &s1)
{
    return  ((s1.p1.x==s.p1.x && s1.p1.y == s.p1.y) && (s1.p2.x==s.p2.x && s1.p2.y == s.p2.y)) ||
            ((s1.p1.x==s.p2.x && s1.p1.y == s.p2.y) && (s1.p2.x==s.p1.x && s1.p2.y == s.p1.y));
}

