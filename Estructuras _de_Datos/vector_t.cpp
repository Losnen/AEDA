#include "vector_t.h"
#include <iostream>

        vector_t::vector_t(void):
        v_(NULL),
        sz_(0)
        {}
        
        vector_t::vector_t(int sz):
        v_(NULL),
        sz_(sz)
        {
            build(sz_);
        }
        
        vector_t::vector_t(const vector_t& v):
        v_(NULL),
        sz_(v.get_sz())
        {
            build(v.get_sz());
            for (int i = 0; i<v.get_sz(); i++)
            {
                v_[i] = v[i];
            }
        }
        
        vector_t::~vector_t(void)
        {
            clean();
        }
        
        void vector_t::resize(int sz)
        {
            clean();
            sz_ = sz;
            build(sz_);
        }
        
        int vector_t::get_sz(void)
        {
            return sz_;
        }
        
        int vector_t::get_sz(void) const
        {
            return sz_;
        }
        
        TDATO& vector_t::operator[](int pos)
        {
            return v_[pos];
        }
        
        TDATO vector_t::operator[](int pos) const
        {
            return v_[pos];
        }
        
        void vector_t::write(void)
        {
            cout << "Tamaño: " << get_sz() << endl;
            for(int i = 0; i<10; i++)
            {
                cout << v_[i] << " ";
            }
            cout << endl;
        }
        
        int vector_t::escalar(vector_t& w)
        {
            int prod = 0;
            for(int i = 0; i < sz_; i++)
                prod += v_[i] * w[i];
                
            return prod;
        }
        
        void vector_t::build(int sz)
        {
            v_ = new TDATO [sz];
        }
        
        void vector_t::clean(void)
        {
            if (v_ != NULL)
            {
                delete [] v_;
                v_ = NULL;
                sz_ = 0;
            }
            
        }