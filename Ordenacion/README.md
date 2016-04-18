#Algoritmos y Estructuras de Datos Avanzadas
##Práctica 5: Ordenación

###Objetivo

Desarrollar en lenguaje C++ diferentes algoritmos de ordenación y realizar un análisis de rendimiento de los algoritmos implementados.

###Enunciado

Se deben implementar en lenguaje C++ los siguientes algoritmos de ordenación:
* Inserción.
* Burbuja.
* Por incrementos decrecientes (ShellSort), debe permitir seleccionar la constante de reducción alfa, siendo 0 < alpha < 1.
* QuickSort.
* MergeSort.

La implementación de cada método de ordenación se realizará mediante una plantilla de función en la que se especificará el tipo de los elementos a ordenar, y la función recibirá como parámetros la secuencia a ordenar y su tamaño: Funcion(secuencia, tamaño). Las secuencias a ordenar se generarán de forma aleatoria, y estarán formadas por valores de claves del tipo DNI (clase definida en el enunciado de la práctica 4). La clase DNI tendrá sobrecargadas todas las operaciones de comparación necesarias para aplicar los algoritmos de ordenación.

Se deben realizar dos programas para ejecutar el código implementado:

Modo demostración: Se utilizan secuencias pequeñas (de hasta 25 elementos) para comprobar el funcionamiento de un algoritmo determinado.

El programa solicita los parámetros necesarios:
* N: Tamaño de la secuencia a ordenar
* Algoritmo a ejecutar

En la ejecución, al pulsar una tecla se mostrará el resultado de cada comparación, destacando los elementos del vector que son comparados y cómo queda la secuencia tras la comparación y la acción correspondiente.

Modo estadísticas: El programa cuenta el número de comparaciones necesarias para ordenar los elementos en cada uno de los algoritmos.

El programa solicita los parámetros del experimento:
* N: Tamaño de la secuencia a ordenar
* P (pruebas). Número de veces que se repite la ejecución de cada método.

Para cada uno de los algoritmos se genera un banco de pruebas con P secuencias de N elementos y se ordena cada secuencia contando el número de comparaciones realizadas y actualizando los valores mínimo, máximo y acumulado.

Al finalizar el experimento se presentan los valores mínimo, máximo y medio del número de comparaciones de claves contabilizados, con el siguiente formato de salida:

###Numero de Comparaciones

<table>
    <tr>
        <td><strong>-----</strong></td>
        <td><strong>Minimo</strong></td>
        <td><strong>Medio</strong></td>
        <td><strong>Máximo</strong></td>
    </tr>
    <tr>
        <td>Método 1</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
    </tr>
    <tr>
        <td>Método 2</td>
        <td>xxxx</td>
        <td>xxxx</td>
        <td>xxxx</td>
    </tr>
</table>

De forma opcional se puede utilizar el programa desarrollado para realizar un estudio de la variación del comportamiento en los métodos de ordenación cuando se incrementa el tamaño de la secuencia a ordenar. Además, también se pueden implementar el resto de algoritmos de ordenación vistos en clase.
