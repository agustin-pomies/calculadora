/* CALCULADORA */
#include "include/aritmetica.hpp"
//#include "include/polinomio.hpp"
//#include "include/discreta.hpp"
#include "include/grafos.hpp"
#include <stdio.h>
#include <cstdlib>

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

/* Para limpiar la pantalla de la consola tanto en Windows como Linux
void clear_screen() {
    #ifdef WIN32
        std::system("cls");
    #else
        // Assume POSIX
        std::system("clear");
    #endif

    Guardo por las dudas la funcion auxiliar
    for(int i = 1; i <= 50; i++)
        printf("\n");

}
*/

int main() {
    bool salir, atras;
    salir = false;
    atras = false;
    int option;
    char c;

    while(!salir) {
        atras = false;
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

        scanf("%d", &option);
        // clear_screen();
        switch(option) {
            case 1:
                //
                break;
            case 2:
                //
                break;
            case 3:
                //
                break;
            case 4:
                while(!atras) {
                    printf("Elija uno de los siguientes metodos para ingresar el grafo no dirigido\n");
                    printf("1) Matriz de Adyacencia\n");
                    printf("2) Listas de Adyacencia\n");
                    printf("3) Lista de Aristas\n");
                    printf("4) Mas info\n");
                    printf("0) Atras\n");
                    scanf("%d", &option);
                    // clear_screen();
                    switch(option) {
                        case 1:
                            //
                            break;
                        case 2:
                            //
                            break;
                        case 3:
                            //
                            break;
                        case 4:
                            printf("<< MATRIZ DE ADYACENCIA >>\n");
                            printf("La matriz de adyacencia es una matriz cuadrada cuya dimension es el numero de vertices del grafo y sus entradas son unos (1) o ceros (0).\n");
                            printf("La columna y fila [i] representan el vertice [i] del grafo dado.\n");
                            printf("La entrada [i,j] si es 1 significa que hay una arista que une al vertice [i] y al vertice [j] en el grafo ingresado.\n");
                            printf("Si es 0 no existe tal arista.\n");
                            printf("Se pide ingresar la matriz anteriormente descrita por filas donde cada entrada este separada por un espacio en blanco.\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("<< LISTA DE ADYACENCIA >>\n");
                            printf("Se da una lista de los vertices del grafo ingresado con sus vertices adyacentes:\n");
                            printf("Por cada vertice se explicita los vertices adyacentes al mismo a traves de sus nombres.\n");
                            printf("Se pide ingresar para cada vertice una lista con el siguiente formato: \n");
                            printf("nombre_vertice: vecino_1 vecino_2 ... ultimo_vecino\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("<< ARISTAS >>\n");
                            printf("Se ingresa en la entrada TODAS las aristas del grafo donde la arista esta representada por el par de vertices que une.\n");
                            printf("La arista que une el vertice A con el vertice D viene representada por el par AD.\n");
                            printf("Si el grafo es un grafo no dirigido se representa la arista que une A con D con el par AD o DA indistintamente.\n");
                            printf("Se pide ingresar las aristas por el par de nombres que tienen los vertices unidos\n");
                            printf("Procure una arista de otra por un espacio en blanco al ingresarlas.\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("A continuacion se otorga un ejemplo de ingreso de un grafo usando las 3 opciones a modo de ilustracion.\n"); 
                            printf("En este caso se ingresa un grafo de 4 vertices conectados en forma de rueda (C4)\n");
                            printf("\n");
                            printf("Ejemplo de ingreso:\n");
                            printf("0 1 0 1\n");
                            printf("1 0 1 0\n");
                            printf("0 1 0 1\n");
                            printf("1 0 1 0\n");
                            printf("\n");
                            printf("\n");
                            printf("Ejemplo de ingreso:\n");
                            printf("A: B D\n");
                            printf("B: A C\n");
                            printf("C: B D\n");
                            printf("D: A C\n");
                            printf("\n");
                            printf("\n");
                            printf("Ejemplo de ingreso:\n");
                            printf("AB AD DC CB\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf(">> Ingrese cualquier caracter para volver al menu anterior..\n");
                            c = getchar();
                            break;
                        case 0:
                            // clear_screen();
                            atras = true;
                            break;
                        default:
                            printf("Seleccion Invalida. Por favor intente nuevamente.");
                            printf("\n");
                    } // switch
                } // while
                break;
            case 5:
                //
                break;
            case 6:
                //
                break;
            case 7:
                //
                break;
            case 8:
                //
                break;
            case 9:
                //
                break;
            case 0:
                salir = true;
                break;
            default:
                printf("Seleccion Invalida. Por favor intente nuevamente.");
                printf("\n");
        }

        // leer el comando
        // char nom_comando[TXT_MAX_LNG];
        // scanf("%s", nom_comando);

    } // while
    return 0;    
}