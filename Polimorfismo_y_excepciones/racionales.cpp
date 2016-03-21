#include "racionales.h"
#include "cmath"

racional::racional(void):
numerador(1),
denominador(2)
{}

racional::racional(entero dio, entero dir):
numerador(dio),
denominador(dir),
mcd(m_d())
{
  try
  {
    if(!denominador.get_numero()) { throw "ERRORACO DEL 15"; }

    mcd = m_d();
    numerador = numerador/mcd;
    denominador = denominador/mcd;
  } 
  catch(const char* a)
  {
    cerr << "ERROR, SE HA INTRODUCIDO UN NÚMERO CON DENOMINADOR 0" << endl;
  }

}

racional::racional(int dio, int dir):
numerador(entero(dio)),
denominador(entero(dir)),
mcd(m_d())
{
  try
  {
      if(!denominador.get_numero()) throw "ERRORACO DEL 15";

      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
  } 
  catch(const char* a)
  {
      cerr << "ERROR, SE HA INTRODUCIDO UN NÚMERO CON DENOMINADOR 0" << endl;
      exit(0);
  }

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

const entero racional::toEntero(void) const
{
  entero a(get_numerador() / get_denominador());
  return a;
}
const real racional::toReal(void) const
{
  entero d(get_denominador());
  entero n(get_numerador());
  real a(n.get_numero() / d.get_numero());
  return a;
}

racional& racional::operator=(const racional& a)
{
  numerador = a.get_numerador();
  denominador = a.get_denominador();
  mcd=a.m_d();
  
  return *this;
}

racional& racional::operator=(const string a)
{
    try
    {
      size_t found = a.find("/");
    
      string b,c;
      b.resize(found);
      c.resize((a.size() - found)-1);
      for(unsigned int i=0;i<found;i++) 
      {
        b[i] = a[i];
      }
      for(unsigned int j=0;j<c.size();j++) 
      {
        c[j] = a[j+1+found];
      }
  
      numerador = atoi(b.c_str());
      denominador = atoi(c.c_str());
  
      if(!denominador.get_numero()||!numerador.get_numero()) throw 1; 

      
      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
      return *this;
   } 
    catch(int a)
    {
      cerr << "ERROR, SE HA INTRODUCIDO UN NÚMERO CON DENOMINADOR 0" << endl;
    }
  
}

entero racional::m_d(void) const //algoritmo de Euclides
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

ostream& racional::toStream(ostream& sout) const
{
    numerador.toStream(cout);
    cout << "/";
    denominador.toStream(cout);
  
    return sout;
}

istream& racional::fromStream(istream& sin)
{
    string a;
    sin >> a;
  
    try
    {
      size_t found = a.find("/");
    
      string b,c;
      b.resize(found);
      c.resize((a.size() - found)-1);
      for(unsigned int i=0;i<found;i++) 
      {
        b[i] = a[i];
      }
      for(unsigned int j=0;j<c.size();j++) 
      {
        c[j] = a[j+1+found];
      }
    
      numerador = atoi(b.c_str());
      denominador = atoi(c.c_str());
    
      if(!denominador.get_numero()||!numerador.get_numero()) throw 1; 
      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
     } 
    catch(int a)
    {
      cerr << "ERROR, SE HA INTRODUCIDO UN NÚMERO CON DENOMINADOR 0" << endl;
    }
  
  return sin;
}

//*************************SOBRECARGA DE OPERADORES "AMIGOS*******************************
//Aritméticos
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