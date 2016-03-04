#pragma once
#include <iostream>
#include <cmath>


const float eps = 0.0001;

using namespace std;

class real 
{
    private:
        float numero_;
     
    public:
  
        real(void);
        real(float n);
        ~real(void);
        float get_numero(void) const;
          
        real& operator=(const real&);
        real& operator=(const float& n);
          
        friend real operator+(const real&, const real&);
        friend real operator-(const real&, const real&);
        friend real operator*(const real&, const real&);
        friend real operator/(const real&, const real&);
          
        friend bool operator==(const real&, const real&);
        friend bool operator!=(const real&, const real&);
        friend bool operator<(const real&, const real&);
        friend bool operator>(const real&, const real&);
        friend bool operator<=(const real&, const real&);
        friend bool operator>=(const real&, const real&);
          
        friend ostream& operator<<(ostream&, const real&);
        friend istream& operator>>(istream&, const real&);
};