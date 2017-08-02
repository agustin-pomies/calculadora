#include "include/grafos.hpp"
#include "include/tabla.hpp"
#include "include/cola.hpp"

#include <stdio.h>

/* LISTA DE FUNCIONES A PROBAR

bool esta_lleno_grafo(grafo G);
grafo copiar_grafo(grafo G);
grafo complementario(grafo G);
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
    // GRAFO VACIO
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
    eliminar_grafo(vacio);
    printf("\n");
    
    // GRAFO K1
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
    eliminar_grafo(K1);
    printf("\n");

    // GRAFO K2
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
    
    // luego de agregar la arista
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
    
    // luego de quitar la arista
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
    if(es_arbol(K2))
        printf("El grafo ES ARBOL.\n");
    else
        printf("El grafo NO ES ARBOL.\n");
    eliminar_grafo(K2);
    printf("\n");

    // GRAFO K3
    printf("PRUEBA CON K3\n");
    grafo K3 = crear_grafo();
    // agregar 3 vertices
    agregar_vertice(K3, et1);
    agregar_vertice(K3, et2);
    agregar_vertice(K3, et3);
    // agregar 2 aristas
    agregar_arista(K3, et1, et2);
    agregar_arista(K3, et1, et3);

    if(es_aciclico(K3))
        printf("El grafo ES ACICLICO.\n");
    else
        printf("El grafo NO ES ACICLICO.\n");
    if(es_arbol(K3))
        printf("El grafo ES ARBOL.\n");
    else
        printf("El grafo NO ES ARBOL.\n");
    if(existe_rec_euleriano(K3))
        printf("El grafo TIENE RECORRIDO EULERIANO.\n");
    else
        printf("El grafo NO TIENE RECORRIDO EULERIANO.\n");
    if(existe_circ_euleriano(K3))
        printf("El grafo TIENE CIRCUITO EULERIANO.\n");
    else
        printf("El grafo NO TIENE CIRCUITO EULERIANO.\n");

    // agregar la ultima arista
    agregar_arista(K3, et3, et2);

    if(es_aciclico(K3))
        printf("El grafo ES ACICLICO.\n");
    else
        printf("El grafo NO ES ACICLICO.\n");
    if(es_arbol(K3))
        printf("El grafo ES ARBOL.\n");
    else
        printf("El grafo NO ES ARBOL.\n");
    if(existe_rec_euleriano(K3))
        printf("El grafo TIENE RECORRIDO EULERIANO.\n");
    else
        printf("El grafo NO TIENE RECORRIDO EULERIANO.\n");
    if(existe_circ_euleriano(K3))
        printf("El grafo TIENE CIRCUITO EULERIANO.\n");
    else
        printf("El grafo NO TIENE CIRCUITO EULERIANO.\n");

    eliminar_grafo(K3);
    printf("\n");

    // GRAFO K4
    printf("PRUEBA CON K4\n");
    grafo K4 = crear_grafo();
    // agregar 4 vertices
    agregar_vertice(K4, et1);
    agregar_vertice(K4, et2);
    agregar_vertice(K4, et3);
    agregar_vertice(K4, et4);

    if(es_conexo(K4))
        printf("El grafo ES CONEXO.\n");
    else
        printf("El grafo NO ES CONEXO.\n");
    printf("El grafo tiene %d componentes conexas. \n", componentes_conexas(K4));
    if(existe_rec_euleriano(K4))
        printf("El grafo TIENE RECORRIDO EULERIANO.\n");
    else
        printf("El grafo NO TIENE RECORRIDO EULERIANO.\n");
    if(existe_circ_euleriano(K4))
        printf("El grafo TIENE CIRCUITO EULERIANO.\n");
    else
        printf("El grafo NO TIENE CIRCUITO EULERIANO.\n");
    if(es_aciclico(K3))
        printf("El grafo ES ACICLICO.\n");
    else
        printf("El grafo NO ES ACICLICO.\n");

    // agregar 2 atistas
    agregar_arista(K4, et1, et2);
    agregar_arista(K4, et3, et4);    

    if(es_conexo(K4))
        printf("El grafo ES CONEXO.\n");
    else
        printf("El grafo NO ES CONEXO.\n");
    printf("El grafo tiene %d componentes conexas. \n", componentes_conexas(K4));    
    if(existe_rec_euleriano(K4))
        printf("El grafo TIENE RECORRIDO EULERIANO.\n");
    else
        printf("El grafo NO TIENE RECORRIDO EULERIANO.\n");
    if(existe_circ_euleriano(K4))
        printf("El grafo TIENE CIRCUITO EULERIANO.\n");
    else
        printf("El grafo NO TIENE CIRCUITO EULERIANO.\n");
    if(es_aciclico(K3))
        printf("El grafo ES ACICLICO.\n");
    else
        printf("El grafo NO ES ACICLICO.\n");

    // agregar el resto de las aristas (repitiendo una)
    agregar_arista(K4, et1, et3);
    agregar_arista(K4, et1, et4);
    // repite esta
    agregar_arista(K4, et2, et1);
    agregar_arista(K4, et2, et3);
    agregar_arista(K4, et2, et4);    
    
    if(es_conexo(K4))
        printf("El grafo ES CONEXO.\n");
    else
        printf("El grafo NO ES CONEXO.\n");
    printf("El grafo tiene %d componentes conexas. \n", componentes_conexas(K4));
    if(existe_rec_euleriano(K4))
        printf("El grafo TIENE RECORRIDO EULERIANO.\n");
    else
        printf("El grafo NO TIENE RECORRIDO EULERIANO.\n");
    if(existe_circ_euleriano(K4))
        printf("El grafo TIENE CIRCUITO EULERIANO.\n");
    else
        printf("El grafo NO TIENE CIRCUITO EULERIANO.\n");
    if(es_aciclico(K3))
        printf("El grafo ES ACICLICO.\n");
    else
        printf("El grafo NO ES ACICLICO.\n");

    eliminar_grafo(K4);
    printf("\n");
    // NOTA: HASTA ACA LA SALIDA ESTA BIEN
/*
    // GRAFO K5
    printf("PRUEBA CON K5\n");    
    grafo v5 = crear_grafo();
    // agregar 5 vertices
    agregar_vertice(v5, et1);
    agregar_vertice(v5, et2);
    agregar_vertice(v5, et3);
    agregar_vertice(v5, et4);
    agregar_vertice(v5, et5);
    // prueba de agregar uno ya existente
    agregar_vertice(v5, et1);

    eliminar_grafo(v5);

    // usar el complementario
    grafo K5 = complementario(v5);

    eliminar_grafo(K5);
    
    // GRAFO K3,3
    printf("PRUEBA CON K3,3\n");
    // grupo A = impares = {1, 3, 5}
    // grupo B = pares = {2, 4, 6}
    grafo K33 = crear_grafo();
    // agregar 6 vertices
    agregar_vertice(K33, et1);
    agregar_vertice(K33, et2);
    agregar_vertice(K33, et3);
    agregar_vertice(K33, et4);
    agregar_vertice(K33, et5);
    agregar_vertice(K33, et6);
    // aristas desde et1
    agregar_arista(K33, et1, et2);
    agregar_arista(K33, et1, et4);
    agregar_arista(K33, et1, et6);
    // aristas desde et2
    agregar_arista(K33, et2, et1);
    agregar_arista(K33, et2, et3);
    agregar_arista(K33, et2, et5);
    // aristas desde et3
    agregar_arista(K33, et3, et2);
    agregar_arista(K33, et3, et4);
    agregar_arista(K33, et3, et6);
    // aristas desde et4
    agregar_arista(K33, et4, et1);
    agregar_arista(K33, et4, et3);
    agregar_arista(K33, et4, et5);
    // aristas desde et5
    agregar_arista(K33, et5, et2);
    agregar_arista(K33, et5, et4);
    agregar_arista(K33, et5, et6);
    // aristas desde et6
    agregar_arista(K33, et6, et1);
    agregar_arista(K33, et6, et3);
    agregar_arista(K33, et6, et5);

    eliminar_grafo(K33);  

    // GRAFO DE PETERSEN
    grafo Petersen = crear_grafo();
    // agregar 10 vertices
    agregar_vertice(Petersen, et1);
    agregar_vertice(Petersen, et2);
    agregar_vertice(Petersen, et3);
    agregar_vertice(Petersen, et4);
    agregar_vertice(Petersen, et5);
    agregar_vertice(Petersen, et6);
    agregar_vertice(Petersen, et7);
    agregar_vertice(Petersen, et8);
    agregar_vertice(Petersen, et9);
    agregar_vertice(Petersen, et10);

    eliminar_grafo(Petersen);
*/
/*
    grafo C4 = crear_grafo();
    grafo P6 = crear_grafo();
*/

    return 0;
}
