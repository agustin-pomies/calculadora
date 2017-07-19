#ifndef _LISTA_H
#define _LISTA_H

struct rep_nodo;

typedef rep_nodo *lista;

// Devuelve la lista vacia
// Tiempo de Ejecucion: O(1)
lista nueva_lista();

// Inserta los datos clave y valor al principio de la lista
// Tiempo de Ejecucion: O(1)
void insertar_en_lista(char clave, int valor, lista &l);

// Elimina de l el nodo con el dato clave
// Tiempo de Ejecucion: O()
void eliminar_de_tabla(char clave, lista &l);

// Libera la memoria asignada a l
// Tiempo de Ejecucion: O()
void liberar_lista(lista &l);

// 
// Tiempo de Ejecucion: O()
int valor_en_lista(char clave, lista l);

// Devuelve una copia de l
// Tiempo de Ejecucion: O(n) siendo n el largo de la lista
lista copiar_lista(lista l);

#endif