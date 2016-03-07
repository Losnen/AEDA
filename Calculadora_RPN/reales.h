#pragma once
#include <iostream>

#define EPSILON 0.000000001



using namespace std;

class real {

private:
  float numero;
     
public:
  
  real(void);
  real(float n);
  real(const real& n);
  ~real(void);
  
  float get_numero(void) const;
  
 
  real& operator=(const real&);
  real& operator=(const float& n);
  

  friend real operator+(const real&, const real&);
  friend real operator-(const real&, const real&);
  friend real operator*(const real&, const real&);
  friend real operator/(const real&, const real&);
  

  friend bool operator==(const real&, const real&);
  friend bool operator!=(const real&, const real&);
  friend bool operator<(const real&, const real&);
  friend bool operator>(const real&, const real&);
  friend bool operator<=(const real&, const real&);
  friend bool operator>=(const real&, const real&);
  
  friend ostream& operator<<(ostream&, const real&);
  friend istream& operator>>(istream&,  real&);
  
};