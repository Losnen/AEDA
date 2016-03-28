#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "enteros.h"
#include "numero.h"


class racional:public numero_t {

private:
  entero numerador;
  entero denominador;
  entero mcd;
     
public:
  
  racional(void);
  racional(entero num, entero den);
  racional(const racional& n);
  racional(int dio, int dir);
  ~racional(void);
  
  entero get_numerador(void) const;
  entero get_denominador(void) const;
  entero m_d(void) const;
  
  virtual const entero toEntero(void) const;
  virtual const real toReal(void) const;        
  virtual const racional toRacional(void) const;
  virtual ostream& toStream(ostream& sout) const;  
  virtual istream& fromStream(istream& sin);
  
  racional& operator=(const racional&);
  racional& operator=(const string cad);
  
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
  friend istream& operator>>(istream&, const racional&);
  
};