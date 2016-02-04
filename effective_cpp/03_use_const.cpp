#include <iostream>
using namespace std;
class CTextBlock {
public:
	static const size_t len=3;
	size_t data[len];
	mutable size_t fuck;
	CTextBlock(){
		for(size_t i=0;i<len;i++){
			data[i]=i;
		}
	}
	// size_t& operator[](size_t position){
	// 	return data[position];
	// }
	const size_t& operator[](size_t position) const{
		fuck++;
		return data[position];
	} 
	void print(){
		for(size_t i=0;i<len;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
};

class child: public CTextBlock{
	size_t a;
};

int main(){

	CTextBlock tb;
	child c;
	CTextBlock* ptr=&c;//&tb;
	cout<<typeid(*ptr).name()<<endl;
	const size_t& val=tb[1];
	size_t& val2=const_cast<size_t&> (val);
	val2++;
	tb.print();
}