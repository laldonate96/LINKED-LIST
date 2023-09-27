#include "pila.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct nodo {
	void *elemento;
	struct nodo *anterior;
} nodo_t;

struct _pila_t {
	nodo_t *nodo_inicio;
	nodo_t *nodo_fin;
	size_t tope;
};

pila_t *pila_crear()
{	
	pila_t *pila = calloc(1, sizeof(struct _pila_t));

	if (pila == NULL)
		return NULL;	

	return pila;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{
	if (pila == NULL)
		return NULL;

	nodo_t *nodo_nuevo = calloc(1, sizeof(nodo_t));

	if (nodo_nuevo == NULL)
		return NULL;

	nodo_nuevo->elemento = elemento;

	if (pila->nodo_inicio == NULL) {
		pila->nodo_inicio = nodo_nuevo;
		pila->nodo_fin = nodo_nuevo;
	} else {
		nodo_nuevo->anterior = pila->nodo_fin;
		pila->nodo_fin = nodo_nuevo;
	}

	pila->tope++;

	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	if (pila == NULL)
		return NULL;

	nodo_t *nodo_a_eliminar = pila->nodo_fin;

	if (nodo_a_eliminar == NULL)
		return NULL;

	pila->nodo_fin = nodo_a_eliminar->anterior;
	void *elemento = nodo_a_eliminar->elemento;
	free(nodo_a_eliminar);
	pila->tope--;

	return elemento;

}

void *pila_tope(pila_t *pila)
{
	if (pila == NULL || pila->nodo_fin == NULL)
		return NULL;

	return pila->nodo_fin->elemento;
}

size_t pila_tamanio(pila_t *pila)
{
	if (pila == NULL)
		return 0;
	
	return pila->tope;
}

bool pila_vacia(pila_t *pila)
{
	if(pila == NULL)
		return true;

	return pila_tamanio(pila) == 0;
}

void pila_destruir(pila_t *pila)
{
	if (pila == NULL)
		return;

	nodo_t *nodo_actual = pila->nodo_fin;

	while (nodo_actual != NULL) {
		nodo_t *nodo_aux = nodo_actual->anterior;
		free(nodo_actual);
		nodo_actual = nodo_aux;
	}

	free(pila);
}
