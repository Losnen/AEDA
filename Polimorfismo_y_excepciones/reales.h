#pragma once
#include <iostream>
#include "enteros.h"
#include "numero.h"

#define EPSILON 0.000000001



using namespace std;

class real:public numero_t {

private:
  float numero;
     
public:
  
  real(void);
  real(float n);
  real(const real& n);
  ~real(void);
  
  float get_numero(void) const;
  
  virtual const entero toEntero(void) const;
  virtual ostream& toStream(ostream& sout) const;  
  virtual istream& fromStream(istream& sin);
  
  //SOBRECARGA DE OPERADORES
  real& operator=(const real&);
  real& operator=(const float& n);
  
  //aritméticos
  friend real operator+(const real&, const real&);
  friend real operator-(const real&, const real&);
  friend real operator*(const real&, const real&);
  friend real operator/(const real&, const real&);
  
  //comparación
  friend bool operator==(const real&, const real&);
  friend bool operator!=(const real&, const real&);
  friend bool operator<(const real&, const real&);
  friend bool operator>(const real&, const real&);
  friend bool operator<=(const real&, const real&);
  friend bool operator>=(const real&, const real&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const real&);
  friend istream& operator>>(istream&, const real&);
  
};