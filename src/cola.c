#include "cola.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct _cola_t {
	nodo_t *nodo_inicio;
	nodo_t *nodo_fin;
	size_t longitud;
};

cola_t *cola_crear()
{
	cola_t *cola = calloc(1, sizeof(struct _cola_t));

	if (!cola)
		return NULL;

	return cola;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	if (!cola)
		return NULL;

	nodo_t *nodo_nuevo = calloc(1, sizeof(nodo_t));

	if (!nodo_nuevo)
		return NULL;

	nodo_nuevo->elemento = elemento;

	if (!cola->nodo_inicio) {
		cola->nodo_inicio = nodo_nuevo;
		cola->nodo_fin = nodo_nuevo;
	} else {
		cola->nodo_fin->siguiente = nodo_nuevo;
		cola->nodo_fin = nodo_nuevo;
	}

	cola->longitud++;

	return cola;
}

void *cola_desencolar(cola_t *cola)
{
	if (!cola)
		return NULL;

	nodo_t *nodo_a_eliminar = cola->nodo_inicio;

	if (!nodo_a_eliminar)
		return NULL;

	cola->nodo_inicio = nodo_a_eliminar->siguiente;

	void *elemento = nodo_a_eliminar->elemento;
	free(nodo_a_eliminar);
	cola->longitud--;

	return elemento;
}

void *cola_frente(cola_t *cola)
{
	if (!cola || !cola->nodo_inicio)
		return NULL;

	return cola->nodo_inicio->elemento;
}

size_t cola_tamanio(cola_t *cola)
{
	if (!cola)
		return 0;

	return cola->longitud;
}

bool cola_vacia(cola_t *cola)
{
	if (!cola)
		return true;

	return cola_tamanio(cola) == 0;
}

void cola_destruir(cola_t *cola)
{
	if (!cola)
		return;

	nodo_t *nodo_actual = cola->nodo_inicio;

	while (nodo_actual) {
		nodo_t *nodo_aux = nodo_actual->siguiente;
		free(nodo_actual);
		nodo_actual = nodo_aux;
	}

	free(cola);
}
