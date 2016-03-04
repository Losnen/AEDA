#pragma once
#include <iostream>

using namespace std;

class entero 
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
          
        friend entero operator+(const entero&, const entero&);
        friend entero operator-(const entero&, const entero&);
        friend entero operator*(const entero&, const entero&);
        friend entero operator/(const entero&, const entero&);
          
        friend bool operator==(const entero&, const entero&);
        friend bool operator!=(const entero&, const entero&);
        friend bool operator<(const entero&, const entero&);
        friend bool operator>(const entero&, const entero&);
        friend bool operator<=(const entero&, const entero&);
        friend bool operator>=(const entero&, const entero&);
          
        friend ostream& operator<<(ostream&, const entero&);
};