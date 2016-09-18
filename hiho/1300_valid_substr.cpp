#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <cstring> //memset
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define CLR(a, b) memset(a, b, sizeof(a))


int main(){
	string str;
	cin>>str;
	vector<LL> pos_of_left;
	vector<LL> dp;
	pos_of_left.resize(str.size());
	dp.resize(str.size());
	stack<LL> stk;
	for(LL i=0;i<str.size();i++){
		if(str[i]=='('){
			stk.push(i);
		} else {
			if(stk.size()==0){
				pos_of_left[i]=-1;
			} else {
				pos_of_left[i]=stk.top();
				stk.pop();
			}
		}
	}
	for(LL i=0;i<str.size();i++){
		if(str[i]==')' && pos_of_left[i]!=-1){
			LL left=pos_of_left[i];
			if(left==0 ){
				dp[i]=1;
			} else {
				dp[i]=dp[left-1]+1;
			}
		}
	}
	LL total=0;
	for(LL i=0;i<dp.size();i++){
		total+=dp[i];
	}
	cout<<total<<endl;
}


