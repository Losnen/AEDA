#include <iostream>
#include "celda.h"

int main (void)
{
    Celda<int> a(10);
    
    for (int i = 0; i < 10; i++) 
    {
        a.Insertar(i+1);
    }
    
    for (int i = 0; i < 10; i++) 
    {
        cout << a.get_dato(i) << " ";
    }
}