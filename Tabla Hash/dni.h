#pragma once
#include <iostream>

using namespace std;

class DNI
{
    private:
        
        int num;	                                                //DNI

    public:
        
        DNI(void);                                                  //Constructor por defecto
        DNI(int n);		                                            //Constructor
        ~DNI(void);		                                            //Destructor

        int set_dni(int n);                                         //Asgina valor a un DNI
        int get_dni(void) const;                                    //Devuelve el valor del DNI
        
        operator unsigned int() const {return num;}                 //Realiza la conversión del tipo DNI a unsigned int
        
        DNI& operator=(const DNI&);                                 //Iguala el DNI a un objeto DNI
        DNI& operator=(const int&);                                 //Iguala el DNI a un número entero
        friend bool operator==(const DNI&, const DNI&);	            //operador de comparación igualdad con un objeto DNI
        friend bool operator==(const DNI&, const int&);	            //operador de comparación igualdad con un entero
        friend bool operator!=(const DNI&, const DNI&);	            //operador de comparación distinto con un objeto DNI
        friend bool operator!=(const DNI&, const int&);	            //operador de comparación distinto con un entero
        friend bool operator>(const DNI&, const int&);	            //operador de comparación mayor que con un entero
        
        friend int operator+(const DNI&, const DNI&);               //Operador de suma con un objeto DNI
        friend int operator/(const DNI&, const DNI&);               //Operador de división con un objeto DNI
        friend int operator/(const DNI&, const int&);               //Operador de división con un entero
        friend int operator%(const DNI&, const DNI&);               //Operador de módulo con un objeto DNI
        friend int operator%(const DNI&, const int&);               //Operador de módulo con un entero
        friend ostream& operator<<(ostream& os, const DNI& a);      //Sobrecarga del operador de flujo salida
};