/* 4926148 - 5034314*/

#include "../include/tabla.hpp"
#include "../include/texto.hpp"
#include "../include/info.hpp"
#include "../include/cadena.hpp"

#include <limits.h>

/* Hash abierto. */
struct rep_tabla {
  cadena *elems;
  nat tamanio;
};

tabla crear_tabla(nat tamanio) {
	tabla t = new rep_tabla;
	t->tamanio = tamanio;
	t->elems = new cadena [tamanio];
	for(nat i = 0; i < tamanio; i++) {
		t->elems[i] = crear_cadena();
	};
	return t;
}

void insertar_en_tabla(texto_t clave, int valor, tabla &t) {
	info_t i = crear_info(valor, clave);
	int n;
	cadena cad = t->elems[hash_texto(clave, t->tamanio)];
	if(numero_de_texto(clave, cad, n)) {
		localizador loc = inicio_cadena(cad);
		info_t a_borrar;
		while(comparar_texto(clave, texto_info(info_cadena(loc, cad))) != igual || numero_info(info_cadena(loc, cad))!= n)
			loc = siguiente(loc, cad);
		a_borrar = info_cadena(loc, cad);
		cambiar_en_cadena(i, loc, cad);
		liberar_info(a_borrar);
	}	else
		insertar_despues(i, final_cadena(cad), cad);
}

void eliminar_de_tabla(texto_t clave, tabla &t) {
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
	for(nat i = 0; i < t->tamanio; i++)
		liberar_cadena(t->elems[i]);
	delete [] t->elems;
	delete t;
}

int valor_en_tabla(texto_t clave, tabla t) {
	cadena cad = t->elems[hash_texto(clave, t->tamanio)];
	int n;
	if(!numero_de_texto(clave, cad, n))
		n = INT_MAX;
	return n;
}
