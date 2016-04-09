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
	int N;
	vector<bool> is_prime;
	vector<int> prime_list;
	//N=atoi(argv[1]);
	cin>>N;
	is_prime.resize(N+1,true);
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=1;i<=N;i++){
		if(is_prime[i]){
			prime_list.push_back(i);
		}
		for(int j=0;j<prime_list.size();j++){
			if(i*prime_list[j]>N){
				break;
			}
			is_prime[ i*prime_list[j] ] =false;
			if(i % prime_list[j] ==0 ){
				break;
			}
		}
	}
	cout<<prime_list.size()<<endl;
}