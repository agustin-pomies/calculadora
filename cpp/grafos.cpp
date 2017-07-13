#include "../include/grafos.hpp"
#include "../include/tabla.hpp"
#include "../include/cola.hpp"

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
};

// Crea una matriz de tamanio maximo determinado por MAX_VER
grafo crear_grafo() {
    grafo G = new rep_grafo;
    G->cant_vertices = 0;
    G->cant_aristas = 0;
    for(int i = 0; i <= MAX_VER; i++)
        for(int j = 0; j <= MAX_VER; j++)
            G->info[i][j] = false;
    G->etiquetas = crear_tabla(MAX_VER);
    return G;
}

// Agrega al grafo un vertice
void agregar_vertice(grafo &G, char c) {
    if(G->cant_vertices != MAX_VER) {
        insertar_en_tabla(c, G->cant_vertices, G->etiquetas);
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
        // TODO:
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
    if(!G->info[valor_a][valor_b]) {
        G->info[valor_a][valor_b] = true;
        G->info[valor_b][valor_a] = true;
        G->cant_aristas++;
    }
}

// Remueve del grafo la arista entre a y b
// Si no habia arista no hace nada
// Precondicion: es_vertice(a) & es_vertice(b)
void remover_arista(grafo &G, char a, char b) {
    int valor_a = valor_en_tabla(a, G->etiquetas);
    int valor_b = valor_en_tabla(b, G->etiquetas);
    if(G->info[valor_a][valor_b]) {
        G->info[valor_a][valor_b] = false;
        G->info[valor_b][valor_a] = false;
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
num_t distancia(grafo G, char a, char b) {
    // TODO:
    // NOTA: Deep Searching no serviria, es mejor Breadth Searching
}

// Devuelve la mayor distancia entre dos vertices cualesquiera del grafo G
num_t diametro(grafo G) {
    // TODO:
}

// Devuelve el nro de caminos de largo n que comienzan en a y terminan en b
// Precondicion: n > 0, es_vertice(a), es_vertice(b)
num_t nro_caminos(grafo G, char a, char b, num_t n) {
    int valor_a = valor_en_tabla(a, G->etiquetas);
    int valor_b = valor_en_tabla(b, G->etiquetas);
    num_t devolucion;
    if(n == 1) {
        devolucion = G->info[valor_a][valor_b];
    } else {
        int res[G->cant_vertices];
        int copia[G->cant_vertices];
        /* for(int i = 0; i < G->cant_vertices; i++)
            copia[i] = G->info[valor_b][i];
        for(int x = 0; x < G->cant_vertices; x++)
            for(int y = 0; y < G->cant_vertices; y++)
                res[i] = vector[i]*/
        // TODO:
    }
    return devolucion;
}

// Devuelve true si v es vertice de G, false en caso contrario
bool es_vertice(grafo G, char v) { return valor_en_tabla(v, G->etiquetas) >= 0; }

// Devuelve true si entre a y b hay una arista que los une, false en caso contrario
// Precondicion: es_vertice(a) & es_vertice(b)
bool son_adyacentes(grafo G, char a, char b) {
    int valor_a = valor_en_tabla(a, G->etiquetas);
    int valor_b = valor_en_tabla(b, G->etiquetas);
    return G->info[valor_a][valor_b];
}

// Devuelve true si G esta vacio false en caso contrario
bool es_grafo_vacio(grafo G) { return G->cant_vertices == 0; }

// Devuelve true si en G no se pueden insertar mas vertices, false en caso contrario
bool esta_lleno_grafo(grafo G) { return G->cant_vertices == MAX_VER; }

// Devuelve true si G es completo, false en caso contrario
bool es_completo(grafo G) { return G->cant_aristas == ((G->cant_vertices)*(G->cant_vertices - 1))/2; }

// Devuelve una copia del grafo G
grafo copiar_grafo(grafo G) {
    grafo copia = new rep_grafo;
    copia->cant_vertices = G->cant_vertices;
    copia->cant_aristas = G->cant_aristas;
    // TODO: copiar tabla y matriz
    return copia;
}

// Devuelve el grafo complementario de G
grafo complementario(grafo G) {
    grafo C = crear_grafo();
    C->cant_vertices = G->cant_vertices;
    C->cant_aristas = ((G->cant_vertices*(G->cant_vertices-1))/2) - G->cant_aristas;
    for(int i = 0; i < C->cant_vertices; i++)
        for(int j = i; j < C->cant_vertices; j++) {
            C->info[i][j] = !G->info[i][j];
            C->info[j][i] = C->info[i][j];
        }
    //C->etiquetas;
    // TODO:
    return C;
}

// Devuelve true si G es conexo, false en caso contrario
bool es_conexo(grafo G) {
    bool res = false;
    if(!es_grafo_vacio(G)) {
        bool visita[G->cant_vertices];
        cola c = crear_cola();
        int cont, indice;
        encolar(0, c);
        cont = 0;
        for(int i = 1; i < G->cant_vertices; i++)
            visita[i] = false;

        while(!es_vacia_cola(c)) {
            indice = frente(c);
            visita[indice] = true;
            desencolar(c);
            cont++;
            for(int j = 0; j < G->cant_vertices; j++)
                if(G->info[indice][j] && !visita[j])
                    encolar(j, c);
        }
        liberar_cola(c);
        // REVISAR:
        delete visita[];
        res = cont == G->cant_vertices;
    }
    return res;
}

// Devuelve el nro de componentes conexas de G
num_t componentes_conexas(grafo G) {
    num_t comp = 0;
    if(!es_grafo_vacio(G)) {
        bool visita[G->cant_vertices];
        cola c = crear_cola();
        int cont, indice, n;
        cont = 0;
        n = 0;
        for(int i = 1; i < G->cant_vertices; i++)
            visita[i] = false;
        
        while(cont != G->cant_vertices) {
            while(visita[n])
                n++;
            encolar(n, c);
            while(!es_vacia_cola(c)) {
                indice = frente(c);
                visita[indice] = true;
                desencolar(c);
                cont++;
                for(int j = 0; j < G->cant_vertices; j++)
                    if(G->info[indice][j] && !visita[j])
                        encolar(j, c);
            }
            comp++;
        }
        liberar_cola(c);
        // REVISAR:
        delete visita[];
    }
    return comp;
}

// Devuelve true si G es plano, false en caso contrario
bool es_plano(grafo G) {
    bool res;
    res = G->cant_aristas <= 3*G->cant_vertices - 6;
    // TODO:
    // res = res && true;
    return res;
}

// Devuelve true si G es aciclico, false en caso contrario
bool es_aciclico(grafo G) {
    // TODO:
}

// Devuelve true si G es arbol, false en caso contrario
bool es_arbol(grafo G) {
    bool res;
    res = G->cant_vertices == G->cant_aristas + 1;
    // NOTA: eligo el que tenga mejor tiempo de ejecucion
    res = res & es_conexo(G); // orden V^2 en el peor caso
    res = res & es_aciclico(G);
    return res;
}

// Devuelve true si el G tiene un recorrido euleriano, false en caso contrario
bool existe_rec_euleriano(grafo G) {
    int impares = 0;
    if(es_conexo(G)) {
        int i, j, cont;
        i = 0;
        while(i < G->cant_vertices && impares < 3) {
            j = 0;
            cont = 0;
            while(j < G->cant_vertices) {
                if(G->info[i][j])
                    cont++;
                j++;
            }
            if(cont%2 != 0)
                impares++;
            i++;
        }
    }
    return impares == 2;
}

// Devuelve true si el G tiene un circuito euleriano, false en caso contrario
bool existe_circ_euleriano(grafo G) {
    bool res = es_conexo(G);
    if(res) {
        int i, j, cont;
        i = 0;
        while(i < G->cant_vertices && res) {
            j = 0;
            cont = 0;
            while(j < G->cant_vertices) {
                if(G->info[i][j])
                    cont++;
                j++;
            }
            res = cont%2 == 0;
            i++;
        }
    }
    return res;
}

// Devuelve true si el G tiene un camino hamiltoniano, false en caso contrario
bool existe_cam_hamiltoniano(grafo G) {

}

// Devuelve true si el G tiene un ciclo hamiltoniano, false en caso contrario
bool existe_cic_hamiltoniano(grafo G) {
    
}

// COLORACION