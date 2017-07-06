#ifndef _DISCRETA_H
#define _DISCRETA_H

#include <stdlib.h>

/* Mat. Discreta
    - Algoritmo de Euclides
    - MCD y mcm
    - División entera y módulo
    - Cantidad de divisores
    - Descomposición factorial
    - Coef. de Bezout
    - phi(n)
*/

type division_entera(type a, type b) {return (type)(a/b);} 

type modulo(type a, type b) {return a%b;}

type Euclides(type a, type b, bool extended) {
    // ALGORITMO DE EUCLIDES TRADICIONAL
    type r = modulo(a,b);
    while(r != 0) {
        a = b;
        b = r;
        r = modulo(a, b);
    };
    return b;

    // ALGORITMO DE EUCLIDES EXTENDIDO
    type aux = 0;
    type matrix [2][2];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            if(i == j)
                matrix [i][j] = 1;
            else
                matrix [i][j] = 0;
        };
    type q = division_entera(a, b);
    type r = modulo(a,b);
    while(r != 0) {
        for(int i = 0; i < 2; i++) {
            aux = matrix[0][i];
            matrix[0][i] = matrix[1][i];
            matrix[1][i] = aux - q*matrix[1][i];
        };
        a = b;
        b = r;
        q = division_entera(a,b);
        r = modulo(a,b);
    };
    // Los coeficientes de Bezout son las entradas [1][0] y [1][1]
    // El valor de b es el gcd
}

// guardar factores y exponentes en una lista?
// leer metodo de pollard
list desc_factorial(type a) {
    type raiz = sqrt(a);
    type d = 2;
    type pot = 0;
    while(a != 1 && d <= raiz) {
        while(a%d == 0) {
            a = a/d;
            pot++;
        };
        d++;
    };
}

#endif