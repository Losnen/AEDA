#pragma once
#include <iostream>

typedef int TDATO;
using namespace std;

class vector_t
{
    private:
        TDATO*  v_;
        int     sz_;
    
    public:
        
        vector_t(void);
        vector_t(int sz);
        vector_t(const vector_t& v);
        ~vector_t(void);
        void resize(int sz);
        int get_sz(void);
        int get_sz(void) const;
        TDATO& operator[](int pos);
        TDATO operator[](int pos) const;
        void write(void);
        int escalar(vector_t& w);
        
        private:
        void build(int sz);
        void clean(void);
    
};