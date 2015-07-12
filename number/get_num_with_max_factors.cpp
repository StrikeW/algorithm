/*
题目要求的是小于等于N的数中，因子个数最多的数
首先，最多只用到16个素数，再之后就太大了。
其次是前面用的素数肯定要大于等于后面用的素数。
然后用深度优先搜索

*/

#include <iostream>

using namespace std;
typedef long long int64;
int64 prime[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int64 val;
int64 sum;
int64 N;
void dfs(int p,int e,int64 v,int64 s){
	if(p>=16)
		return ;
	if(v>N)
		return ;
	if(s>sum){
		sum=s;
		val=v;
	} else if(s==sum && val>v){
		val=v;
	}
	for(int i=1;i<=e;i++){
		double tmp=v;
		if(tmp*prime[p]>N)
			break;
		v=v*prime[p];
		dfs(p+1,i,v,s*(i+1));
	}
}
int main(){
	val=1;
	sum=1;
	cin>>N;
//	cout<<N<<endl;
	dfs(0,60,1,1);
	cout<<val<<endl;

}