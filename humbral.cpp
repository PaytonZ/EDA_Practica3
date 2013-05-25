//
//  humbral.cpp
//  Practica3-EDA
//
//  Created by Dani on 25/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#include <iostream>
#include "TADs/Lista.h"
#include "pareja.h"
#include "faux.h"
#include "humbral.h"
#include "dyv.h"
#include "mezcla.h"

using namespace std;

int humbral(int numero_de_puntos) {
    
    bool dm = false;
    
    clock_t tiempoInicioDirecto;
    clock_t tiempoFinalDirecto;
    float tiempoDirecto;
    
    clock_t tiempoInicioDV;
    clock_t tiempoFinalDV;
    float tiempoDV;
    
    while ( numero_de_puntos >= 0 && !dm) {
        
        Lista<Punto> lista_de_puntos =  generarListaDePuntos(numero_de_puntos);
        
        tiempoInicioDirecto = clock();
        
        solucionDirecta(lista_de_puntos, numero_de_puntos);
        
        tiempoFinalDirecto = clock();
        
        tiempoDirecto = ((float) (tiempoFinalDirecto - tiempoInicioDirecto)) / CLOCKS_PER_SEC;
        
        cout << "HUMBRAL tiempo directo: " << tiempoDirecto << endl;
        
        tiempoInicioDV = clock();
        
        OrdenacionMergeSort(lista_de_puntos, menorigualX);
        parMasCercano(lista_de_puntos, numero_de_puntos, 50);
        
        tiempoFinalDV = clock();
        
        tiempoDV = ((float) (tiempoFinalDV - tiempoInicioDV)) / CLOCKS_PER_SEC;
        
        cout << "HUMBRAL puntos: " << numero_de_puntos << endl;
        cout << "HUMBRAL tiempo dv: " << tiempoDV << endl;
        
        dm = directaMenor(tiempoDirecto, tiempoDV);
        
        // Decremento el nº de punto de 10 en 10.
        numero_de_puntos -= 2;
    }
    
    return numero_de_puntos;
}

bool directaMenor(float tiempoDirecto, float tiempoDV) {
    return ( tiempoDirecto < tiempoDV );
}

