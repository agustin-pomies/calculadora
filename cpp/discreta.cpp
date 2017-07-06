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
struct rep_list {
    type factor;
    type exponente;
    rep_list* sig;
};

typedef rep_list* list;

void insertar_en_lista(type a, list &l) {

}

type division_entera(type a, type b) {return (type)(a/b)} 

type modulo(type a, type b) {return a%b}

// guardar factores y exponentes en una lista?
list desc_factorial(type a) {
    type raiz = sqrt(a);
    type d = 2;
    while(a != 1 && d <= raiz) {
        
    };
}



#endif