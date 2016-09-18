#include <iostream>
using namespace std;
class A{
	int val;
public:
	int value(){
		return val;
	}
	A(int v):val(v){
	}
	A operator+(const A& a){
		return A(val+a.val);
	}
	friend A operator+(const A& a,const A& b);
};

A operator+(const A& a,const A& b){
	return A(a.val+b.val);
}

int main(){
	A a1(1);
	A a2=a1+2;
	cout<<a2.value()<<endl;


	A a3=2+a1;
	cout<<a3.value()<<endl;
}

