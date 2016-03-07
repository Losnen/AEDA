#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include "pila.hpp"


using namespace std;

template <class TDATO>
class calculadora 
{

  private:
   	pila<TDATO> pila_;
  public: 
	
	calculadora(void);
	~calculadora(void);
    TDATO eval(istream& expresion);
    bool isoperador(basic_istream<char>::int_type car);
    bool iscomplex(basic_istream<char>::int_type car);
    bool isrational(basic_istream<char>::int_type car);




};


template <class TDATO>
calculadora<TDATO>::calculadora(void):
pila_()
{}

template <class TDATO>
calculadora<TDATO>::~calculadora(void)
{}

template <class TDATO>
TDATO calculadora<TDATO>::eval(istream& expresion)
{
 
   
  TDATO aux;
   TDATO op1;
   TDATO op2;
   TDATO operando; 
   TDATO resultado;
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
                           TDATO negativo = -1;
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

template <class TDATO>
bool calculadora<TDATO>::isoperador(basic_istream<char>::int_type car)
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


template <class TDATO>
bool calculadora<TDATO>::iscomplex(basic_istream<char>::int_type car)
{
    
  
    
    if (( car == ')' ) || ( car == '('))
        return true;
    else    
        return false;
}


template <class TDATO>
bool calculadora<TDATO>::isrational(basic_istream<char>::int_type car)
{
    
  
    
    if ( car == '"' )
        return true;
    else    
        return false;
}