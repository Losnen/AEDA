#include "real.h"
#include <cstdlib>


class complejo {

private:
  real r;
  real i;
  real m;
     
public:
  
  complejo(void);
  complejo(real re, real im);
  complejo(float re, float im);
  complejo(const complejo& n);
  ~complejo(void);
  
  real get_r(void) const;
  real get_i(void) const;
  real get_m(void) const;
  
  complejo& operator=(const complejo&);
  complejo& operator=(const string a);
  
  

  friend complejo operator+(const complejo&, const complejo&);
  friend complejo operator-(const complejo&, const complejo&);
  friend complejo operator*(const complejo&, const complejo&);
  friend complejo operator/(const complejo&, const complejo&);
  

  friend bool operator==(const complejo&, const complejo&);
  friend bool operator!=(const complejo&, const complejo&);
  friend bool operator<(const complejo&, const complejo&);
  friend bool operator>(const complejo&, const complejo&);
  friend bool operator<=(const complejo&, const complejo&);
  friend bool operator>=(const complejo&, const complejo&);
  

  friend ostream& operator<<(ostream&,  complejo&);
  friend istream& operator>>(istream&,  complejo&);
  
};