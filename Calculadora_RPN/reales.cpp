#include "reales.h"
#include <cmath>
real::real(void):
numero(0)
{}

real::real(float n):
numero(n)
{}

real::real(const real& n) 
{
  *this = n;
}

real::~real(void){}

float real::get_numero(void) const
{
  return numero;
}

real& real::operator=(const real& a)
{
  numero = a.get_numero();
  
  return *this;
}

real& real::operator=(const float& n)
{
  numero = n;
  return *this;
}

real operator+(const real& a, const real& b)
{
  return real(a.get_numero() + b.get_numero());
}

real operator-(const real& a, const real& b)
{ 
      return real(a.get_numero() - b.get_numero());
}

real operator*(const real& a, const real& b)
{
  return real(a.get_numero() * b.get_numero());
}

real operator/(const real& a, const real& b)
{
  return real(a.get_numero() / b.get_numero());
}


bool operator==(const real& a, const real& b)
{
  return(fabs(a.get_numero()-b.get_numero()) < EPSILON ? true:false);
}

bool operator!=(const real& a, const real& b)
{
  return(a==b ? false:true);
}

bool operator<(const real& a, const real& b)
{
  return((a.get_numero()-b.get_numero()) < -EPSILON ? true:false);
}

bool operator>(const real& a, const real& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const real& a, const real& b)
{
  return(a>b ? false:true);
}

bool operator>=(const real& a, const real& b)
{
  return(a<b ? false:true);
}


ostream& operator<<(ostream& os, const real& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, real& a)
{
  float n;
  is >> n;
  a = real(n);
  return is;
}
