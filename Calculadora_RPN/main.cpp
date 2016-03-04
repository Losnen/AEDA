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
using namespace std;

int main(void)
{
    
    
    string str; 
     
     cout << "Introduce la expresion en forma RPN a calcular: " ; 
     
     getline(cin,str);
     
    istringstream expresion(str);
    int r=0;
    mycalc<int> A;
    cout << " El resultado es: ";
    r =  A.calc(expresion);
    cout << r << endl;

}
 