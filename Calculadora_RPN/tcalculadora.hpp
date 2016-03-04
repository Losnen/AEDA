#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <cctype> 
#include "tpila.hpp"

using namespace std;

template <class T>
class mycalc
{
    private:

        mypila<T> pila;
        
    public: 

	    mycalc(void);
	    ~mycalc(void);
	    T calc(istream& expresion);
	    bool es_operando(char* expres);
};


template <class T>
mycalc<T>::mycalc(void):
pila()
{}

template <class T>
mycalc<T>::~mycalc(void)
{}

template <class T>
T mycalc<T>::calc(istream& expresion)
{
   T aux;
   T op1;
   T op2;
   T operando; 
   T resultado;
   char op; 
   

   while (expresion.peek() != '=')
   {

    if(isdigit(expresion.peek()))
    {        
        expresion >> operando;
            pila.push(operando);
    }
    
    else
    {
        expresion >> op;
        
        switch (op)
        {
        case '+':
    
            op1 = pila.pop();
            op2 = pila.pop();
            aux = op1 + op2;
            pila.push(aux);
        break;
        
        case '-':
            op1 = pila.pop();
            op2 = pila.pop();
            aux = op2 - op1;
            pila.push(aux);
           
        break;
        
        case '/':
            op1 = pila.pop();
            op2 = pila.pop();
            aux = op2 / op1;
            pila.push(aux);
           
         break; 
         
        case '*':
            op1 = pila.pop();
            op2 = pila.pop();
            aux = op1 * op2;
            pila.push(aux);
        break; 
        
        }
    }
    
    
    expresion.ignore(1);
  
   }
 return pila.pop(); 
}

template <class T>
bool mycalc<T>::es_operando(char* expres)
{
	if( ((*expres)>= '0') && ((*expres)<= '9') )
	    return true;
	else
	    return false;
}