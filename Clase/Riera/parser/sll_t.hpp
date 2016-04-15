#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include <cstdio>


    //=====================================================================
    // Elemento de lista doblemente enlazada
    //=====================================================================

    class sll_item_t {
    public:

        sll_item_t* next_;
        sll_item_t* prev_;

    public:
        sll_item_t();
        sll_item_t(sll_item_t* prev, sll_item_t* next);

        virtual ~sll_item_t(void);

        virtual void write(std::ostream& os) {};

        virtual sll_item_t* copy(void) {return NULL;}
        virtual void clean(void) {}
    };

    //=====================================================================
    // Clase gestora de lista doblemente enlazada
    //=====================================================================

    class sll_t {
    private:
        sll_item_t* inicio_;
        sll_item_t* fin_;

        int size_;

    public:
        sll_t(void);
        sll_t(const sll_t& lista);
        virtual ~sll_t(void); // Elimina la lista pero no la información

        void push_back(sll_item_t*);
        sll_item_t* pop_front(void);
        sll_item_t* pop_back(void);

        bool empty(void);

        void remove(sll_item_t*);

        void clear(void); // Borra el sólo el nodo y no borra el dato
        void clean(void); // Borra el nodo y el dato
      
        int size(void);

        void write(std::ostream& os);

    };


   //=====================================================================
    // Elemento de lista doblemente enlazada
    //=====================================================================

    sll_item_t::sll_item_t() :
	next_(NULL),
    prev_(NULL)
	{
    }

    sll_item_t::sll_item_t(sll_item_t* prev, sll_item_t* next) :
    next_(next),
    prev_(prev) {
    }

    sll_item_t::~sll_item_t(void) {
        prev_ = NULL;
        next_ = NULL;
    }

    //=====================================================================
    // Clase gestora de lista doblemente enlazada
    //=====================================================================

    sll_t::sll_t(void) :
    inicio_(NULL),
    fin_(NULL),
    size_(0) {
    }

    sll_t::~sll_t(void) {

        clear();
    }

    sll_t::sll_t(const sll_t& lista) :
    inicio_(NULL),
    fin_(NULL),
    size_(0) {
    }

    void sll_t::clear(void) {

        sll_item_t* aux = NULL;

        while (inicio_ != NULL) {
            aux = inicio_;
            inicio_ = inicio_->next_;
            delete aux;
            aux = NULL;
        }
        size_ = 0;
        inicio_ = NULL;
        fin_ = NULL;
    }


    void sll_t::clean(void) {

        sll_item_t* aux = NULL;

        while (inicio_ != NULL) {
			
            aux = inicio_;
            inicio_ = inicio_->next_;
			
			if (aux){
				aux->clean();
				delete aux;				
			}
        }

        size_ = 0;
        inicio_ = NULL;
        fin_ = NULL;
    }


    void sll_t::push_back(sll_item_t* nodo) {

        assert(nodo != NULL);

        if (!inicio_) {
            inicio_ = nodo;
            fin_ = inicio_;
        } else {
            fin_->next_ = nodo;
            nodo->prev_ = fin_;
            fin_ = nodo;
        }

        size_++;
    }

    bool sll_t::empty(void) {
        return (inicio_ == NULL);
    }

    sll_item_t* sll_t::pop_front(void) {

        assert(inicio_ != NULL);

        sll_item_t* aux = inicio_;

        inicio_ = inicio_->next_;

        if (inicio_)
            inicio_->prev_ = NULL;
        else
            fin_ = NULL;

        size_--;

        return aux;
    }

    sll_item_t* sll_t::pop_back(void) {

        assert(fin_ != NULL);

        sll_item_t* aux = fin_;

        fin_ = fin_->prev_;

        if (fin_)
            fin_->next_ = NULL;
        else
            inicio_ = NULL;

        size_--;

        return aux;
    }

    void sll_t::write(std::ostream& os) {
		
        sll_item_t* aux = inicio_;

        while (aux != NULL) {
            aux->write(os);
            aux = aux->next_;
        }
    }

    void sll_t::remove(sll_item_t* nodo) {
			
        assert(nodo != NULL);

        if (nodo->prev_ != NULL)
            nodo->prev_->next_ = nodo->next_;
        else
            inicio_ = nodo->next_;

        if (nodo->next_ != NULL)
            nodo->next_->prev_ = nodo->prev_;
        else
            fin_ = nodo->prev_;

        size_--;

    }

    int sll_t::size(void) {
        return size_;
    }


