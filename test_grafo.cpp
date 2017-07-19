#include "include/grafos.hpp"
#include "include/tabla.hpp"
#include "include/cola.hpp"

#include <stdio.h>

/* LISTA DE FUNCIONES A PROBAR

bool esta_lleno_grafo(grafo G);
grafo copiar_grafo(grafo G);
grafo complementario(grafo G);
bool es_conexo(grafo G);
num_t componentes_conexas(grafo G);
bool es_plano(grafo G);
bool es_aciclico(grafo G);
bool es_arbol(grafo G);
bool existe_rec_euleriano(grafo G);
bool existe_circ_euleriano(grafo G);
bool existe_cam_hamiltoniano(grafo G);
bool existe_cic_hamiltoniano(grafo G);
*/

const char et1 = 'A';
const char et2 = 'B';
const char et3 = 'C';
const char et4 = 'D';
const char et5 = 'E';
const char et6 = 'F';
const char et7 = 'G';
const char et8 = 'H';
const char et9 = 'I';
const char et10 = 'J';

int main() {
    // Grafo Vacio
    printf("PRUEBA CON GRAFO VACIO\n");
    grafo vacio = crear_grafo();
    if(es_grafo_vacio(vacio))
        printf("El grafo es vacio.\n");
    else
        printf("El grafo es NO vacio.\n");
        
    if(es_vertice(vacio, et1))
        printf("El grafo TIENE el vertice %c.\n", et1);
    else
        printf("El grafo NO TIENE el vertice %c.\n", et1);
    // NOTA: no despliega esta instruccion
    // eliminar_grafo
    printf("\n");
    
    // Grafo K1
    printf("PRUEBA CON K1\n");
    grafo K1 = crear_grafo();
    agregar_vertice(K1, et1);
    
    if(es_grafo_vacio(K1))
        printf("El grafo es vacio.\n");
    else
        printf("El grafo es NO vacio.\n");
    
    if(nro_vertices(K1) == 1)
        printf("El vertice fue agregado.\n");
    
    if(es_vertice(K1, et1))
        printf("El grafo TIENE el vertice %c. \n", et1);
    else
        printf("El grafo NO TIENE el vertice %c. \n", et1);
    if(es_vertice(K1, et2))
        printf("El grafo TIENE el vertice %c. \n", et2);
    else
        printf("El grafo NO TIENE el vertice %c. \n", et2);
    if(es_completo(K1))
        printf("El grafo ES COMPLETO.\n");
    else
        printf("El grafo NO ES COMPLETO.\n");
    // eliminar grafo
    // NOTA: recien aca despliega todo
    printf("\n");

    // Grafo K2
    printf("PRUEBA CON K2\n");
    grafo K2 = crear_grafo();
    agregar_vertice(K2, et1);
    agregar_vertice(K2, et2);
    printf("El grado del vertice %c es %d. \n", et1, grado(K2, et1));
    printf("El grado del vertice %c es %d. \n", et2, grado(K2, et2));
    num_t dist = distancia(K2, et1, et2);
    printf("La distancia entre el vertice %c y %c es %d. \n", et1, et2, dist);
    if(son_adyacentes(K2, et1, et2))
        printf("Los vertices son adyacentes.\n");
    else 
        printf("Los vertices NO son adyacentes.\n");
    if(es_completo(K2))
        printf("El grafo ES COMPLETO.\n");
    else
        printf("El grafo NO ES COMPLETO.\n");
    
    agregar_arista(K2, et1, et2);
    dist = distancia(K2, et1, et2);
    printf("El grado del vertice %c es %d. \n", et1, grado(K2, et1));
    printf("El grado del vertice %c es %d. \n", et2, grado(K2, et2));
    if(son_adyacentes(K2, et1, et2))
        printf("Los vertices son adyacentes. \n");
    else 
        printf("Los vertices NO son adyacentes.\n");
    printf("La distancia entre el vertice %c y %c es %d. \n", et1, et2, dist);
    if(es_completo(K2))
        printf("El grafo ES COMPLETO.\n");
    else
        printf("El grafo NO ES COMPLETO.\n");
    
    remover_arista(K2, et1, et2);
    dist = distancia(K2, et1, et2);
    printf("El grado del vertice %c es %d. \n", et1, grado(K2, et1));
    printf("El grado del vertice %c es %d. \n", et2, grado(K2, et2));
    printf("La distancia entre el vertice %c y %c es %d. \n", et1, et2, dist);
     if(son_adyacentes(K2, et1, et2))
        printf("Los vertices son adyacentes.\n");
    else 
        printf("Los vertices NO son adyacentes.\n");
    if(es_completo(K2))
        printf("El grafo ES COMPLETO.\n");
    else
        printf("El grafo NO ES COMPLETO.\n");
    // eliminar_grafo
    printf("\n");

/*
    printf("PRUEBA CON K3\n");
    grafo K3 = crear_grafo();

    grafo K4 = crear_grafo();
    grafo K5 = crear_grafo();
    grafo K33 = crear_grafo();
    grafo Petersen = crear_grafo();
    grafo C4 = crear_grafo();
    grafo P6 = crear_grafo();
*/

    return 0;
}
