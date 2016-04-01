#include "dni.h"

DNI::DNI(void):
num(0)
{}

DNI::DNI(int n):
num(n)
{}
  
DNI::~DNI(void)
{}
  
int DNI::set_dni(int n)
{
  num = n;
}

int DNI::get_dni(void) const
{
  return(num);
}

DNI& DNI::operator=(const DNI& a)
{
  num = a.get_dni();
}

DNI& DNI::operator=(const int& a)
{
  num = a;
}

ostream& operator<<(ostream& os, const DNI& a)
{
  os << a.get_dni();
  return os;
}
