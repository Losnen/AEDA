#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include "pila.hpp"


using namespace std;

template <class T>
class calculadora 
{

  private:
   	pila<T> pila_;
  public: 
	
	calculadora(void);
	~calculadora(void);
    T eval(istream& expresion);
    bool isoperador(basic_istream<char>::int_type car);
    bool iscomplex(basic_istream<char>::int_type car);
    bool isrational(basic_istream<char>::int_type car);




};


template <class T>
calculadora<T>::calculadora(void):
pila_()
{}

template <class T>
calculadora<T>::~calculadora(void)
{}

template <class T>
T calculadora<T>::eval(istream& expresion)
{
 
   
  T aux;
   T op1;
   T op2;
   T operando; 
   T resultado;
   char op; 
   char parentesis, comillas;

   while (expresion.peek() != '=')
   {


    if(isdigit(expresion.peek()))
    {     
         expresion >> operando;
         pila_.push(operando);
    }
    
    else if((iscomplex(expresion.peek())) && (!isdigit(expresion.peek())))
    {
        expresion >> parentesis;
 
    }
    
    else if((isrational(expresion.peek())) && (!isdigit(expresion.peek())))
    {
        expresion >> comillas;
 
    }
  
    else if(isblank(expresion.peek()))
    {
        expresion.ignore(1);
    }
    
    else
    {
            
            expresion >> op;
            
            if((isoperador(expresion.peek())) && (!isdigit(expresion.peek())))
            {
                    expresion >> op;
                 cout << "Error al escribir  en formato RPN " << endl; 
                 exit (EXIT_FAILURE);
        
            }
          
           else
            {
                switch (op)
                {
                    case '+':
                         op1 = pila_.pop();
                        op2 = pila_.pop();
                        aux = op1 + op2;
                        pila_.push(aux);
                     
                    break;
        
                    case '-':
                    
                        if (isdigit(expresion.peek()))
                        {
                           T negativo = -1;
                            expresion >> operando;
                            operando = operando * negativo; 
                            pila_.push(operando);
                        }
                        
                        else
                        {
                        op1 = pila_.pop();
                        op2 = pila_.pop();
                        pila_.push(op2 - op1);
                        }
                        
                     break;
        
                    case '/':
                        op1 = pila_.pop();
                        op2 = pila_.pop();
                        pila_.push(op2 / op1);
           
                    break; 
         
                    case '*':
                        op1 = pila_.pop();
                        op2 = pila_.pop();
                        pila_.push(op1 * op2);
        
                    break; 
        
                }
             }
        
    }
    
    
  
   }
    
   
   
   
   cout << endl; 
   
    return pila_.pop();
    
    
}

template <class T>
bool calculadora<T>::isoperador(basic_istream<char>::int_type car)
{
    
  
    
    if (( car == ' ') || ( car == ')' ) || ( car == '('))
    {
        return false;
     
    }   
    
    
    if ( (car == '+')  ||    (car == '-') || (car == '*') || (car == '/')  )
    {
        return true;
     
    }   
}


template <class T>
bool calculadora<T>::iscomplex(basic_istream<char>::int_type car)
{
    
  
    
    if (( car == ')' ) || ( car == '('))
        return true;
    else    
        return false;
}


template <class T>
bool calculadora<T>::isrational(basic_istream<char>::int_type car)
{
    
  
    
    if ( car == '"' )
        return true;
    else    
        return false;
}