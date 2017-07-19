#include "../include/lista.hpp"
#include <stdlib.h>

struct rep_nodo {
	char c;
	int indice;
	lista sig;
};

// Devuelve la lista vacia
// Tiempo de Ejecucion: O(1)
lista nueva_lista() { return NULL; }

// Inserta los datos clave y valor al principio de la lista
// Tiempo de Ejecucion: O(1)
void insertar_en_lista(char clave, int valor, lista &l) {
    lista aux = new rep_nodo;
    aux->c = clave;
    aux->indice = valor;
    aux->sig = l;
    l = aux;
}

// Elimina de l el nodo con el dato clave
// Si es vacia no hace nada
// Tiempo de Ejecucion: O(n) siendo n el largo de la lista
void eliminar_de_tabla(char clave, lista &l) {
    if(l != NULL) {
        lista aux = l;
        while(aux->sig->c != clave)
            aux = aux->sig;
        lista a_borrar = aux->sig;
        aux->sig = aux->sig->sig;
        delete a_borrar;
    }
}

// Libera la memoria asignada a l
// Tiempo de Ejecucion: O(n) siendo n el largo de la lista
void liberar_lista(lista &l) {
    lista aux;
    while(l != NULL) {
        aux = l;
        l = l->sig;
        delete aux;
    }    
}

// Devuelve el valor numerico que acompania a clave
// Tiempo de Ejecucion: O(n) siendo n el largo de la lista
int valor_en_lista(char clave, lista l) {
    lista aux = l;
    int n;
    while(aux != NULL && aux->c != clave)
        aux = aux->sig;
    if(aux != NULL)
        n = aux->indice;
    else
        n = -1;
    return n;
}

// Devuelve una copia de l (la lista es copiada al reves)
// Tiempo de Ejecucion: O(n) siendo n el largo de la lista
lista copiar_lista(lista l) {
    lista copia = nueva_lista();
    lista aux = l;
    while(aux != NULL) {
        insertar_en_lista(aux->c, aux->indice, copia);
        aux = aux->sig;
    }
    return copia;
}