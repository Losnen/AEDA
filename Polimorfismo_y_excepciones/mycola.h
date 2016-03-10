#include "mylista.h"


using namespace std;

template <class T>
class mycola 
{
    private:
        mylista<T> l_;
        
    public:
        mycola(void);
        ~mycola(void);
        void put(T dato);
        T get(void);
        bool empty(void);
        void clean(void);
        ostream& write(ostream& os);
    
};

template <class T>
mycola<T>::mycola(void):
l_()
{}

template <class T>
mycola<T>::~mycola(void)
{
    clean();
}

template <class T>
void mycola<T>::put(T dato)
{
    l_.insert_begin(new nodo_t(dato));
}

template <class T>
T mycola<T>::get(void)
{
    nodo_t* nodo_aux = (nodo_t*)(l_.extract_end());
    TDATO aux = nodo_aux->get_dato();
    delete nodo_aux;
    return aux;
}

template <class T>
bool mycola<T>::empty(void)
{
    return l_.empty();
}

template <class T>
void mycola<T>::clean(void)
{
    l_.clean();
}

template <class T>
ostream& mycola<T>::write(ostream& os)
{
   l_.write(os);
    return os; 
}