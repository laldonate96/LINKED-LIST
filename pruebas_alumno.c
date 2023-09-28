#include "pa2m.h"
#include "src/lista.h"
#include <string.h>

void prueba_lista_crear()
{
	lista_t *lista = lista_crear();
	if (lista) {
		printf("✓ Se creo la lista\n");
	} else {
		printf("✗ Se creo la lista\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_lista_nula()
{
	lista_t *lista = NULL;
	if (!lista_insertar(lista, "hola")) {
		printf("✓ No se puede insertar al final en una lista nula\n");
	} else {
		printf("✗ No se deberia poder insertar al final en una lista nula\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_lista_vacia()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	if (lista_insertar(lista, elemento) && (lista_elemento_en_posicion(lista, 0) == elemento)) {
		printf("✓ Se inserto al final y se verifico su posicion en una lista vacia\n");
	} else {
		printf("✗ Se inserto al final y se verifico su posicion en una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_lista_con_elementos()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && (lista_elemento_en_posicion(lista, 1) == elemento_2)) {
		printf("✓ Se inserto al final y se verifico su posicion en una lista con elementos\n");
	} else {
		printf("✗ Se inserto al final y se verifico su posicion en una lista con elementos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_elemento_null()
{
	lista_t *lista = lista_crear();
	char *elemento = NULL;
	if (lista_insertar(lista, elemento) && (lista_elemento_en_posicion(lista, 0) == elemento)) {
		printf("✓ Se inserto al final un elemento NULL y se verifico su posicion en una lista vacia\n");
	} else {
		printf("✗ Se inserto al final un elemento NULL y se verifico su posicion en una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_en_posicion_lista_nula()
{
	lista_t *lista = NULL;
	char *elemento = "hola";
	if (!lista_insertar_en_posicion(lista, elemento, 0)) {
		printf("✓ No se puede insertar en una posicion en una lista nula\n");
	} else {
		printf("✗ No se deberia poder insertar en una posicion en una lista nula\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_en_posicion_lista_vacia()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	if (lista_insertar_en_posicion(lista, elemento, 0) && (lista_elemento_en_posicion(lista, 0) == elemento)) {
		printf("✓ Se inserto en una posicion y se verifico su posicion en una lista vacia\n");
	} else {
		printf("✗ Se inserto en una posicion y se verifico su posicion en una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_en_posicion_lista_con_elementos()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar_en_posicion(lista, elemento_2, 1) && (lista_elemento_en_posicion(lista, 1) == elemento_2)) {
		printf("✓ Se inserto en una posicion y se verifico su posicion en una lista con elementos\n");
	} else {
		printf("✗ Se inserto en una posicion y se verifico su posicion en una lista con elementos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_en_posicion_inexistente()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar_en_posicion(lista, elemento_2, 2) && (lista_elemento_en_posicion(lista, 1) == elemento_2)) {
		printf("✓ Se inserto en una posicion inexistente y se verifico su posicion en una lista con elementos\n");
	} else {
		printf("✗ Se inserto en una posicion inexistente y se verifico su posicion en una lista con elementos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_elemento_nulo_lista_valida()
{
	lista_t *lista = lista_crear();
	char *elemento = NULL;
	if (lista_insertar_en_posicion(lista, elemento, 0) && (lista_elemento_en_posicion(lista, 0) == elemento)) {
		printf("✓ Se inserto un elemento nulo en una posicion y se verifico su posicion en una lista valida\n");
	} else {
		printf("✗ Se inserto un elemento nulo en una posicion y se verifico su posicion en una lista valida\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_varios_elementos()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	char *elemento_3 = "como";
	char *elemento_4 = "estas";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_insertar(lista, elemento_3) && lista_insertar(lista, elemento_4)) {
		if ((lista_elemento_en_posicion(lista, 0) == elemento) && (lista_elemento_en_posicion(lista, 1) == elemento_2) && (lista_elemento_en_posicion(lista, 2) == elemento_3) && (lista_elemento_en_posicion(lista, 3) == elemento_4)) {
			printf("✓ Se insertaron varios elementos y se verifico su posicion en una lista valida\n");
		} else {
			printf("✗ Se insertaron varios elementos y se verifico su posicion en una lista valida\n");
			__pa2m_cantidad_de_pruebas_fallidas++;
		}
	} else {
		printf("✗ Se insertaron varios elementos y se verifico su posicion en una lista valida\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_insertar_elemento_repetido()
{
	lista_t *lista = lista_crear();
	int contador = 0;
	char *elemento = "hola";
	char *elemento_2 = "chau";
	char *elemento_3 = "hola";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_insertar(lista, elemento_3)) {
		for (size_t i = 0; i < sizeof(lista); i++) {
			if (lista_elemento_en_posicion(lista, i) == elemento)
				contador++;
		}
		if (contador >= 2) {
			printf("✓ Se insertaron correctamente elementos repetidos\n");
		} else {
		printf("✗ Se insertaron correctamente elementos repetidos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
		}
	} else {
		printf("✗ Se insertaron correctamente elementos repetidos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_lista_nula()
{
	lista_t *lista = NULL;
	if (!lista_quitar(lista)) {
		printf("✓ No se puede quitar el ultimo elemento de una lista nula\n");
	} else {
		printf("✗ No se deberia poder quitar el ultimo elemento de una lista nula\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_lista_vacia()
{
	lista_t *lista = lista_crear();
	if (!lista_quitar(lista)) {
		printf("✓ No se puede quitar el ultimo elemento de una lista vacia\n");
	} else {
		printf("✗ No se deberia poder quitar el ultimo elemento de una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_lista_con_elementos()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_quitar(lista) && (lista_elemento_en_posicion(lista, 0) == elemento)) {
		printf("✓ Se quito el ultimo elemento y se verifico la posicion en una lista con elementos\n");
	} else {
		printf("✗ Se quito el ultimo elemento y se verifico la posicion en una lista con elementos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_en_posicion_lista_nula()
{
	lista_t *lista = NULL;
	if (!lista_quitar_de_posicion(lista, 0)) {
		printf("✓ No se puede quitar un elemento de una lista nula\n");
	} else {
		printf("✗ No se deberia poder quitar un elemento de una lista nula\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_en_posicion_lista_vacia()
{
	lista_t *lista = lista_crear();
	if (!lista_quitar_de_posicion(lista, 0)) {
		printf("✓ No se puede quitar un elemento de una lista vacia\n");
	} else {
		printf("✗ No se deberia poder quitar un elemento de una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_en_posicion_lista_con_elementos()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_quitar_de_posicion(lista, 0) && (lista_elemento_en_posicion(lista, 0) == elemento_2)) {
		printf("✓ Se quito un elemento y se verifico la posicion en una lista con elementos\n");
	} else {
		printf("✗ Se quito un elemento y se verifico la posicion en una lista con elementos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_quitar_multiples_elementos()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	char *elemento_3 = "como";
	char *elemento_4 = "estas";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_insertar(lista, elemento_3) && lista_insertar(lista, elemento_4)) {
		if (lista_quitar_de_posicion(lista, 0) && lista_quitar_de_posicion(lista, 0) && lista_quitar_de_posicion(lista, 0) && lista_quitar_de_posicion(lista, 0)) {
			if (lista_elemento_en_posicion(lista, 0) == NULL) {
				printf("✓ Se quitaron correctamente varios elementos\n");
			} else {
				printf("✗ Se quitaron correctamente varios elementos\n");
				__pa2m_cantidad_de_pruebas_fallidas++;
			}
		} else {
			printf("✗ Se quitaron correctamente varios elementos\n");
			__pa2m_cantidad_de_pruebas_fallidas++;
		}
	} else {
		printf("✗ Se quitaron correctamente varios elementos\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_obtener_lista_nula()
{
	lista_t *lista = NULL;
	if (!lista_elemento_en_posicion(lista, 0)) {
		printf("✓ No se puede obtener un elemento de una lista nula\n");
	} else {
		printf("✗ No se deberia poder obtener un elemento de una lista nula\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_obtener_lista_vacia()
{
	lista_t *lista = lista_crear();
	if (!lista_elemento_en_posicion(lista, 0)) {
		printf("✓ No se puede obtener un elemento de una lista vacia\n");
	} else {
		printf("✗ No se deberia poder obtener un elemento de una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_obtener_de_posicion_inexistente()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && (lista_elemento_en_posicion(lista, 2) == NULL)) {
		printf("✓ Obtener un elemento de una posicion inexistente devuelve NULL\n");
	} else {
		printf("✗ Obtener un elemento de una posicion inexistente devuelve NULL\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_obtener_de_posicion()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && (lista_elemento_en_posicion(lista, 1) == elemento_2)) {
		printf("✓ Obtener un elemento de una posicion devuelve el elemento correcto\n");
	} else {
		printf("✗ Obtener un elemento de una posicion devuelve el elemento correcto\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

int comparador(void *elemento, void *contexto)
{
	return (strcmp(elemento, contexto) == 0);
}

void prueba_lista_buscar_lista_nula()
{
	lista_t *lista = NULL;
	char *elemento = "hola";
	
	if (!lista_buscar_elemento(lista, comparador, elemento)) {
		printf("✓ No se puede buscar un elemento en una lista nula\n");
	} else {
		printf("✗ No se deberia poder buscar un elemento en una lista nula\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_buscar_comparador_nulo()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	
	if (!lista_buscar_elemento(lista, NULL, elemento)) {
		printf("✓ No se puede buscar un elemento en una lista con un comparador nulo\n");
	} else {
		printf("✗ No se deberia poder buscar un elemento en una lista con un comparador nulo\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_buscar_contexto_nulo() {
	lista_t *lista = lista_crear();
	char *elemento = NULL;
	
	if (!lista_buscar_elemento(lista, comparador, elemento)) {
		printf("✓ No se puede buscar un elemento en una lista con un contexto nulo\n");
	} else {
		printf("✗ No se deberia poder buscar un elemento en una lista con un contexto nulo\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_buscar_elemento()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_buscar_elemento(lista, comparador, elemento)) {
		printf("✓ Se encontro el elemento en la lista\n");
	} else {
		printf("✗ Se encontro el elemento en la lista\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_buscar_lista_vacia()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	
	if (!lista_buscar_elemento(lista, comparador, elemento)) {
		printf("✓ No se puede buscar un elemento en una lista vacia\n");
	} else {
		printf("✗ No se deberia poder buscar un elemento en una lista vacia\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

void prueba_lista_buscar_elemento_duplicado()
{
	lista_t *lista = lista_crear();
	char *elemento = "hola";
	char *elemento_2 = "chau";
	
	if (lista_insertar(lista, elemento) && lista_insertar(lista, elemento_2) && lista_insertar(lista, elemento) && lista_buscar_elemento(lista, comparador, elemento)) {
		printf("✓ Se encontro el elemento duplicado en la lista\n");
	} else {
		printf("✗ Se encontro el elemento duplicado en la lista\n");
		__pa2m_cantidad_de_pruebas_fallidas++;
	}	
	lista_destruir(lista);
	__pa2m_cantidad_de_pruebas_corridas++;
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== Creacion ========================");

	prueba_lista_crear();

	pa2m_nuevo_grupo(
		"\n======================== Insercion ========================");

	prueba_lista_insertar_lista_nula();
	prueba_lista_insertar_lista_vacia();
	prueba_lista_insertar_lista_con_elementos();
	prueba_lista_insertar_elemento_null();

	prueba_lista_insertar_en_posicion_lista_nula();
	prueba_lista_insertar_en_posicion_lista_vacia();
	prueba_lista_insertar_en_posicion_lista_con_elementos();
	prueba_lista_insertar_en_posicion_inexistente();

	prueba_lista_insertar_elemento_nulo_lista_valida();
	prueba_lista_insertar_varios_elementos();
	prueba_lista_insertar_elemento_repetido();

	pa2m_nuevo_grupo(
		"\n======================== Eliminacion ========================");

	prueba_lista_quitar_lista_nula();
	prueba_lista_quitar_lista_vacia();
	prueba_lista_quitar_lista_con_elementos();

	prueba_lista_quitar_en_posicion_lista_nula();
	prueba_lista_quitar_en_posicion_lista_vacia();
	prueba_lista_quitar_en_posicion_lista_con_elementos();
	prueba_lista_quitar_multiples_elementos();
	
	pa2m_nuevo_grupo(
		"\n======================== Obtencion ========================");

	prueba_lista_obtener_lista_nula();
	prueba_lista_obtener_lista_vacia();
	prueba_lista_obtener_de_posicion_inexistente();
	prueba_lista_obtener_de_posicion();

	pa2m_nuevo_grupo(
		"\n======================== Busqueda ========================");

	prueba_lista_buscar_lista_nula();
	prueba_lista_buscar_comparador_nulo();
	prueba_lista_buscar_contexto_nulo();
	prueba_lista_buscar_lista_vacia();
	prueba_lista_buscar_elemento();
	prueba_lista_buscar_elemento_duplicado();

	pa2m_nuevo_grupo(
		"\n======================== Cantidad de elementos y vacia ========================");
	
	
	

	return pa2m_mostrar_reporte();
}
