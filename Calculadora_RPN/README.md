##Práctica 2: Calculadora de expresiones en notación postfija

Implementar en lenguaje C++ una calculadora que reciba como entrada una expresión aritmética en
notación postfija, la evalúe y retorne su resultado.
En la notación postfija, también denominada notación polaca inversa [1], los operandos de la expresión se introducen primero y a continuación se introduce el operador. Esta notación tiene la ventaja frente a la notación infija, la notación tradicional para las expresiones aritméticas, de no requerir el uso de paréntesis para indicar el orden de las operaciones. La siguiente tabla muestra algunas expresiones aritméticas con datos enteros expresadas en las notaciones infija y postfija.

<table >
    <tr>
      <td>Notacion Fija</td>
      <td>Notacion Infija</td>
    </tr>
    <tr>
      <td>3+2</td>
      <td> 3 2 + </td>
    </tr>
    <tr>
      <td>3+2*5*</td>
      <td> 3 2 5 + * </td>
    </tr>
    <tr>
      <td>(3+2)*(5-7)</td>
      <td>  3 2 + 5 7 - *  </td>

</table>


La evaluación de una expresión aritmética en notación postfija se realiza utilizando una pila para almacenar los operandos. Cuando se lee un operando de la expresión de entrada se guarda en la pila; mientras que si lo que se lee de la expresión de entrada es un operador se recuperan los operandos necesarios de la pila, se evalúa la operación y se guarda el resultado en la pila. El terminar de procesar la expresión de entrada el resultado de la misma queda en el top de la pila

<table >
    <tr>
      <td>Expresión extraida</td>
      <td>Dato leído</td>
      <td>Dato Evaluado</td>
      <td>Pila</td>
    </tr>
    <tr>
      <td>3 2 + 5 7 - *</td>
      <td> -  </td>
      <td> -  </td>
      <td> [vacía] </td>
    </tr>
    <tr>
      <td>2 + 5 7 - *</td>
      <td> 3  </td>
      <td> -  </td>
      <td> [3] </td>
    </tr>
    <tr>
      <td>+ 5 7 - * </td>
      <td> 2  </td>
      <td> -  </td>
      <td> [3][2] </td>
    </tr>
    <tr>
      <td> 5 7 - * </td>
      <td>  +   </td>
      <td> -   </td>
      <td>  [5] </td>
    </tr>
    <tr>
      <td> 7 - *  </td>
      <td>  5   </td>
      <td> -  </td>
      <td> [5][5] </td>
    </tr>
    <tr>
      <td>  - *  </td>
      <td>  7   </td>
      <td> 5  </td>
      <td> [5][5][7] </td>
    </tr>
     <tr>
      <td>   *  </td>
      <td>  7   </td>
      <td>  -   </td>
      <td>  [5][-2] </td>
    </tr>
   </tr>
     <tr>
      <td>   -  </td>
      <td>  *   </td>
      <td>  5*(-2)=-10   </td>
      <td>  [-10] </td>
    </tr>
</table>

Se hará un Template con la Calculadora.