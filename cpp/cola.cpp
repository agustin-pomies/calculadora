#include "../include/cola.hpp"
#include <stddef.h>

struct rep_nodo {
	int dato;
	rep_nodo* sig;
};

struct rep_cola {
	rep_nodo* ppio;
	rep_nodo* fin;
};

cola crear_cola() {
	cola nuevo = new rep_cola;
	nuevo->ppio = nuevo->fin = NULL;
	return nuevo;
}

void encolar(int b, cola &c) {
	rep_nodo* elem = new rep_nodo;
	elem->dato = b;
	elem->sig = NULL;
	if(es_vacia_cola(c))
		c->ppio = elem;
	else
		c->fin->sig = elem;
	c->fin = elem;
}

void desencolar(cola &c) {
	if(!es_vacia_cola(c)) {
		rep_nodo* aux = c->ppio;
		if(c->ppio->sig == NULL)
			c->fin = NULL;
		c->ppio = c->ppio->sig;
		delete(aux);
	};
}

bool es_vacia_cola(cola c) {
	return c->ppio == NULL;
}

int frente(cola c) {
	return c->ppio->dato;
}

void liberar_cola(cola &c) {
	while(!es_vacia_cola(c))
		desencolar(c);
	delete(c);
}
