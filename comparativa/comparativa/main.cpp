//
//  main.cpp
//  comparativa
//
//  Created by Dani on 28/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#include <iostream>
#include "Lista.h"
#include "pareja.h"
#include "faux.h"
#include "dyv.h"
#include "mezcla.h"

using namespace std;

void compararDVpuroConDVcompuesto(float tiempoPuro, float tiempoCompuesto, int numeroPuntos, int umbral);
void calculoTiempo(int puntos, int umbral);

int main(int argc, const char * argv[]) {

    int puntos = 2;
    int umbral = 10;
    
    while ( puntos <= 20000) {
        
        calculoTiempo(puntos, 1);
        
        // Decremento el nº de puntos.
        puntos *= 2;
    }
    
    puntos = 2;
    
    while ( puntos <= 20000) {
        
        calculoTiempo(puntos, umbral);
        
        // Decremento el nº de puntos.
        puntos *= 2;
        umbral += 10;
    }
    
    return 0;
}

void compararDVpuroConDVcompuesto(float tiempoPuro, float tiempoCompuesto, int numeroPuntos, int umbral) {
    
    cout << "ALGORITMO PURO: " << tiempoPuro << " con número de puntos: " << numeroPuntos << endl;
    
    cout << "ALGORITMO COMPUESTO: " << tiempoCompuesto << " con número de puntos: " << numeroPuntos << " y umbral: " << umbral << endl << endl;
}

void calculoTiempo(int puntos, int umbral) {
    
    clock_t tiempoInicioDVpuro;
    clock_t tiempoFinalDVpuro;
    float tiempoDVpuro;
    
    clock_t tiempoInicioDVcompuesto;
    clock_t tiempoFinalDVcompuesto;
    float tiempoDVcompuesto;
    
    Lista<Punto> lista_de_puntos = generarListaDePuntos(puntos);
    
    tiempoInicioDVpuro = clock();
    
    OrdenacionMergeSort(lista_de_puntos, menorigualX);
    parMasCercano(lista_de_puntos, puntos, 1);
    
    tiempoFinalDVpuro = clock();
    
    tiempoDVpuro = ((float) (tiempoFinalDVpuro - tiempoInicioDVpuro)) / CLOCKS_PER_SEC;
    
    //lista_de_puntos = generarListaDePuntos(puntos);
    
    tiempoInicioDVcompuesto = clock();
    
    OrdenacionMergeSort(lista_de_puntos, menorigualX);
    parMasCercano(lista_de_puntos, puntos, umbral);
    
    tiempoFinalDVcompuesto = clock();
    
    tiempoDVcompuesto = ((float) (tiempoFinalDVcompuesto - tiempoInicioDVcompuesto)) / CLOCKS_PER_SEC;
    
    compararDVpuroConDVcompuesto(tiempoDVpuro, tiempoDVcompuesto, puntos, umbral);
}