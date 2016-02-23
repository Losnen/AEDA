// Primer Ejemplo
template <class T>

class mypair
{
    private:
    
        T values[2];
    
    public:
    
        mypair(T first, T second)
        {
            values[0] = first;
            values[1] = second;
        }
};

//Segundo ejemplo del Pair
#include <iostream>

using namespace std;

template <class T>

class mypair
{
    private:
    
        T a;
        T b;
    
    public:
    
        mypair(T first, T second):
            a(first),
            b(second)
        {}
        
        T get_max(void);
};

template <class T> // Definicion de la clase
T mypair<T>::get_max(void)
{
    T aux;
    aux = a>b?a:b;
    return aux;
}

int main (void)
{
    mypair<int> myob(10,75);
    cout << myob.get_max();
}

#include <iostream>
using namespace std;

template <class T>

class mycontainer
{
    private:
    
        T element;
    
    public:
    
        mycontainer(T arg):
            element(arg) {}
            
        T increase(void)
        {
            return ++element;
        }
};

template <>
class mycontainer<char>
{
    private:
    
        char element;
        
    public:
        
        mycontainer(char arg):
            element(arg){}
        
        char uppercase(void)
        {
            if( (element >= 'a') && (element <= 'z') )
            {
                element += 'A' -'a';
            }
            return element;
        }
};

int main(void)
{
    mycontainer<int> myint(7);
    mycontainer<char> mychar('j');
    
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;
}


