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

        pila<T> pila_;
        
    public: 

	    mycalc(void);
	    ~mycalc(void);
	    T calc(istream& expresion);
};


template <class T>
mycalc<T>::mycalc(void):
pila_()
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
            pila_.push(operando);
    }
    
    else
    {
        expresion >> op;
        
        switch (op)
        {
        case '+':
    
            op1 =  pila_.pop();
            op2 =  pila_.pop();
            aux = op1 + op2;
             pila_.push(aux);
        break;
        
        case '-':
            op1 = pila_.pop();
            op2 = pila_.pop();
            aux = op2 - op1;
            pila_.push(aux);
           
        break;
        
        case '/':
            op1 = pila_.pop();
            op2 = pila_.pop();
            aux = op2 / op1;
            pila_.push(aux);
           
         break; 
         
        case '*':
            op1 = pila_.pop();
            op2 = pila_.pop();
            pila_.push(op1 * op2);
        break; 
        
        }
    }
    
    
    expresion.ignore(1);
  
   }
 return pila_.pop(); 
}
