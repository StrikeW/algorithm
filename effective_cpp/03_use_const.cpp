#include <iostream>
using namespace std;
class CTextBlock {
public:
	static const size_t len=3;
	size_t data[len];
	CTextBlock(){
		for(size_t i=0;i<len;i++){
			data[i]=i;
		}
	}
	// size_t& operator[](size_t position){
	// 	return data[position];
	// }
	const size_t& operator[](size_t position) const{
		return data[position];
	} 
	void print(){
		for(size_t i=0;i<len;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	CTextBlock tb;
	const size_t& val=tb[1];
	tb.print();
}