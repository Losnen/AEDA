#pragma once

#include <iostream>
using namespace std;

#include "tnodo.hpp"

template <class T>
class dll {
private:

        node<T>* beginning_;
        node<T>* end_;

 public:
        dll(void);
         ~dll(void);

        void insert_beginning(node<T>* n);
        node<T>* extract_beginning(void);

	    void insert_end(node<T>* n);
	    node<T>* extract_end(void);

        bool empty(void) const;	
	    ostream&  write(ostream& os) const;
};
    

template <class T>
dll<T>::dll(void):
beginning_(NULL),
end_(NULL){}


template <class T>
dll<T>::~dll(void) 
{
    while (beginning_ != NULL) 
    {
        node<T>* aux = beginning_;
        beginning_ = beginning_->get_next();
        delete aux;
        }
}


template <class T>	
bool dll<T>::empty(void) const 
{
        return (beginning_ == NULL);
}



template <class T>
void dll<T>::insert_beginning(node<T>* n)
{
   n->set_next(beginning_);
   n->set_prev(NULL);
    	
  if(end_ == NULL)
    	end_ = n;
   else
        beginning_->set_prev(n);
    	    
    beginning_ = n;
}


template <class T>
node<T>* dll<T>::extract_beginning(void) 
{

   node<T>* aux = beginning_;
   beginning_ = beginning_->get_next();
        
   aux->set_next(NULL);
   aux->set_prev(NULL);
        
   if (beginning_ == NULL)
        end_ = NULL;

        return aux;
}



template <class T> 
void dll<T>::insert_end(node<T>* n)
{
    n->set_prev(end_);
    n->set_next(NULL);
    	
    if (end_ != NULL)
    	    end_->set_next(n);
    else
    	    beginning_ = n;
    	    
    end_ = n;
}


template <class T>
node<T>* dll<T>::extract_end(void) 
{

        node<T>* aux = end_;
        
        end_ = end_->get_prev();
        
        aux->set_next(NULL);
        aux->set_prev(NULL);
        
        if (end_ == NULL)
            beginning_ = NULL;
        else
            end_->set_next(NULL);

        return aux;
    } 


template <class T>
ostream& dll<T>::write(ostream& os) const 
{
    node<T>* aux = beginning_;

    while (aux != NULL) 
    {
            aux->write(os);
            aux = aux->get_next();
    }
}
