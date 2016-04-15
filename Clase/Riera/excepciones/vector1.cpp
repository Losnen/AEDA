
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

#include <exception>

using namespace std;

struct overflow_index_exception : public exception
{
  const char * what () const throw ()
  {
    return "Índice sobrepasado";
  }
};

struct underflow_index_exception : public exception
{
  const char * what () const throw ()
  {
    return "Índice incorrecto";
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

		//if (pos >= sz_)
		//	throw overflow_error;
		
		//assert((pos < sz_) && ((pos >= 0)));

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
		v_ = new T[sz_];
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

	 for(int i = 0; i < 11; i++)
		a[-i] = i;

  }catch(overflow_index_exception& e)
  {
    cout << e.what() <<  endl;
  }
  catch(underflow_index_exception& e)
  {
    cout << e.what() <<  endl;
  }
  catch(exception& e)
  {
    cout << e.what() <<  endl;
  }

  return 0;

}


