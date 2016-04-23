#include "dni.hpp"

DNI::DNI(void):
numero(0)
{}

DNI::DNI(int n):
numero(n)
{}
  
DNI::~DNI(void)
{}
  
void DNI::editar(int n)
{
  numero = n;
}
  
int DNI::obtener(void) const
{
  return(numero);
}

DNI& DNI::operator=(const DNI& a)
{
  numero = a.obtener();
}

DNI& DNI::operator=(const int& a)
{
  numero = a;
}

bool operator==(const DNI& a, const DNI& b)
{
  return (a.obtener()==b.obtener()?true:false);
}

bool operator==(const DNI& a, const int& b)
{
  return (a.obtener()==b?true:false);
}

bool operator!=(const DNI& a, const DNI& b)
{
  return (a==b?false:true);
}

bool operator!=(const DNI& a, const int& b)
{
  return (a.obtener()==b?false:true);
}

bool operator>(const DNI& a, const int& b)
{
  return (a.obtener()>b?true:false);
}

bool operator>(const DNI& a, const DNI& b)
{
  return (a.obtener()>b.obtener()?true:false);
}

ostream& operator<<(ostream& os, const DNI& a)
{
  os << a.obtener();
  return os;
}

int operator+(const DNI& a, const DNI& b)
{
  return(a.obtener()+b.obtener());
}
  
unsigned operator/(const DNI& a, const DNI& b)
{
  return(a.obtener()/b.obtener());
}

unsigned operator/(const DNI& a, const unsigned& b)
{
  return(a.obtener()/b);
}
  
unsigned operator%(const DNI& a, const DNI& b)
{
  return(a.obtener()%b.obtener());
}

unsigned operator%(const DNI& a, const unsigned& b)
{
  return(a.obtener()%b);
}








