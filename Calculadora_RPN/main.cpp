#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <cctype> 
#include "tlista.hpp"
#include "tpila.hpp"
#include "tcalculadora.hpp"
#include "entero.h"
#include "real.h"
#include "complejo.h"

using namespace std;

int main(void)
{
    
    
    string str; 
     
     cout << "Introduce la expresion en forma RPN a calcular: " ; 
     
     getline(cin,str);
     
    istringstream expresion(str);
    complejo r;
    mycalc<complejo> A;
    cout << " El resultado es: ";
    r =  A.calc(expresion);
    cout << r << endl;

}
 