#include "../include/grafos.hpp"
#include <stdlib.h>
//#include "matrices.hpp"
//#include "cola.hpp"

// GRAFOS
// Metodo para ingresar grafos:
//      & Ingresando el nro de vertices y las aristas del grafo (ad, bc, ...) [Lista de incidencia]
//      & Ingresando la matriz de adyacencia [Matriz de adyacencia]
//      & Ingresando por listas de vecinos [Lista de adyacencia]

struct rep_nodo_vecino {
    vertice ady;
    lista_vecinos sig_vecino;
};

struct rep_vertice {
    char nombre;
    lista_vecinos vecinos;
    vertice sig_ver;
};

struct rep_grafo {
    num_t cant_vertices;
    num_t cant_aristas;
    vertice info;
};

// Crea un grafo vacio
grafo crear_grafo() {
    grafo G = new rep_grafo;
    G->cant_vertices = 0;
    G->cant_aristas = 0;
    G->info = NULL;
    return G;
}

// Devuelve true si G esta vacio false en caso contrario
bool es_grafo_vacio(grafo G) { return G->info == NULL; }

// Devuelve true si v es vertice de G, false en caso contrario
bool es_vertice(grafo G, char v) {
    bool res = false;
    if(!es_grafo_vacio(G)) {
        vertice aux = G->info;
        while(aux->sig_ver != NULL && aux->nombre != v)
            aux = aux->sig_ver;
        if(aux->nombre == v)
            res = true;
    }
    return res;
}

// Agrega al grafo el vertice a
// Si ya estaba ese vertice no hace nada
void agregar_vertice(grafo &G, char v) {
    if(!es_vertice(G, v)) {
        vertice nuevo = new rep_vertice;
        nuevo->nombre = v;
        nuevo->vecinos = NULL;
        nuevo->sig_ver = G->info;
        G->info = nuevo;
        G->cant_vertices++;
    }
}

// Remueve del grafo el vertice a y sus aristas
// Si no estaba ese vertice no hace nada
void remover_vertice(grafo &G, char v);

// Devuelve true si entre a y b hay una arista que los une, false en caso contrario
// Precondicion: a != b, es_vertice(a) & es_vertice(b)
bool son_adyacentes(grafo G, char a, char b) {
    bool res = false;
    vertice aux = G->info;
    char etiqueta;
    while(aux->nombre != a && aux->nombre != b)
        aux = aux->sig_ver;
    if(aux->nombre == a)
        etiqueta = b;
    else
        etiqueta = a;
    lista_vecinos l = aux->vecinos;
    while(l != NULL && l->ady->nombre != etiqueta)
        l = l->sig_vecino;
    if(l != NULL)
        res = true;
    return res;
}

// Agrega al grafo la arista entre a y b
// Si la arista ya existia no hace nada
// Precondicion: es_vertice(a) & es_vertice(b), a != b
void agregar_arista(grafo &G, char a, char b) {
    if(!son_adyacentes(G, a, b)) {
        vertice v1 = G->info;
        vertice v2 = G->info;
        while(v1->nombre != a || v2->nombre != b) {
            if(v1->nombre != a)
                v1 = v1->sig_ver;
            if(v2->nombre != b)
                v2 = v2->sig_ver;
        }
        lista_vecinos nuevo1 = new rep_nodo_vecino;
        nuevo1->ady = v2;
        nuevo1->sig_vecino = v1->vecinos;
        v1->vecinos = nuevo1;
        lista_vecinos nuevo2 = new rep_nodo_vecino;
        nuevo2->ady = v1;
        nuevo2->sig_vecino = v2->vecinos;
        v2->vecinos = nuevo2;
        G->cant_aristas++;
    }
}

// Remueve del grafo la arista entre a y b
// Si no habia arista no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
void remover_arista(grafo &G, char a, char b) {
    if(son_adyacentes(G, a, b)) {
        vertice v = G->info;
        char etiqueta;
        while(v->nombre != a && v->nombre != b)
            v = v->sig_ver;
        if(v->nombre == a)
        etiqueta = b;
        else
        etiqueta = a;
        lista_vecinos l = v->vecinos;
        // TODO: SEGUIR
        while(l->sig_vecino->ady->nombre != )
        G->cant_aristas--;
    }
}

// Devuelve el nro de vertices de G
num_t nro_vertices(grafo G) { return G->cant_vertices; }

// Devuelve el nro de aristas de G
num_t nro_aristas(grafo G) { return G->cant_aristas; }

// Devuelve el grado del vertice v en el grafo G
// Precondicion: es_vertice(v)
num_t grado(grafo G, char v) {
    vertice a = G->info;
    while(a->nombre != v)
        a = a->sig_ver;
    lista_vecinos l = a->vecinos;
    num_t n = 0;
    while(l != NULL) {
        n++;
        l = l->sig_vecino;
    };
    return n;
}

// Devuelve la distancia entre los vertices a y b
// Precondicion: es_vertice(a) & es_vertice(b)
num_t distancia(grafo G, vertice a, vertice b);

// Devuelve la mayor distancia entre dos vertices cualesquiera del grafo G
num_t diametro(grafo G);

// Devuelve el nro de caminos de largo n que comienzan en a y terminan en b
// Precondicion: n > 0, es_vertice(a), es_vertice(b)
num_t nro_caminos(grafo G, vertice a, vertice b, num_t n);

// Devuelve true si G es completo, false en caso contrario
bool es_completo(grafo G);

// Devuelve un grafo completo de n vertices
// Precondicion: n > 0
grafo Kompleto(num_t n);

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
bool existe_rec_euleriano(grafo G) {

}

// Devuelve true si el G tiene un circuito euleriano, false en caso contrario
bool existe_circ_euleriano(grafo G) {
    //TODO: FALTA SABER SI ES CONEXO
    vertice aux = G->info;
    char etiqueta;
    bool res = true;
    while(aux != NULL && res) {
        etiqueta = aux->nombre;
        res = res && grado(G, etiqueta) % 2 == 0;
    }
    return res;
}

// Devuelve true si el G tiene un camino hamiltoniano, false en caso contrario
bool existe_cam_hamiltoniano(grafo G);

// Devuelve true si el G tiene un ciclo hamiltoniano, false en caso contrario
bool existe_cic_hamiltoniano(grafo G);

// COLORACION
