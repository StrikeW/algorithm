#include <iostream>
using namespace std;


bool func1(int a,int b){
	return a==b;
}
class func2{
public:
	int input;
	func2(int i){
		input=i;
	}
	bool operator()(int a,int b){
		return a+input==b;
	}
};
int main(){
	function<bool(int,int)> f=func1;
	cout<<f(1,1)<<endl;
	cout<<f(1,2)<<endl;

	f=func2(1);
	cout<<f(1,1)<<endl;
	cout<<f(1,2)<<endl;

}