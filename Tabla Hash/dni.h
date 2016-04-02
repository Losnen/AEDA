#pragma once
#include <iostream>

using namespace std;

class DNI
{
    private:
        
        int num;	                                                 //DNI

    public:
        
        DNI(void);                                                   //Constructor por defecto
        DNI(int n);		                                             //Constructor
        ~DNI(void);		                                             //Destructor

        int set_dni(int n);                                          //Asgina valor a un DNI
        int get_dni(void) const;                                     //Devuelve el valor del DNI
        
        operator unsigned int() const { return num;}
        
        DNI& operator=(const DNI&);                                 //Iguala el DNI a un objeto DNI
        DNI& operator=(const int&);                                 //Iguala el DNI a un número entero
        friend bool operator==(const DNI&, const DNI&);	
        friend bool operator==(const DNI&, const int&);	
        friend bool operator!=(const DNI&, const DNI&);	//operador de comparación
        friend bool operator!=(const DNI&, const int&);	//operador de comparación
        friend bool operator>(const DNI&, const int&);	//operador de comparación
        
        friend int operator+(const DNI&, const DNI&);
        friend int operator/(const DNI&, const DNI&);
        friend int operator/(const DNI&, const int&);
        friend int operator%(const DNI&, const DNI&);
        friend int operator%(const DNI&, const int&);
        friend ostream& operator<<(ostream& os, const DNI& a);
};