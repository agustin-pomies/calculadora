#ifndef _ARITMETICA_H
#define _ARITMETICA_H

/* Aritmetica Básica
    (+, -, ×, ÷)
& Constantes
    - Pi
    - e
*/
typedef int num_t;

num_t suma(num_t a, num_t b);

num_t resta(num_t a, num_t b);

num_t producto(num_t a, num_t b);

// PRECONDICION: b != 0
num_t division_exacta(num_t a, num_t b);

#endif