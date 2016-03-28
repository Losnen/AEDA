#pragma once
#include <iostream>
#include <istream>
#include <ostream>

class entero;
class racional;
class real;

using namespace std;



class numero_t 
{
  public:

    virtual const entero toEntero(void) const = 0;
    virtual const racional toRacional(void) const = 0; 
    virtual const real toReal(void) const = 0; 
    //virtual const complejo toComplejo(void) const = 0; 

    virtual ostream& toStream(ostream& sout) const = 0;
    virtual istream& fromStream(istream& sin) = 0;
  
};