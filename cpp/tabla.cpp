#include "../include/tabla.hpp"

#include <limits.h>

/* Hash abierto. */
struct rep_nodo {
	char c;
	int indice;
	nodo sig;
};

struct rep_tabla {
  rep_nodo *elems;
  int tamanio;
};

tabla crear_tabla(int tamanio) {
	tabla t = new rep_tabla;
	t->tamanio = tamanio;
	t->elems = new nodo [tamanio];
	for(int i = 0; i < tamanio; i++) {
		t->elems[i] = NULL;
	};
	return t;
}

// TODO:
// TODO:
// TODO:
// TODO:
// TODO:

void insertar_en_tabla(char clave, int valor, tabla &t) {
	int n;
	cadena cad = t->elems[hash_texto(clave, t->tamanio)];
	if(numero_de_texto(clave, cad, n)) {
		localizador loc = inicio_cadena(cad);
		nodo a_borrar;
		while(comparar_texto(clave, texto_info(info_cadena(loc, cad))) != igual || numero_info(info_cadena(loc, cad))!= n)
			loc = siguiente(loc, cad);
		a_borrar = info_cadena(loc, cad);
		cambiar_en_cadena(i, loc, cad);
		liberar_info(a_borrar);
	}	else
		insertar_despues(i, final_cadena(cad), cad);
}

void eliminar_de_tabla(char clave, tabla &t) {
	cadena cad = t->elems[hash_texto(clave, t->tamanio)];
	localizador loc = inicio_cadena(cad);
	localizador aux = loc;
	while(es_localizador_cadena(loc)) {
		if(comparar_texto(texto_info(info_cadena(loc, cad)), clave) == igual) {
			aux = loc;
			loc = siguiente(loc, cad);
			remover_de_cadena(aux, cad);
		} else {
			loc = siguiente(loc, cad);
		};
	};
}

void liberar_tabla(tabla &t) {
	for(int i = 0; i < t->tamanio; i++)
		liberar_cadena(t->elems[i]);
	delete [] t->elems;
	delete t;
}

int valor_en_tabla(char clave, tabla t) {
	cadena cad = t->elems[hash_texto(clave, t->tamanio)];
	int n;
	if(!numero_de_texto(clave, cad, n))
		n = INT_MAX;
	return n;
}
