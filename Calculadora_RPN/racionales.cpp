#include "racionales.h"
#include <cmath>



racional::racional(void):
numerador(),
denominador()
{}

racional::racional(entero dio, entero dir):
numerador(dio),
denominador(dir),
mcd(m_d())
{
  numerador = numerador/mcd;
  denominador = denominador/mcd;
}


racional::racional(int n):
numerador(n),
denominador(1)
{}

racional::racional(int dio, int dir):
numerador(entero(dio)),
denominador(entero(dir)),
mcd(m_d())
{
  numerador = numerador/mcd;
  denominador = denominador/mcd;
}

racional::racional(const racional& n) 
{
  *this = n;
}

racional::~racional(void){}

entero racional::get_numerador(void) const
{
  return numerador;
}

entero racional::get_denominador(void) const
{
  return denominador;
}

racional& racional::operator=(const racional& a)
{
  numerador = a.get_numerador();
  denominador = a.get_denominador();
  mcd=a.m_d();
  
  return *this;
}
racional& racional::operator=(int n)
{
  numerador = n;
  denominador = 1;
  return *this;
}



racional& racional::operator=(const string a)
{
  size_t found = a.find("/");
  
  string b,c;
  b.resize(found);
  c.resize((a.size() - found)-1);
  for(unsigned int i=0;i<found;i++) {
  
   b[i] = a[i];
  }
  for(unsigned int j=0;j<c.size();j++) {
  
    c[j] = a[j+1+found];
  }
  
  numerador = atoi(b.c_str());
  denominador = atoi(c.c_str());
  mcd=m_d();
  numerador = numerador/mcd;
  denominador = denominador/mcd;
  
}

entero racional::m_d(void) const 
{
  entero resto, numerador_aux, resto_aux;
  
  resto = numerador.get_numero()%denominador.get_numero();
  numerador_aux = denominador;
  
  while(resto!=0)
  {
   resto_aux = resto;
   resto = numerador_aux.get_numero()%resto.get_numero();
   numerador_aux = resto_aux;
  }
  
  return numerador_aux;
}

racional operator+(const racional& a, const racional& b)
{  
  return racional(a.get_numerador()*b.get_denominador() + b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional operator-(const racional& a, const racional& b)
{ 
  return racional(a.get_numerador()*b.get_denominador() - b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional operator*(const racional& a, const racional& b)
{ 
  return racional(a.get_numerador()*b.get_numerador(),a.get_denominador()*b.get_denominador());
}

racional operator/(const racional& a, const racional& b)
{
  return racional(a.get_numerador()*b.get_denominador(),a.get_denominador()*b.get_numerador());
}


bool operator==(const racional& a, const racional& b)
{
  if((a.get_numerador()==b.get_numerador())&&(a.get_denominador()==b.get_denominador())) {
    return true;
  } else {
    return false;
  }
}

bool operator!=(const racional& a, const racional& b)
{
  return(a==b ? false:true);
}

bool operator<(const racional& a, const racional& b)
{
  if(a.get_numerador()==b.get_denominador())
  {
    return(a.get_denominador()<b.get_denominador() ? false:true);
    
  } else {
    
      if((a.get_numerador()*b.get_denominador())<(b.get_numerador()*a.get_denominador())) {
	return true;
      } else {
	return false;
      }
  }
  
}

bool operator>(const racional& a, const racional& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const racional& a, const racional& b)
{
  return(a>b ? false:true);
}

bool operator>=(const racional& a, const racional& b)
{
  return(a<b ? false:true);
}


ostream& operator<<(ostream& os, const racional& a)
{
  if ((a.get_numerador() == 0) && (a.get_denominador() == 1))
    os << 0; 
  else
      os << a.get_numerador() << "/" << a.get_denominador();
  return os;
}

istream& operator>>(istream& is, racional& a)
{
  string n;
  is >> n;
  a = n;
  return is;
}
