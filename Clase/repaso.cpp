#include <iostream>

class A
{
    private:
        int a_;
    
    public:
    A(void):
    a_(0)
    {}
    
    int get(void) const
    {
        return a_;
    }
    
    int &get(void)
    {
        return a_;
    }
};

int main(void)
{
    A b;
    b.get() = 6;
    cout << b.get() << endl;
}
