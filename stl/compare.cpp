#include <iostream>
using namespace std;

int cmp(int a,int b){
	if(a<b){
		return -1;
	} else if( a>b){
		return 1;
	}
	return 0;
}


template<typename T>
int call_func(int (*f)(T ,T ),T a, T b){
	return f(a,b);
}
typedef int (*func)(int ,int );
int main(){
	//func f=cmp;
	int (*f)(int ,int );
	f=cmp;
	cout<<f(0,0)<<endl;
	cout<<f(-1,1)<<endl;
	cout<<f(1,-1)<<endl;

	cout<< call_func<int>(cmp,-1,0) <<endl;
}