#include <iostream>
#include <string>
#include <vector>

//	http://blog.csdn.net/yutianzuijin/article/details/11954939

using namespace std;

//the meaning of next array: max length of equal prefix and postfix
//for example 
//string longstr="abcabaabcabc";
//next[5] means max length of equal prefix and postfix of "abcab", 
//so next[5]=2;
//next[]={0,0,0,0,1,2,1,1,2,3,4,5,3};

vector<int> get_next(string str){
	vector<int> next;
	next.resize(str.size()+1);
	if(str.size()<2)
		return next;
	next[1]=0;
	int len=1;
	while(len<str.size()){
		// we are calculating next[len+1]
		int j=next[len];
		while(true){
			if(str[j]==str[len]){
				next[len+1]=j+1;
				break;
			}
			else {
				if(next[j]==j)
					break;
				j=next[j];
			}
		}
		len++;
	}
	return next;
}

int kmp(string longstr,string str){
	if(str.size()==0)
		return 0;
	vector<int>next= get_next(str);
	int j=0;
	for(int i=0;i<longstr.size();i++){
		while(j>0 && longstr[i]!=str[j])
			j=next[j];
		if(longstr[i]==str[j])
			j++;
		if(j==str.size()){
			// we found it!
			return i-j+1;
		}
	}
	return -1;
}


void test_kmp(){
	string longstr="abcabaabcabccbab";
	string str="aabcb";
	//string str="a";
	vector<int> next=get_next(longstr);
	for(int i=1;i<next.size();i++){
		cout<<next[i]<<endl;
	}
	//cout<<kmp(longstr,str)<<endl;
}

int main(){
	test_kmp();
}