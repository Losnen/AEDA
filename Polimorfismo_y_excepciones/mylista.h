#pragma once
#include "tnodo.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

template <class T>
class mylista
{
  private:
    mynodo<T>* head_;
    mynodo<T>* tail_;

  public:
    mylista(void);
    ~mylista(void);
    bool empty(void);
    void clean(void);
    void write(ostream& os);
    void insert_begin(mynodo<T>* aux);
    void insert_end(mynodo<T>* aux);
    mynodo<T>* extract_begin(void);
    mynodo<T>* extract_end(void);

};

template <class T>
mylista<T>::mylista(void):
head_(NULL),
tail_(NULL)
{}

template <class T>
mylista<T>::~mylista(void)
{
	clean();
}
    
template <class T>
bool mylista<T>::empty(void)
{
    if(head_ == NULL)
        return true;
    else
        return false;
}
    
template <class T>
void mylista<T>::clean(void)
{
    while (head_ != NULL) 
	{
       	mynodo<T>* aux = head_;
        head_ = head_->get_next();
        delete aux;
    }
}
    
template <class T>
void mylista<T>::write(ostream& os)
{
    mynodo<T>* aux = head_;
    while(aux != NULL)
    {
        aux->write(os);
        aux= aux->get_next();
    }
}
    
template <class T>
void mylista<T>::insert_begin(mynodo<T>* aux)
{
    if(empty())
	{
        head_ = aux;
        tail_ = aux;
	}
	else 
	{ 
        aux->set_next(head_);
	    head_=aux;
	}
}

template <class T>
void mylista<T>::insert_end(mynodo<T>* aux)
{
	if(empty())
	{
	    head_= aux;
	    tail_=aux;
	}
	else 
	{
	    tail_->set_next(aux);
	    tail_=aux;
	}
}

template <class T>
mynodo<T>* mylista<T>::extract_begin(void)
{
    if(head_==tail_)
	{
		mynodo<T>* aux=head_;
		head_=NULL;
		tail_=NULL;
		return aux;
	}
	else
	{
		mynodo<T>* aux = head_;
		head_=head_->get_next();
		return aux;
	}
}

template <class T>
mynodo<T>* mylista<T>::extract_end(void)
{
    if(head_==tail_)
	{
		mynodo<T>* aux=head_;
		head_=NULL;
		tail_=NULL;
		return aux;
	}
	else
	{
		mynodo<T>* aux=head_;
		while(aux->get_next() != tail_)
			aux=aux->get_next();
	    
	    tail_= aux;
	    aux=aux->get_next();
	    tail_->set_next(NULL);
	    return aux;
	}
}