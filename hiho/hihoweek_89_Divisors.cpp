#include <iostream>

using namespace std;
#define LL long long
#define ULL unsigned long long
LL prime[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

// 第一层 2的指数从1到60都试一下, 2^i
// 第二层 3的指数从1到上一层的指数，都试一下。 3的指数没理由比2高
// 第三层 类似
// 2^2 * 3^2
LL N;
LL max_N;
LL max_factor;
void dfs(int prime_index,int max_i,LL accum,LL factor){
	if(factor>max_factor || (factor==max_factor && accum<max_N)){
		max_factor=factor;
		max_N=accum;
	}
	if(prime_index>=16){
		return ;
	}
	for(int i=1;i<=max_i;i++){
		accum=accum*prime[prime_index];
		if(accum > N){
			return ;
		}
		dfs(prime_index+1,i,accum,factor*(i+1));
	}
}
int main(){
	cin>>N;
	max_factor=0;
	dfs(0,60,1,1);
	cout<<max_N<<endl;
}