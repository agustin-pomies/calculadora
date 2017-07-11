#include "../include/grafos.hpp"

// GRAFOS
// Metodo para ingresar grafos:
//      & Ingresando el nro de vertices y las aristas del grafo
//      & Ingresando la matriz de incidencia
//      & Ingresando por listas de vecinos

struct rep_grafo {
    bool info[MAX_VER][MAX_VER];
    num_t cant_vertices;
    num_t cant_aristas;
};

// Crea una matriz de tamanio maximo determinado por MAX_VER
grafo crear_grafo() {
    grafo G = new rep_grafo;
    G->cant_vertices = 0;
    G->cant_aristas = 0;
    for(int i = 0; i <= MAX_VER; i++)
        for(int j = 0; j <= MAX_VER; j++)
            G->info[i][j] = false;
    return G;
}

// Remueve del grafo el vertice a
// Si ya estaba ese vertice no hace nada
void agregar_vertice(grafo &G, vertice a);

// Remueve del grafo el vertice a y sus aristas
// Si no estaba ese vertice no hace nada
void remover_arista(grafo &G, vertice a);

// Agrega al grafo la arista entre a y b
// Si la arista ya existia no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
void agregar_arista(grafo &G, vertice a, vertice b);

// Remueve del grafo la arista entre a y b
// Si no habia arista no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
void remover_arista(grafo &G, vertice a, vertice b);

// Devuelve el nro de vertices de G
num_t nro_vertices(grafo G);

// Devuelve el nro de aristas de G
num_t nro_aristas(grafo G);

// Devuelve el grado del vertice v en el grafo G
// Precondicion: es_vertice(v)
num_t grado(grafo G, vertice v);

// Devuelve la distancia entre los vertices a y b
// Precondicion: es_vertice(a) & es_vertice(b)
num_t distancia(grafo G, vertice a, vertice b);

// Devuelve la mayor distancia entre dos vertices cualesquiera del grafo G
num_t diametro(grafo G);

// Devuelve el nro de caminos de largo n que comienzan en a y terminan en b
// Precondicion: n > 0, es_vertice(a), es_vertice(b)
num_t nro_caminos(grafo G, vertice a, vertice b, num_t n);

// Devuelve true si v es vertice de G, false en caso contrario
bool es_vertice(grafo G, vertice v);

// Devuelve true si entre a y b hay una arista que los une, false en caso contrario
bool son_adyacentes(vertice a, vertice b);

// Devuelve true si G esta vacio false en caso contrario
bool es_vacio(grafo G);

// Devuelve true si G es completo, false en caso contrario
bool es_completo(grafo G);

// Devuelve una copia del grafo G
grafo copiar_grafo(grafo G);

// Devuelve el grafo complementario de G
grafo complementario(grafo G);

// Devuelve true si G es conexo, false en caso contrario
bool es_conexo(grafo G);

// Devuelve el nro de componentes conexas de G
num_t componentes_conexas(grafo G);

// Devuelve true si G es plano, false en caso contrario
bool es_plano(grafo G);

// Devuelve true si G es aciclico, false en caso contrario
bool es_aciclico(grafo G);

// Devuelve true si G es arbol, false en caso contrario
bool es_arbol(grafo G);

// Devuelve true si el G tiene un recorrido euleriano, false en caso contrario
bool existe_rec_euleriano(grafo G);

// Devuelve true si el G tiene un circuito euleriano, false en caso contrario
bool existe_circ_euleriano(grafo G);

// Devuelve true si el G tiene un camino hamiltoniano, false en caso contrario
bool existe_cam_hamiltoniano(grafo G);

// Devuelve true si el G tiene un ciclo hamiltoniano, false en caso contrario
bool existe_cic_hamiltoniano(grafo G);

// COLORACION