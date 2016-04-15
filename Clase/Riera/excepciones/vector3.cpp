#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

#include <exception>
#include <cstring>

#define MAX_VECTOR_SZ 20

using namespace std;

class vector_exception: public exception
{
};

class overflow_index_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Índice sobrepasado";
  }
};

class underflow_index_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Índice incorrecto";
  }
};

class over_size_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Tamaño máximo de vector excedido";
  }
};

class bad_size_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Tamaño de vector incorrecto";
  }
};


template <class T>
class vector_t{
private:
	T*      v_;
	int     sz_;

public:

	vector_t(void):
		v_(NULL),
		sz_(0) {}

	vector_t(int sz):
		v_(NULL),
		sz_(sz) {

		crea_vector();
	}

	~vector_t(void){

		destruye_vector();
	}

	void resize(int sz)
	{
		destruye_vector();
		sz_ = sz;
		crea_vector();
	}

	int get_sz(void) const
	{
		return sz_;
	}

	T operator[](int pos) const{

		if (pos >= sz_)
			throw overflow_index_exception();
		else if (pos < 0)
			throw underflow_index_exception();

		return v_[pos];
	}

	T& operator[](int pos){

		if (pos >= sz_)
			throw overflow_index_exception();
		else if (pos < 0)
			throw underflow_index_exception();


		return v_[pos];
	}

	ostream& write(ostream& os) const{
	
		os << setw(8) <<  sz_ << endl;

		for(int i = 0; i < sz_; i ++)
		 	os << v_[i] << " ";


		return os;
	}

	istream& read(istream& is){
	
		is >> sz_;

		resize(sz_);

		for(int i = 0; i < sz_; i ++)
		 	is >> v_[i];

		return is;
	}

private:

	void crea_vector(void){

		if (sz_ > MAX_VECTOR_SZ)
			throw over_size_exception();
		else  if (sz_ <= 0)
			throw bad_size_exception();				
	
		v_ = new T[sz_];

		if (v_ == NULL)
                	throw std::bad_alloc();
	}

	void destruye_vector(void)
	{
		if (v_ != NULL){
			delete [] v_;
			v_ = NULL;
		}
	}

};

template <class T>
ostream& operator<<(ostream& os, const vector_t<T>& v)
{
	v.write(os);
	return os;
}

template <class T>
istream& operator>>(istream& is, vector_t<T>& v)
{
	v.read(is);
	return is;
}


int main(void)
{

  try 
  {
  	vector_t<int> a(10);
	a[-1] = 1;
  }
  catch(exception& e)
  {
    cout << e.what() <<  endl;
  }

  try 
  {
  	vector_t<int> a(10);
	a[20] = 1;
  }
  catch(exception& e)
  {
    cout << e.what() <<  endl;
  }

  try 
  {
  	vector_t<int> a(21);
  }
  catch(exception& e)
  {
    cout << e.what() <<  endl;
  }

  try 
  {
  	vector_t<int> a(-1);
  }
  catch(exception& e)
  {
    cout << e.what() <<  endl;
  }

  return 0;

}
