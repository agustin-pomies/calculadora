#ifndef _GRAFOS_H
#define _GRAFOS_H

//#include "matrices.hpp"
//#include "cola.hpp"

// GRAFOS
// Metodo para ingresar grafos:
//      & Ingresando el nro de vertices y las aristas del grafo (ad, bc, ...) [Lista de incidencia]
//      & Ingresando la matriz de incidencia [Matriz de adyacencia]
//      & Ingresando por listas de vecinos [Lista de adyacencia]

struct rep_grafo;

typedef int num_t;
typedef rep_grafo *grafo;
const int MAX_VER = 20;

// Crea una matriz de tamanio maximo determinado por MAX_VER
// Tiempo de Ejecucion: O(MAX_VER^2)
grafo crear_grafo();

// Remueve del grafo el vertice a
// Si ya estaba ese vertice no hace nada
// Tiempo de Ejecucion: O(1)
void agregar_vertice(grafo &G, char c);

// Remueve del grafo el vertice y sus aristas
// Si no estaba ese vertice no hace nada
// Tiempo de Ejecucion: 
void remover_vertice(grafo &G, char c);

// Agrega al grafo la arista entre a y b
// Si la arista ya existia no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
// Tiempo de Ejecucion: O(1) en tiempo promedio
void agregar_arista(grafo &G, char a, char b);

// Remueve del grafo la arista entre a y b
// Si no habia arista no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
// Tiempo de Ejecucion: O(1) en tiempo promedio
void remover_arista(grafo &G, char a, char b);

// Devuelve el nro de vertices de G
// Tiempo de Ejecucion: O(1)
num_t nro_vertices(grafo G);

// Devuelve el nro de aristas de G
// Tiempo de Ejecucion: O(1)
num_t nro_aristas(grafo G);

// Devuelve el grado del vertice v en el grafo G
// Precondicion: es_vertice(v)
// Tiempo de Ejecucion: O(V)
num_t grado(grafo G, char v);

// Devuelve la distancia entre los vertices a y b
// Precondicion: es_vertice(a) & es_vertice(b)
// Tiempo de Ejecucion: 
num_t distancia(grafo G, char a, char b);

// Devuelve la mayor distancia entre dos vertices cualesquiera del grafo G
// Tiempo de Ejecucion: 
num_t diametro(grafo G);

// Devuelve el nro de caminos de largo n que comienzan en a y terminan en b
// Precondicion: n > 0, es_vertice(a), es_vertice(b)
// Tiempo de Ejecucion: 
num_t nro_caminos(grafo G, char a, char b, num_t n);

// Devuelve true si v es vertice de G, false en caso contrario
// Tiempo de Ejecucion: O(1) en tiempo promedio
bool es_vertice(grafo G, char v);

// Devuelve true si entre a y b hay una arista que los une, false en caso contrario
// Precondicion: es_vertice(a) & es_vertice(b)
// Tiempo de Ejecucion: O(1) en tiempo promedio
bool son_adyacentes(grafo G, char a, char b);

// Devuelve true si G esta vacio false en caso contrario
// Tiempo de Ejecucion: O(1)
bool es_grafo_vacio(grafo G);

// Devuelve true si en G no se pueden insertar mas vertices, false en caso contrario
// Tiempo de Ejecucion: O(1)
bool esta_lleno_grafo(grafo G);

// Devuelve true si G es completo, false en caso contrario
// Tiempo de Ejecucion: O(1)
bool es_completo(grafo G);

// Devuelve una copia del grafo G
// Tiempo de Ejecucion: O()
grafo copiar_grafo(grafo G);

// Devuelve el grafo complementario de G
// Tiempo de Ejecucion: 
grafo complementario(grafo G);

// Devuelve true si G es conexo, false en caso contrario
// Tiempo de Ejecucion: O(V^2) en el peor caso
bool es_conexo(grafo G);

// Devuelve el nro de componentes conexas de G
// Tiempo de Ejecucion: O(V^2) en el peor caso
num_t componentes_conexas(grafo G);

// Devuelve true si G es plano, false en caso contrario
// Tiempo de Ejecucion: 
bool es_plano(grafo G);

// Devuelve true si G es aciclico, false en caso contrario
// Tiempo de Ejecucion: 
bool es_aciclico(grafo G);

// Devuelve true si G es arbol, false en caso contrario
// Tiempo de Ejecucion: 
bool es_arbol(grafo G);

// Devuelve true si el G tiene un recorrido euleriano, false en caso contrario
// FIXME: Tiempo de Ejecucion: O(V^2) en el peor caso
// MEJORAR TE: no se si es conveniente
bool existe_rec_euleriano(grafo G);

// Devuelve true si el G tiene un circuito euleriano, false en caso contrario
// FIXME: Tiempo de Ejecucion: O(V^2) en el peor caso
// MEJORAR TE: no se si es conveniente
bool existe_circ_euleriano(grafo G);

// Devuelve true si el G tiene un camino hamiltoniano, false en caso contrario
// Tiempo de Ejecucion: 
bool existe_cam_hamiltoniano(grafo G);

// Devuelve true si el G tiene un ciclo hamiltoniano, false en caso contrario
// Tiempo de Ejecucion: 
bool existe_cic_hamiltoniano(grafo G);

// COLORACION

#endif