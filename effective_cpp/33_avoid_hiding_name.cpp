#include <iostream>
using namespace std;


class A{
public:
    virtual int mf1(int x=1){return x;}
};
class B: public A{
public:
    virtual int mf1(int x=2){return 2*x;}
};

int main(){
    A* ptr=new B;
    cout<<ptr->mf1()<<endl;
    cout<<ptr->mf1(2)<<endl;
}
