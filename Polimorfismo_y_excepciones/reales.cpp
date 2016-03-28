#include "reales.h"
#include "racionales.h"
#include "complejos.h"

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

const entero real::toEntero(void) const
{
  int num = get_numero();
  entero a(num);
  return a;
}

const real real::toReal(void) const
{
  real a(get_numero());
  return a;
}

const racional real::toRacional(void) const
{
    float num = get_numero();
    num = num * 10000; 
    racional a(num,10000);
    return a;
}

const complejo real::toComplejo(void) const
{
  real b(get_numero());
  real c(0.0);
  complejo a(b,c);
  return a;
}

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