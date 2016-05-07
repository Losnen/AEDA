#pragma once
#include <ostream>

using namespace std;

class DNI
{
private:
  
  int numero;	//número del dni. Uso int para poder darle valor -1 en caso de elminiación(método no implementado en ésta práctica)
  
public:
  DNI(void);		//constructor por defecto
  DNI(int n);		//constructor para asignarle un valor a número
  ~DNI(void);		//destructor
  
  void editar(int n);	//método para editar el número
  int obtener(void) const;	//método para obtener el número
  
  DNI& operator=(const DNI&);	//operador de asignación a objeto de la misma clase
  DNI& operator=(const int&);	//operador de asignación a int
  
  friend bool operator==(const DNI&, const DNI&);	//operador de comparación
  friend bool operator==(const DNI&, const int&);	//operador de comparación
  friend bool operator!=(const DNI&, const DNI&);	//operador de comparación
  friend bool operator!=(const DNI&, const int&);	//operador de comparación
  friend bool operator>(const DNI&, const int&);	//operador de comparación
  friend bool operator>(const DNI&, const DNI&);	//operador de comparación
  friend bool operator<(const DNI&, const DNI&);
  friend bool operator>=(const DNI&, const DNI&);
  friend bool operator<=(const DNI&, const DNI&);
  
  operator unsigned int() const { return numero;}
  
  friend ostream& operator<<(ostream&, const DNI&);
  
  friend int operator+(const DNI&, const DNI&);
  friend unsigned operator/(const DNI&, const DNI&);
  friend unsigned operator/(const DNI&, const unsigned&);
  friend unsigned operator%(const DNI&, const DNI&);
  friend unsigned operator%(const DNI&, const unsigned&);
};