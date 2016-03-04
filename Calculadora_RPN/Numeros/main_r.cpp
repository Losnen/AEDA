#include "real.h"

using namespace std;

int main() {
    
    real A, X;
    real B(1.2);
    real C(1.0100002);
      
     
    //cout << "Elige un valor para A" << endl;
    //cin >> A;
    
    
    A = 2.121202;
    
    X = A + B + C;
    cout << "Suma: " << A << "+" << B << "+" << C << "=" << X << endl;
      
    //resta
    X = A - C;
    cout << "Resta: " << A << "-" << C << "=" << X << endl;//salida
    X = B - C;
    cout << "Resta: " << B << "-" << C << "=" << X << endl;//salida
      
    //multiplicación
    X = A*B*C;
    cout << "Multiplicacion: " << A << "*" << B << "*" << C << "=" << X << endl;//salida
    
    //división
    X = A/C;
    cout << "Division: " << A << "/" << C << "=" << X << endl;
      
    //OPERADORES DE COMPARACIÓN
    
    //Igualdad y desigualdad
    A = 4.01;
    B = 4.01;
    if(A==B) 
    {
        cout << "A:" << A << " y B:" << B << " son iguales." << endl;
    }
        
    if(C!=A)
    {
        cout << "B:" << B << " y C:" << C << " son distintos." << endl;
    }
    
    if(A>C) 
    {
        cout << "A:" << A << " Es mayor que C:" << C << endl;
    }
        
    if(C<A)
    {
        cout << "C:" << C << " Es menor que A:" << A << endl;
    }
    
}
