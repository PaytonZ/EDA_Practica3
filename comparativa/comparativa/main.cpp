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

int main(int argc, const char * argv[]) {

    int puntos = 10;
    int umbral = 15;
    
    while ( puntos <= 20000) {
        
        clock_t tiempoInicioDVpuro;
        clock_t tiempoFinalDVpuro;
        float tiempoDVpuro;
        
        clock_t tiempoInicioDVcompuesto;
        clock_t tiempoFinalDVcompuesto;
        float tiempoDVcompuesto;
            
        Lista<Punto> lista_de_puntos = generarListaDePuntos(puntos);
        
        tiempoInicioDVpuro = clock();
        
        OrdenacionMergeSort(lista_de_puntos, menorigualX);
        parMasCercano(lista_de_puntos, puntos, 0);
        
        tiempoFinalDVpuro = clock();
        
        tiempoDirecto = ((float) (tiempoFinalDVpuro - tiempoInicioDVpuro)) / CLOCKS_PER_SEC;
        
        //lista_de_puntos = generarListaDePuntos(puntos);
        
        tiempoInicioDV = clock();
        
        OrdenacionMergeSort(lista_de_puntos, menorigualX);
        parMasCercano(lista_de_puntos, numero_de_puntos, umbral);
        
        tiempoFinalDVcompuesto = clock();
        
        tiempoDVcompuesto = ((float) (tiempoFinalDVcompuesto - tiempoInicioDVcompuesto)) / CLOCKS_PER_SEC;
        
        compararDVpuroConDVcompuesto(tiempoDVpuro, tiempoDVcompuesto, puntos, umbral);
        
        // Decremento el nº de puntos.
        numero_de_puntos *= 10;
        umbral += 10;
    }
    
    return 0;
}

void compararDVpuroConDVcompuesto(float tiempoPuro, float tiempoCompuesto, int numeroPuntos, int umbral) {
    
    cout << "ALGORITMO PURO: " << tiempoPuro << " con número de puntos: " << numeroPuntos << endl;
    
    cout << "ALGORITMO COMPUESTO: " << tiempoCompuesto << " con número de puntos: " << numeroPuntos << " y umbral: " << umbral << endl << endl;
}
