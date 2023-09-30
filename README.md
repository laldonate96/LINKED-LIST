<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# NOMBRE TP/TDA

## Repositorio de Lucas Aldonate - 100030 - laldonate@fi.uba.ar

- Para compilar:

```bash
make pruebas_chanutron
```

- Para ejecutar:

```bash
./pruebas_chanutron
```

- Para ejecutar con valgrind:
```bash
make valgrind-chanutron
```
---
##  Funcionamiento

Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluír **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

---

## Respuestas a las preguntas teóricas

Respuesta 1:

Pila:

La pila es una estructura de datos en donde elementos pueden ser añadidos o eliminados por el final de esta misma. Es decir,
los elementos pueden ser "apilados" o "desapilados". A continuación un diagrama de una implementación de pila con nodos
simplemente enlazados:

<div align="center">
<img width="70%" src="img/Pile.svg">
</div>

Cola:

La cola al igual que la pila es una estructura de datos. Lo que las diferencia, es que en el caso de la cola los elementos
se agregan por el inicio y se quitan por el final. En este caso los elementos se "encolan" y se "desencolan". A continuación,
un diagrama explicando el funcionamientoÑ

<div align="center">
<img width="70%" src="img/Cola.svg">
</div>

Lista:

Finalmente, la lista es otra estructura de datos, que combina las funcionalidades de la pila y la cola. Podríamos entonces decir 
que la pila y la cola son casos particulares de una lista. La diferencia principal, es que en la lista se puede insertar y quitar
elementos de posiciones que no necesariamente sean el inicio o el final.

Respuesta 2:

Lista simplemente enlazada:

- Inicio

    - Insertar: tiene complejidad O(1), ya que con el puntero al nodo inicial, simplemente se agrega el nuevo nodo y su siguiente 
    apuntará al anterior nodo inicial.
    - Obtener: tambien complejidad O(1), simplemente se muestra el elemento del nodo incial.
    - Elimiar: como en las dos anteriores, complejidad O(1). Se elimina el nodo, haciendo como paso previo que el nodo contiguo
    pase a ser el nodo inicial (al revés que en insertar al inicio).

- Medio/Final

    - Insertar: insertar al final tiene complejidad O(n), ya que se deben recorrer todos los nodos hasta llegar al último. En caso 
    de utilizar un puntero al nodo final (como es el caso de la implementación de este TP), la complejidad pasa a ser O(1). En el 
    caso de insertar al medio, siempre será O(n).
    - Obtener: lo mismo que para insertar.
    - Eliminar: lo mismo que en las dos anteriores.

Lista doblemente enlazada:

Posee las mismas complejidades que la lista simplemente enlazada con una salvedad. Debido a que es posible recorrer la lista en 
ambos sentidos, las operaciones del medio poseen una complejidad O(n/2).

Vector dinámicoÑ

-Inicio

    - Insertar: tiene complejidad O(n), debido a que al insertar al inicio conlleva el desplazamiento de todos los elementos 
    hacia la derecha. En el peor caso la complejidad puede ser O(n^2), debido a que si al insertar al inicio también hay que 
    hacer un redimensionamiento