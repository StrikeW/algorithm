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
#include <unordered_map>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define CLR(a, b) memset(a, b, sizeof(a))
#define MOD 1000000007

struct node{
	LL sum;
	LL count;
	node(){
		sum=0;
		count=-1;
	}
};
node dp[20][10][202];
LL ten[20];
node dfs(int len,int digit,int k,bool limit,vector<int>& target){
	if(!limit && dp[len][digit][k].count!=-1){
		return dp[len][digit][k];
	}
	if(len==1){
		if(digit==k){
			dp[len][digit][k].count=1;
			dp[len][digit][k].sum=digit;
		} else {
			dp[len][digit][k].count=0;	
		}
		return dp[len][digit][k];
	}
	int head=0;
	if(len==target.size()){
		head=1;
	}
	int tail=9;
	if(limit){
		tail=target[len-1];
	}
	node result;
	for(int i=head;i<=tail;i++){
		int new_limit=false;
		if(limit && (i==tail)){
			new_limit=true;
		}
		node tmp= dfs(len-1,i,i-k,new_limit,target);
		result.count+=tmp.count;
		result.sum+=tmp.sum+ tmp.count * i * ten[len];
	}
	if(!limit){
		dp[len][digit][k]=result;
	}
	return result;
}
LL calculate(LL target,int k){
	if(target==0){
		return k==0;
	}
	vector<int> digits;
	while(target>0){
		digits.push_back(target%10);
		target=target/10;
	}
	return dfs(digits.size(),0,k+100,true,digits).sum;
}
int main(){
	ten[1]=1;
	for(LL len=2;len<=19;len++){
		ten[len]=(ten[len-1]*10) % MOD;
	}
	cout<<calculate(121,0)<<endl;
}









