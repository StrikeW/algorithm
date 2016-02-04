#include <iostream>
using namespace std;

class a1{
	size_t a;
	virtual void func();
};
class b1:public virtual a1 {
	virtual void foo();
	size_t b;
};
class c1:public virtual b1 {
	virtual void bar();
	size_t c;
};

int main(){
	cout<<sizeof(a1)<<" "<<sizeof(b1)<<" "<<sizeof(c1)<<endl;
}
