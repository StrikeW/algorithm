#include <iostream>
using namespace std;


class A{
	int a;
	int b;
public:
	A(){
		//a=-1;b=1;
		cout<<"Create"<<endl;
	}
	~A(){
		cout<<"a="<<a<<";b="<<b<<endl;
		cout<<"Destroy"<<endl;
	}
};
int main(){
	int* buffer=new int[100];
	buffer[0]=1;
	buffer[1]=2;
	cout<<(void*)buffer<<endl;
	A* ptr=new (buffer)A;
	cout<<ptr<<endl;
	ptr->~A();
	//don't call delete here!
}