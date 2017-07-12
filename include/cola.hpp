#ifndef _COLA_H
#define _COLA_H

struct rep_cola;
typedef rep_cola *cola;

/* Constructoras */

/*  Devuelve una cola_binarios vacía (sin elementos). */
cola crear_cola();

/* Encola `a' en `c'. */
void encolar(char a, cola &c);

/* Destructoras */

/*
  Remueve de `c' el elemento que está en el frente.
  No libera la memoria del elemento removido.
  Si es_vacia_cola(c) no hace nada.
 */
void desencolar(cola &c);

/* Libera la memoria asignada a `c', pero NO la de sus elementos. */
void liberar_cola(cola &c);

/* Predicados */

/* Devuelve `true' si y sólo si `c' es vacía (no tiene elementos). */
bool es_vacia_cola(cola c);

/* Selectoras */

/*
  Devuelve el elemento que está en el frente de `c'.
  Precondición: ! es_vacia_cola(c);
 */
char frente(cola c);

#endif
