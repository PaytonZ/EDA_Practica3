//
//  umbral.h
//  Practica3-EDA
//
//  Created by Dani on 25/05/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#ifndef Practica3_EDA_humbral_h
#define Practica3_EDA_humbral_h

/**
 * Función que indica si el tiempo del algoritmo directo
 * es menor que el del algoritmo de divide y venceras.
 */
bool directaMenor(float tiempoDirecto, float tiempoDV);

/**
 * Función que obtiene el número de puntos a partir
 * del cual el algoritmo directo es más eficiente
 */
int humbral(int numero_de_puntos);

#endif
