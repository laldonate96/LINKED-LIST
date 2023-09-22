#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	size_t longitud;
};

struct lista_iterador {
	nodo_t *nodo_actual;
	lista_t *lista;
};

lista_t *lista_crear()
{
	lista_t *lista = calloc(1, sizeof(struct lista));

	if (lista == NULL)
		return NULL;

	return lista;
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{
	nodo_t *nodo_nuevo = calloc(1, sizeof(nodo_t));

	nodo_nuevo->elemento = elemento;
	nodo_nuevo->siguiente = NULL;

	if (lista->nodo_inicio == NULL) {
		lista->nodo_inicio = nodo_nuevo;
	} else {
		nodo_t *nodo_actual = lista->nodo_inicio;

		while (nodo_actual->siguiente != NULL)
			nodo_actual = nodo_actual->siguiente;

		nodo_actual->siguiente = nodo_nuevo;
	}

	lista->longitud++;

	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento,
				    size_t posicion)
{
	if(lista == NULL)
		return NULL;
	else if(posicion > lista->longitud)
		return lista_insertar(lista, elemento);
		
	nodo_t *nodo_nuevo = calloc(1, sizeof(nodo_t));

	if(nodo_nuevo == NULL)
		return NULL;

	nodo_nuevo->elemento = elemento;
	nodo_nuevo->siguiente = NULL;

	if (lista->nodo_inicio == NULL) {
		lista->nodo_inicio = nodo_nuevo;
	} else if (posicion == 0) {
		nodo_nuevo->siguiente = lista->nodo_inicio;
		lista->nodo_inicio = nodo_nuevo;
	} else {
		nodo_t *nodo_actual = lista->nodo_inicio;
		size_t i = 0;

		while (nodo_actual->siguiente != NULL && i < posicion - 1) {
			nodo_actual = nodo_actual->siguiente;
			i++;
		}

		nodo_nuevo->siguiente = nodo_actual->siguiente;
		nodo_actual->siguiente = nodo_nuevo;
	}

	lista->longitud++;

	return lista;
}

void *lista_quitar(lista_t *lista)
{
	if(lista->nodo_inicio == NULL || lista == NULL)
		return NULL;
	
	nodo_t *nodo_actual = lista->nodo_inicio;

	while (nodo_actual->siguiente != NULL)
		nodo_actual = nodo_actual->siguiente;

	void *elemento = nodo_actual->elemento;
	free(nodo_actual);
	lista->longitud--;

	return elemento;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	if (lista == NULL || lista->nodo_inicio == NULL)
		return NULL;
	else if (posicion >= lista->longitud)
		return lista_quitar(lista);

	nodo_t *nodo_aux = NULL;

	if (lista->nodo_inicio == NULL) {
		return NULL;
	} else if (posicion == 0) {
		nodo_aux = lista->nodo_inicio;
		lista->nodo_inicio = nodo_aux->siguiente;
	} else {
		nodo_t *nodo_actual = lista->nodo_inicio;
		size_t i = 0;

		while (nodo_actual->siguiente != NULL && i < posicion - 1) {
			nodo_actual = nodo_actual->siguiente;
			i++;
		}

		nodo_aux = nodo_actual->siguiente;
		nodo_actual->siguiente = nodo_aux->siguiente;
		
	}

	void *elemento = nodo_aux->elemento;
	free(nodo_aux);
	lista->longitud--;

	return elemento;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	if (lista == NULL || lista->nodo_inicio == NULL || posicion >= lista->longitud)
		return NULL;

	nodo_t *nodo_actual = lista->nodo_inicio;

	for (size_t i = 0; i < posicion; i++)
		nodo_actual = nodo_actual->siguiente;

	return nodo_actual->elemento;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *),
			    void *contexto)
{
	if(lista == NULL || lista->nodo_inicio == NULL)
		return NULL;

	nodo_t *nodo_actual = lista->nodo_inicio;

	while (nodo_actual->siguiente != NULL) {
		if (comparador(nodo_actual->elemento, contexto) == 0)
			return nodo_actual->elemento;
		nodo_actual = nodo_actual->siguiente;
	}

	if(comparador(nodo_actual->elemento, contexto) == 0)
		return nodo_actual->elemento;

	return NULL;
}

void *lista_primero(lista_t *lista)
{
	if(lista == NULL || lista->nodo_inicio == NULL)
		return NULL;
	return lista->nodo_inicio->elemento;
}

void *lista_ultimo(lista_t *lista)
{
	if (lista == NULL || lista->nodo_inicio == NULL)
		return NULL;
	
	nodo_t *nodo_actual = lista->nodo_inicio;

	while (nodo_actual->siguiente != NULL)
		nodo_actual = nodo_actual->siguiente;
	
	return nodo_actual->elemento;
}

bool lista_vacia(lista_t *lista)
{
	if(lista->nodo_inicio == NULL)
		return true;
	else
		return false;
}

size_t lista_tamanio(lista_t *lista)
{
	if (lista == NULL)
		return 0;

	return lista->longitud;
}

void lista_destruir(lista_t *lista)
{
	if(lista == NULL)
		return;
	
	nodo_t *nodo_actual = lista->nodo_inicio;

	while (nodo_actual->siguiente != NULL) {
		nodo_t *nodo_aux = nodo_actual->siguiente;

		free(nodo_actual);
		nodo_actual = nodo_aux;
	}
	
	free(nodo_actual);
	free(lista);
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
	if(lista == NULL)
		return;
	
	nodo_t *nodo_actual = lista->nodo_inicio;

	while (nodo_actual->siguiente != NULL) {
		nodo_t *nodo_aux = nodo_actual->siguiente;

		if (funcion != NULL && nodo_actual->elemento != NULL) {
            funcion(nodo_actual->elemento);
        }

		free(nodo_actual);
		nodo_actual = nodo_aux;
	}

	if (funcion != NULL && nodo_actual->elemento != NULL) {
		funcion(nodo_actual->elemento);
	}

	free(nodo_actual);
	free(lista);

	return;
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	lista_iterador_t *iterador = calloc(1, sizeof(lista_iterador_t));

	if (iterador == NULL)
		return NULL;

	iterador->lista = lista;

	if (lista->nodo_inicio != NULL)
		iterador->nodo_actual = lista->nodo_inicio;

	return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	if (iterador == NULL || iterador->lista == NULL)
		return false;
	else if (iterador->nodo_actual->siguiente != NULL)
		return true;
	
	return false;

}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	if (iterador == NULL || iterador->lista == NULL)
		return false;
	else if (iterador->nodo_actual->siguiente != NULL) {
		iterador->nodo_actual = iterador->nodo_actual->siguiente;
		return true;
	}

	return false;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if (iterador == NULL || iterador->lista == NULL)
		return NULL;

	return iterador->nodo_actual->elemento;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	if (iterador == NULL)
		return;

	free(iterador);	
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
			       void *contexto)
{
	if (lista == NULL || lista->nodo_inicio == NULL)
		return 0;
	
	nodo_t *nodo_actual = lista->nodo_inicio;
	size_t elementos_recorridos = 0;

	while (nodo_actual->siguiente != NULL) {
		if (funcion(nodo_actual->elemento, contexto) == false)
			return elementos_recorridos;
		nodo_actual = nodo_actual->siguiente;
		elementos_recorridos++;
	}

	if (funcion(nodo_actual->elemento, contexto))
		elementos_recorridos++;

	return elementos_recorridos;
}
