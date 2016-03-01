#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "evaluador_RPN.h"
//g++ -g main_RPN.cpp evaluador_RPN.cpp dll_t.cpp  dll_node_t.cpp dll_int_node_t.cpp  stack_int_t.cpp 

using namespace std;

int main(void)
{
    evaluador_RPN_t calculadora;
    
     char cadena[] = "10 10 + 5 * 10 - 9 / 6 %"; 
     cout << cadena << endl;
     cout << " El resultado es: ";
     cout << calculadora.eval(cadena) << endl;
}
 