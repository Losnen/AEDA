#include <iostream>
#include <cstring>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include "calculadora.hpp"
#include <cctype>       // std::isdigit
#include "enteros.h"
#include "reales.h"
#include "complejos.h"
#include "racionales.h"
using namespace std;


bool analizar_cadena(string str)
{
    
    int contador = 0;  
    
    if (str.find_last_of('=') == std::string::npos)
     {
        cout << "Error al escribir  en formato RPN" << endl; 
        return false;
     }  
     
     else
     {
        for(int i = 0; i<= str.size(); i++)
        {   
                if (str[i] == '=')
                {
                        contador++;
                }
        }
     }
    
    if (contador > 1)
    {
             cout << "Error al escribir  en formato RPN" << endl; 
                return false; 
        
    }
    
    return true; 
    
}

int main(void)
{
    
     string str; 
     cout << " Algoritmos y Estructuras de Datos Avanzada - Practica 2" << endl; 
     cout << "Introduce la expresion a calcular: " ; 
     
     getline(cin,str);
     
    istringstream expresion(str);
    bool correcto = analizar_cadena(str);
    size_t found1 = str.find(".");
    if(correcto == true)
    {
         if ( (((str[0] == '-') && isdigit(str[1])) || isdigit(str[0])) && ((found1 == string::npos)) )
         {
             entero resultado;
             calculadora<entero> calculadora;
             resultado = calculadora.eval(expresion);
             cout << "El resultado es:" << resultado << endl; 
         }
        else if ( (((str[0] == '-') && isdigit(str[1])) || isdigit(str[0])) && ((found1 != string::npos)) )
         {
             real resultado;
             calculadora<real> calculadora;
             resultado = calculadora.eval(expresion);
             cout << "El resultado es:" << resultado << endl; 
         }
         
         else if ( str[0] == '(')
        {
            complejo resultado; 
             calculadora<complejo> calculadora;
             resultado = calculadora.eval(expresion);
             cout << "El resultado es:" << resultado << endl; 
        }
        
         else if ( str[0] == '"')
        {
            racional resultado; 
             calculadora<racional> calculadora;
             resultado = calculadora.eval(expresion);
             cout << "El resultado es:" << resultado << endl; 
        }
        
        
        else
            exit (EXIT_FAILURE);
        
    }
    
    else
        exit (EXIT_FAILURE);

    
    
}

 



 

