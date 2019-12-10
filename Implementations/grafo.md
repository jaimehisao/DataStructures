# Grafos

## Terminologia de Grafos
Adyacencia: Los Nodos conectados.

Grafo No Dirigido: Los arcos del grafo no tienen ninguna direccion particular, es decir, bidireccionales.
A a B es igual que B a A

Grafo Dirigido (Digrafo): Estos grafos tienen direccion. Entonces A -> B != B -> A

Grafo Ponderado: Los arcos en el grafo tienen asociado un valor (peso) Eg. Costo, distancia

Ciclo: Una trayectoria en la cual el nodo de inicio y el de terminacion son iguales.

Ciclo Hamiltoniano: Ciclo que empieza y termina en el mismo nodo pero no repiten los nodos. Tiene que pasar por todos los nodos para que sea un Ciclo Hamiltoniano

Ciclo Euleriano: Ciclo en el cual tienes que pasar por todos los ARCOS sin repetir. Si se pueden repetir nodos, pero los arcos no.

Para que un grafo pueda ser un arbol, tiene que tener nodos-1 arcos. Y luego validas si no tiene ciclos dentro del grafo.

Operaciones:
    Agregar Nodo
    Quitar Nodo
    Agregar Arco
    Quitar Arco
    Recorrer el Grafo

Aplicaciones Tipicas de un Grafo:
    Hay un camino entre dos nodos
    Costo minimo de conexion entre nodos
    Ruta mas optima entre dos puntos

Como representar un Grafo (formas más comunes):
    Matriz de Adyacencias
        Si el grafo es no dirigido, la matriz es simetrica entonces se desperdicia mucho espacio.
        Si es dirigido entonces si ocupa toda la matriz.
        Ventajas:
            Las operaciones son muy sencillas de implementar
        Desventaja:
            Se requiere conocer con anticipacion la cantidad de elementos que conformaran el grafo.
    Lista de Adyacencias
        Ventaja:
            No se nececita conocer el tamaño desde antes.
        Desventajas:
    Lista de Arcos
        Es la mas compleja de implementar...
        Graficamente los Nodos Vertice y los elementos de la lista de Arcos se verian como:
            A) X(apuntador al siguiente arco donde X es origen)(apunta al siguiente arco donde X es destino)(apunta al siguiente nodo vertice)
            B) X-Y (apunta al siguiente arco donde X es origen)(apunta al siguiente arco donde Y es destino)
        Ventajas:
            A) Representacion muy eficiente
        Desventajas:
            A) Bastante compleja de imlementar
            B) Requiere mas espacio de memoria debido al manejo de apuntadores.

Recorridos de Grafos
    Los recorridos más utilizados (Recorrer es visitar todos los nodos)
        Breadth First:
            A) A partir de un Nodo de Inicio este algoritmo visita un nodo y luego a todos sus vecinos,
            B) El orden en el que visita a los vecinos depende del orden de almacenamiento, segun la representacion que se esta utilizando.
            c) Este algoritmo usa una fila auxiliar, hay que llevar control si ya se visito o no. Se cambia el estado al meterlo a la fila
        Depth Search:
            A) Se empieza con el nodo de 
            B) Se usa una pila auxiliar.
            C) Se cambia el estado de procesado o no al sacarlo de la pila.