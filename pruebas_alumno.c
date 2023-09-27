#include "pa2m.h"
#include "src/lista.h"

void prueba_simple()
{
	lista_t *lista = lista_crear();
	if (lista) {
		printf("Se creo la lista\n");
		lista_destruir(lista);
	} else
		printf("No se creo la lista\n");
	return;
}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");
	prueba_simple();

	return pa2m_mostrar_reporte();
}
