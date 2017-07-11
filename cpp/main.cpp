/* CALCULADORA */
#include "../include/polinomio.hpp"
#include "../include/aritmetica.hpp"
#include "../include/discreta.hpp"

/* EASTER EGGS
Dividir entre 0 - The Final Countdown / Europe
Raiz cuadrada de negativo - Imagine / John Lennon
300 - THIS IS SPARTA
99 - 99 red balloons / Nena
69 - summer of 69 / Brian Adams
123 - abc 123 / Jackson 5
0.07 - James Bond Theme

FUNCIONALIDADES
& Álgebra Lineal
    - Matrices y determinantes
& Cálculo
    - Integración y derivación
& Funciones
    - Ruffini

NÚMEROS DESTACADOS
007, 69, 42, 99, 123, 300, 666, 

MODOS
42 - todas las respuestas son 42
*/

int main() {
    printf("<<< CALCULADORA PRO v1.0 >>>\n");
    printf("Menu de Opciones:\n");
    printf("1) Aritmetica\n");
    printf("2) Mat. Discreta\n");
    printf("3) Polinomios\n");
    printf("4) Grafos\n");
    printf("5) Calculo\n");
    printf("6) Algebra Lineal\n");
    printf("7) \n");
    printf("8) \n");
    printf("9) \n");
    printf("0) Salir\n");

    // leer el comando
    char nom_comando[TXT_MAX_LNG];
    scanf("%s", nom_comando);

    return 0;    
}