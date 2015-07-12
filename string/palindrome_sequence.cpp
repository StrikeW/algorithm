// hiho 1149
// http://hihocoder.com/problemset/problem/1149

//palindrome ,  sequence of characters that reads the same backward or forward
// here , sequence is the keyword!
//sequence , not substring
// f(a,b) = f(a,b-1)+f(a+1,b) - f(a+1,b-1)
// if(data[a] == data[b])
//    f(a,b) += 1 + f(a+1,b-1) 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int recursive(string& str,vector<vector<int> >& arr,int begin,int end){
	if(arr[begin][end]>0)
		return arr[begin][end];
	if(begin==end){
		arr[begin][end]=1;
		return arr[begin][end];
	} else if(begin+1==end){
		arr[begin][end]=(str[begin]==str[end]?3:2);
		return arr[begin][end];
	}
	//without match
	int tmp=recursive(str,arr,begin,end-1)+recursive(str,arr,begin+1,end)-recursive(str,arr,begin+1,end-1);
	if(str[begin]==str[end]){
		arr[begin][end]=tmp+recursive(str,arr,begin+1,end-1)+1;
	} else{
		arr[begin][end]=tmp;
	}
	// this line is very important!
	// other wise it may be a number less than 0
	arr[begin][end]=(arr[begin][end]+100007) %100007;
	return arr[begin][end];
}
int num_palindrome(string& str){
	
	vector<vector<int> >array;
	array.resize(str.size());
	for(int i=0;i<array.size();i++){
		array[i].resize(str.size());
		for(int j=0;j<str.size();j++){
			array[i][j]=-1;
		}
	}
	return recursive(str,array,0,str.size()-1); 
}

int main(){
	int T;
	cin >>T;
	int count=0;
	string input;
	while(cin>>input){
		count++;
		T--;
		cout<<"Case #"<<count<<": "<<num_palindrome(input)<<endl;
	}
}