#include <iostream>
using namespace std;

class A{
public:
	A(){
		log();
	}
	virtual void log(){
		cout<<"A"<<endl;
	}
};

class B: public A{
public:
	B(){
		log();
	}
	virtual void log(){
		cout<<"B"<<endl;
	}
};

int main(){
	B b;
	// A B
}