#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> mysplit(string input,char c){
	vector<string> result;
	if(input=="")
		return result;
	int curr=0;
	while(true){
		if(curr==input.size())
			break;
		int nextpos=input.find(c,curr);
		if(nextpos==string::npos){
			result.push_back(input.substr(curr));
			break;
		} else if(nextpos==curr){
			result.push_back("");
		} else {
			result.push_back(input.substr(curr,nextpos-curr));
		}
		curr=nextpos+1;
	}
	return result;
}
void test_mysplit(){
	vector<string> vec=mysplit("/..",'/');
	for(int i=0;i<vec.size();i++){
		cout<<i<<":"<<vec[i]<<endl;
	}
}
int main(){
	test_mysplit();
	return 0;
}