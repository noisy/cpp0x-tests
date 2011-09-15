#include <iostream>

using namespace std;

struct Y
{
    Y(int a):a(a){}
    int a;

    Y(Y& y)
    {
        cout<<"copy const\n";
        a = y.a;
    }

    ~Y()
    {
        cout<<"Y dest\n";
    }

};




class X
{
    public:
    //int a;

    X(Y& y)
    {
        cout<<"X(Y& y)"<<endl;
        y.a = 13;
    }

    X(Y const& y)
    {
        cout<<" X(Y const& y)"<<endl;
        //a = 13;
    }

    X(Y&& y)
    {
        cout<<"X(Y&& y)"<<endl;
        y.a = 13;
        cout<<"X(Y&& y) - y.a  = "<<y.a<<endl;
        //cout<<"X(Y&& y) - yy.a = "<<yy.a<<endl;
    }

};



Y&& fun()
{
    Y yy(42);
    cout<<"Y fun() - "<<yy.a<<endl;
    return std::move(yy);
}

int main () {

    Y a(42);

    X x(fun());

    //cout<<yy.a<<endl;

    return 0;
}
