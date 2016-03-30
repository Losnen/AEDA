#pragma once
#include <iostream>
#include "reales.h"
#include "numero.h"
class racional;
class complejo;

using namespace std;

class entero: public numero_t
{
    private:
        int numero_;
     
    public:
  
        entero(void);
        entero(int n);
        ~entero(void);
        int get_numero(void) const;
          
        entero& operator=(const entero&);
        entero& operator=(const int& n);
        
        virtual const entero toEntero(void) const;
        virtual const real toReal(void) const;
        virtual const racional toRacional(void) const;
        virtual const complejo toComplejo(void) const;
        virtual ostream& toStream(ostream& sout) const;
        virtual istream& fromStream(istream& sin);
          
        friend entero operator+(const entero&, const entero&);
        friend entero operator-(const entero&, const entero&);
        friend entero operator*(const entero&, const entero&);
        friend entero operator/(const entero&, const entero&);
        friend entero negar(const entero&);
        friend bool operator==(const entero&, const entero&);
        friend bool operator!=(const entero&, const entero&);
        friend bool operator<(const entero&, const entero&);
        friend bool operator>(const entero&, const entero&);
        friend bool operator<=(const entero&, const entero&);
        friend bool operator>=(const entero&, const entero&);
          
        friend ostream& operator<<(ostream&, const entero&);
        friend istream& operator>>(istream&,entero&);
};