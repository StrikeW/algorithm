#include <iostream>
#include <vector>
using namespace std;
struct factor{
	int value;
	int n;
};
vector<factor> get_factors(int input){
	vector<factor> result;
	factor f;
	f.value=2;
	f.n=0;
	while(input>1){
		if(input % f.value ==0){
			f.n++;
			input=input/f.value;
		} else {
			if(f.n>0)
				result.push_back(f);
			f.value++;
			f.n=0;
		}
	}
	if(f.n>0)
		result.push_back(f);
	return result;
}
int main(){
	int input;
	cin>>input;
	vector<factor> result=get_factors(input);
	for(int i=0;i<result.size();i++){
		cout<<result[i].value<<"^"<<result[i].n<<endl;
	}
}