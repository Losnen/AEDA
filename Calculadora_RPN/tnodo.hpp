#pragma once

#include <iostream>
using namespace std;


template <class T>
class node
{
private:

    T value_;
    node<T>* next_;
    node<T>* prev_;
public:
        node(void);
        node(T value);
        ~node(void);

	    void set_next(node<T>* next);
	    node<T>* get_next(void) const;
	    
	    void set_prev(node<T>* prev);
	    node<T>* get_prev(void) const;	
	    
	    
	     void set_value(T value);
	    T get_value(void) const;
	    
        ostream& write(ostream& os);

};

template <class T>
node<T>::node(void):
next_(NULL),
prev_(NULL),
value_(0)
{}
        
template <class T>        
node<T>::node(T value):
next_(NULL),
value_(value)
{}
        
template <class T>        
node<T>::~node(void){}
        
        
template <class T>
node<T>* node<T>::get_next(void) const
{
    return next_;
}
    
template <class T>
T node<T>::get_value(void) const
{
    return value_;
}

template <class T>
void node<T>::set_next(node<T>* next)
{
    next_ = next;
}

template <class T>
void node<T>::set_prev(node<T>* prev)
{
		prev_ = prev;
}

template <class T>
node<T>* node<T>::get_prev(void) const
{
		return prev_;
}


template <class T>
void node<T>::set_value(T value)
{
    value_ = value;
}

template <class T>
ostream& node<T>::write(ostream& os)
{
    os << value_ << " ";
}