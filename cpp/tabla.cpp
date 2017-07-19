#include "../include/tabla.hpp"
#include "../include/lista.hpp"
#include <stdlib.h>
#include <limits.h>

struct rep_tabla {
  nodo *elems;
  int tamanio;
};

int hash(char c, tabla t) { return (int)c % t->tamanio; } 

tabla crear_tabla(int tamanio) {
	tabla t = new rep_tabla;
	t->tamanio = tamanio;
	t->elems = new nodo [tamanio];
	for(int i = 0; i < tamanio; i++)
		t->elems[i] = NULL;
	return t;
}

void insertar_en_tabla(char clave, int valor, tabla &t) {
	int indice = hash(clave, t);
	insertar_en_lista(clave, valor, t->elems[indice]);
}

void eliminar_de_tabla(char clave, tabla &t) {
	int indice = hash(clave, t);
	eliminar_de_tabla(clave, t->elems[indice]);
}

void liberar_tabla(tabla &t) {
	for(int i = 0; i < t->tamanio; i++)
		liberar_lista(t->elems[i]);
	delete t->elems;
	delete t;
}

int valor_en_tabla(char clave, tabla t) {
	int indice = hash(clave, t);
	int n = valor_en_lista(clave, t->elems[indice]);
	return n;
}

tabla copiar_tabla(tabla t) {
	tabla copia = crear_tabla(t->tamanio);
		for(int i = 0; i < t->tamanio; i++)
			copia->elems[i] = copiar_lista(t->elems[i]);
	return copia;
}