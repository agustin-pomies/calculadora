/* Aritmetica Básica
    (+, -, ×, ÷)
& Constantes
    - Pi
    - e
*/
#include "../include/aritmetica.hpp"

num_t suma(num_t a, num_t b) {return a+b;}

num_t resta(num_t a, num_t b) {return a-b;}

num_t producto(num_t a, num_t b) {return a*b;}

// PRECONDICION: b != 0
num_t division_exacta(num_t a, num_t b) {return a/b;}
