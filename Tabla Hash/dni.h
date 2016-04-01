#pragma once
#include <iostream>

using namespace std;

class DNI
{
    private:
        
        int num;	                    //DNI

    public:
        
        DNI(void);                      //Constructor por defecto
        DNI(int n);		                //Constructor
        ~DNI(void);		                //Destructor

        int set_dni(int n);             //Asgina valor a un DNI
        int get_dni(void) const;        //Devuelve el valor del DNI
        
        DNI& operator=(const DNI&);     //Iguala el DNI a un objeto DNI
        DNI& operator=(const int&);     //Iguala el DNI a un número entero
        friend ostream& operator<<(ostream& os, const DNI& a);
};