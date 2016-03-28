#include <climits>  //INT_MAX  INT_MIN
#include <cstring>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;

void cmd1(string& str){
	int i;
	int j;
	char x;
	cin>>i>>j>>x;
	for(int t=i-1;t<=j-1;t++){
		str[t]=x;
	}
}
void cmd2(string& str){
	int i;
	int j;
	int k;
	cin>>i>>j>>k;

	for(int t=i-1;t<=j-1;t++){
		str[t]=  (str[t]-'A'+k)%26 +'A';
	}
}
void reverse(string& str,int begin,int end){
	while(begin<end){
		swap(str[begin],str[end]);
		begin++;
		end--;
	}
}
void cmd3(string& str){
	int k;
	cin>>k;
	if(k==str.size()){
		return ;
	}
	reverse(str,0,k-1);
	reverse(str,k,str.size()-1);
	reverse(str,0,str.size()-1);
}

void cmd4(string& str){
	int i,j;
	cin>>i>>j;
	int c=1;
	for(int t=i-1;t<=j-1;t++){
		str[t]=  (str[t]-'A'+c)%26 +'A';
		c++;
	}
}
int main(){
	int N,M;
	cin>>N>>M;
	string str;
	cin>>str;
	while(M>0){
		M--;
		string cmd;
		cin>>cmd;
		int id;
		cin>>id;
		if(id==1){
			cmd1(str);
		}
		if(id==2){
			cmd2(str);
		}
		if(id==3){
			cmd3(str);
		}
		if(id==4){
			cmd4(str);
		}
	}
	cout<<str<<endl;
}


