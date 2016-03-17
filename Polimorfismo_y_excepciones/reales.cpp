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

ostream& real::toStream(ostream& sout) const
{
  sout << numero;
  
  return sout;
}

istream& real::fromStream(istream& sin)
{
  sin >> numero;
  
  return sin;
}

//*************************SOBRECARGA DE OPERADORES "AMIGOS*******************************
//Aritméticos
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
  try {
    if(!b.get_numero()) throw 1;
    
    return real(a.get_numero()/b.get_numero());
    } 
  catch(int a)
  {
    cout << "***ERROR*** [División por cero]\nEl resultado se igualará a 0 pero correctamente tiende a infinito." << endl;
    return 000;
  }
}

//comparación
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

//Entrada-Salida
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