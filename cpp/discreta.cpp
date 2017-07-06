#ifndef _DISCRETA_H
#define _DISCRETA_H

/* Mat. Discreta
    - Algoritmo de Euclides
    - MCD y mcm
    - División entera y módulo
    - Cantidad de divisores
    - Descomposición factorial
    - Coef. de Bezout
    - phi(n)
*/

type division_entera(type a; type b) {return (type)(a/b)} 

type modulo(type a; type b) {return a%b}

// guardar factores y exponentes en una lista?
void desc_factorial(type a) {
    type raiz = sqrt(a);
    type d = 2;
    while(a != 1 && d <= raiz) {
        
    };
}



#endif