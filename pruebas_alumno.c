#include "pa2m.h"
#include "src/lista.h"

void prueba_simple()
{
	lista_t *lista = lista_crear();

	char a = 'a', b = 'b', c = 'c', d = 'd', w = 'w';

	lista_insertar(lista, &a);
	lista_insertar(lista, &b);
	lista_insertar(lista, &c);
	lista_insertar(lista, &d);

	lista_iterador_t *iterador = lista_iterador_crear(lista);

	for()

}

int main()
{
	pa2m_nuevo_grupo(
		"\n======================== XXX ========================");
	prueba_simple();

	return pa2m_mostrar_reporte();
}
