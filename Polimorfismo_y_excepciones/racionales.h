#pragma once
#include <iostream>
#include "enteros.h"
#include <cstring>
#include <string>
#include <cstdlib>



class racional {

private:
  entero numerador;
  entero denominador;
  entero mcd;
     
public:
  
  racional(void);
  racional(entero num, entero den);
  racional(int n);
  racional(const racional& n);
  racional(int dio, int dir);
  ~racional(void);
  
  entero get_numerador(void) const;
  entero get_denominador(void) const;
  entero m_d(void) const;
  
  
  racional& operator=(const racional&);
  racional& operator=(const string cad);
  racional& operator=(int n);

  friend racional operator+(const racional&, const racional&);
  friend racional operator-(const racional&, const racional&);
  friend racional operator*(const racional&, const racional&);
  friend racional operator/(const racional&, const racional&);
  

  friend bool operator==(const racional&, const racional&);
  friend bool operator!=(const racional&, const racional&);
  friend bool operator<(const racional&, const racional&);
  friend bool operator>(const racional&, const racional&);
  friend bool operator<=(const racional&, const racional&);
  friend bool operator>=(const racional&, const racional&);
  

  friend ostream& operator<<(ostream&, const racional&);
  friend istream& operator>>(istream&, racional&);
  
};