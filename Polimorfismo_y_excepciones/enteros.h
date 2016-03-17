#pragma once
#include <iostream>
#include "numero.h"

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