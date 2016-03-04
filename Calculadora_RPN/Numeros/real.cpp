#include "real.h"

real::real(void):
numero_(0)
{}

real::real(float n):
numero_(n)
{}

real::~real(void){}

float real::get_numero(void) const
{
  return numero_;
}

real& real::operator=(const real& a)
{
  numero_ = a.get_numero();
  
  return *this;
}

real& real::operator=(const float& n)
{
  numero_ = n;
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
    if(fabs(a.get_numero()-b.get_numero()) < eps)
        return true;
    else
        return false;
}

bool operator!=(const real& a, const real& b)
{
    if(a == b)
        return true;
     else
        return false;
}

bool operator<(const real& a, const real& b)
{
    if((a.get_numero())<(b.get_numero()-eps))
        return true;
    else
        return false;
}

bool operator>(const real& a, const real& b)
{
    if((a.get_numero())>(b.get_numero()+eps))
        return true;
    else
        return false;
}

bool operator<=(const real& a, const real& b)
{
    if(a>b)
        return false;
    else
        return true;
}

bool operator>=(const real& a, const real& b)
{
    if(a<b)
        return false;
    else
        return true;
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
