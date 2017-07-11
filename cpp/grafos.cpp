#include "../include/grafos.hpp"
#include "../include/tabla.hpp"

// GRAFOS
// Metodo para ingresar grafos:
//      & Ingresando el nro de vertices y las aristas del grafo
//      & Ingresando la matriz de incidencia
//      & Ingresando por listas de vecinos

struct rep_grafo {
    bool info[MAX_VER][MAX_VER];
    tabla etiquetas;
    num_t cant_vertices;
    num_t cant_aristas;
    num_t MAX_VER;
};

// Crea una matriz de tamanio maximo determinado por MAX_VER
grafo crear_grafo() {
    grafo G = new rep_grafo;
    G->cant_vertices = 0;
    G->cant_aristas = 0;
    G->MAX_VER = MAX_VER;
    for(int i = 0; i <= MAX_VER; i++)
        for(int j = 0; j <= MAX_VER; j++)
            G->info[i][j] = false;
    G->etiquetas = crear_tabla(MAX_VER);
    return G;
}

// Agrega al grafo un vertice
void agregar_vertice(grafo &G, char c) {
    if(G->cant_vertices != MAX_VER) {
        insertar_en_tabla(c, G->cant_vertices, G->etiquetas)
        G->cant_vertices++;
    }
}

// Remueve del grafo el vertice y sus aristas
void remover_vertice(grafo &G, char c) {
    if(!es_grafo_vacio(G)) {
        int indice = valor_en_tabla(c, G->etiquetas);
        for(int i = 0; i <= indice; i++) {
            G->info[indice][i] = false;
            G->info[i][indice] = false;
        };
        G->cant_vertices--;
        eliminar_de_tabla(c, G->etiquetas);
    };
}

// Agrega al grafo la arista entre a y b
// Si la arista ya existia no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
void agregar_arista(grafo &G, char a, char b) {
    int valor_a = valor_en_tabla(a, G->etiquetas);
    int valor_b = valor_en_tabla(b, G->etiquetas);
    G->info[a][b] = true;
    G->info[b][a] = true;
    G->cant_aristas++;
}

// Remueve del grafo la arista entre a y b
// Si no habia arista no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
void remover_arista(grafo &G, char a, char b) {
    int valor_a = valor_en_tabla(a, G->etiquetas);
    int valor_b = valor_en_tabla(b, G->etiquetas);
    G->info[a][b] = false;
    G->info[b][a] = false;
    G->cant_aristas--;
}

// Devuelve el nro de vertices de G
num_t nro_vertices(grafo G) { return G->cant_vertices; }

// Devuelve el nro de aristas de G
num_t nro_aristas(grafo G) { return G->cant_aristas; }

// Devuelve el grado del vertice v en el grafo G
// Precondicion: es_vertice(v)
num_t grado(grafo G, char v) {
    int valor_v = valor_en_tabla(v, G->etiquetas);
    int grado = 0;
    for(int i = 0; i < G->cant_vertices; i++) {
        if(G->info[valor_v][i])
            grado++;
    };
    return grado;
}

// Devuelve la distancia entre los vertices a y b
// Precondicion: es_vertice(a) & es_vertice(b)
num_t distancia(grafo G, vertice a, vertice b);

// Devuelve la mayor distancia entre dos vertices cualesquiera del grafo G
num_t diametro(grafo G);

// Devuelve el nro de caminos de largo n que comienzan en a y terminan en b
// Precondicion: n > 0, es_vertice(a), es_vertice(b)
num_t nro_caminos(grafo G, vertice a, vertice b, num_t n);

// Devuelve true si v es vertice de G, false en caso contrario
bool es_vertice(grafo G, char v) { return valor_en_tabla(v, G->etiquetas) >= 0; }

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