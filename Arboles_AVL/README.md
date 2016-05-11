#Práctica 7 AEDA: Árboles AVL
##Samuel Ramos Barroso

###Enunciado
Desarrollar en lenguaje C++ la plantilla de clases para el nodo AVL (nodoAVL<Clase>) y para el tipo abstracto de dato árbol AVL (AVL<Clave>), implementando las operaciones de búsqueda, inserción y eliminación de una clave X en el AVL.

En la práctica se utilizará como valores de clave el tipo DNI, definido en el enunciado de la práctica 4.

Se realizan dos programas para ejecutar el código implementado:

* Modo demostración: El programa crea un AVL vacío, y presenta un menú con las siguientes opciones:

```
[0] Salir
[1] Insertar clave
[2] Eliminar clave
```

Tras cada operación se mostrará el árbol resultante mediante un recorrido por niveles. En cada nivel se muestran los nodos de izquierda a derecha. El subárbol vacío se visualiza con [.]. En este modo se trabajará con árboles de tamaño limitado para permitir una correcta visualización.

* Modo estadísticas: El programa cuenta el número de comparaciones necesarias para buscar e insertar claves en el árbol.

El programa solicita los parámetros del experimento:

* N (int): Tamaño del árbol (número de nodos del árbol)
* P (int): Número de pruebas

Se crea un banco de pruebas con valores de clave tipo DNI generados aleatoriamente. Se genera un árbol AVL y se insertan N claves extraídas del banco de pruebas sin repetir los valores de clave insertados.

Se inicializan los contadores para medir los valores mínimo, medio y máximo de comparaciones de claves al realizar P búsquedas de valores de claves ya introducidas. A continuación, se repite la medición anterior al realizar P búsquedas de claves que no fueron previamente introducidas en el árbol.

Al finalizar el experimento se presentarán por pantalla los datos de entrada y los resultados de ambos experimentos. 

<table>
    <tr>
        <td><strong>-----</strong></td>
        <td><strong>N</strong></td>
        <td><strong>P</strong></td>
        <td><strong>Minimo</strong></td>
        <td><strong>Medio</strong></td>
        <td><strong>Máximo</strong></td>
    </tr>
    <tr>
        <td>Búsqueda</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
    </tr>
    <tr>
        <td>Incersión</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
    </tr>
</table>
