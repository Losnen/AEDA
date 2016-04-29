#Práctica 6 AEDA: Árboles Binarios
##Samuel Ramos Barroso

###Objetivo
Desarrollar en lenguaje C++ una clase genérica que implemente un árbol binario de búsqueda.
Realizar un análisis de rendimiento del árbol binario de búsqueda al variar el número de nodos del árbol.

3. Enunciado
Desarrollar en lenguaje C++ la plantilla de clases para el nodo binario de búsqueda nodoBB<Clase> y para el tipo abstracto de dato árbol binario de búsqueda ABB<Clave>, implementando las operaciones de búsqueda, inserción y eliminación de una clave X en el ABB.

En la práctica se utilizará como valores de clave el tipo DNI, definido en el enunciado de la práctica 4.

Se deben realizar dos programas para ejecutar el código implementado:
* Modo demostración: El programa crea un árbol binario de búsqueda vacío, y presenta un menú con las siguientes opciones:

```
[0] Salir
[1] Insertar clave
[2] Eliminar clave
```
Tras cada operación se mostrará el árbol resultante mediante un recorrido por niveles. En cada nivel se muestran los nodos de izquierda a derecha. El subárbol vacío se visualiza con [.].

En este modo se trabajará con árboles de tamaño limitado para permitir una correcta visualización.

Ejemplo de visualización del árbol en el modo demostración:

######Árbol vacío

Nivel 0: [.]

######Insertar: 30

Nivel 0: [30]

Nivel 1: [.] [.]

######Insertar: 25

Nivel 0: [30]

Nivel 1: [25] [.]

######Insertar: 15

Nivel 0: [30]

Nivel 1: [25] [.]

Nivel 2: [15] [.]

Nivel 3: [.] [.]

######Insertar: 40
Nivel 0: [30]

Nivel 1: [25] [40]

Nivel 2: [15] [.] [.] [.]

Nivel 3: [.] [.]

######Eliminar: 15 (Caso trivial, nodo sin hijos)

Nivel 0: [30]

Nivel 1: [25] [40]

Nivel 2: [.] [.] [.] [.]

######Eliminar: 30 (Cambiando la clave borrada por su sucesor)

Nivel 0: [25]

Nivel 1: [.] [40]

Nivel 2: [.] [.]

* Modo estadísticas: El programa cuenta el número de comparaciones necesarias para buscar e insertar claves en el árbol.

El programa solicita los parámetros del experimento:

* N (int): Tamaño del árbol (número de nodos del árbol)

* P (int): Número de pruebas

Se crea un banco de pruebas con valores de clave tipo DNI generados aleatoriamente.

Se genera un árbol binario de búsqueda, ABB, y se insertan N claves extraídas del banco de pruebas sin repetir los valores de clave insertados.

Se inicializan los contadores para medir los valores mínimo, medio y máximo de  comparaciones de claves al realizar las P búsquedas de valores de claves ya introducidas. A continuación, se repite la medición anterior al realizar P búsquedas de claves que no fueron previamente introducidas en el árbol.

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
