#include "entero.h"

using namespace std;

int main() {
    
    entero A, X;
    entero B(5);
    entero C(10);
      
     
    cout << "Elige un valor para A" << endl;
    cin >> A;
    
    cout << "A: " << A << endl; //Salida operadro >>
    
    A = 2;
    
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
    A = 4;
    B = 4;
    if(A==B) 
    {
        cout << "A:" << A << " y B:" << B << " son iguales." << endl;
    }
        
    if(B!=C)
    {
        cout << "B:" << B << " y C:" << C << " son distintos." << endl;
    }
    
    if(A<C) 
    {
        cout << "A:" << A << " Es menor que C:" << C << endl;
    }
        
    if(C>A)
    {
        cout << "C:" << C << " Es mayor que A:" << A << endl;
    }
    
}
















