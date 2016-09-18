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

// 10表示该位数，2表示是否存在235, 7表示除以7的余数
int f[20][10][2][7];
int num[20];
LL ten[20];
// 不要62和4
int dfs(int i, int s, int has_235, int mod7, bool e) {
    if (i==0) {
    	return f[0][s][has_235][mod7];
    }
    if (!e && f[i][s][has_235][mod7]!=0) return f[i][s][has_235][mod7];
    int res = 0;
    int u = e?num[i-1]:9;
    for (int d = 0; d <= u; ++d){
    	if(s==1 && d==8 ){
    		continue;
    	}
    	// mod7  =   (target_mod7 + s *ten[i-1])%7;
    	int target_mod7=(mod7+777-s*ten[i])%7;
    	//int target_mod7=(mod7+7-s)%7;
    	if(!has_235){
    		if(s==2 || s==3||s==5){
    			continue;
    		} else {
    			res += dfs(i-1, d ,0,target_mod7, e&&(d==u));
    		}
    	} else {
    		if(s==2 || s==3||s==5){
    			res += dfs(i-1, d ,0,target_mod7, e&&(d==u));
    			res += dfs(i-1, d ,1,target_mod7, e&&(d==u));
    		} else {
    			res += dfs(i-1, d ,1,target_mod7, e&&(d==u));
    		}
    	}
    }
    return e?res:f[i][s][has_235][mod7]=res;
}
LL solve(LL n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 0;
	}
	int len=0;
	while(n>0){
		num[len]=n%10;
		n=n/10;
		len++;
	}
	return dfs(len,0,1,0,true);
}

int main(){
	ten[0]=1;
	for(int i=1;i<20;i++){
		ten[i]=ten[i-1]*10;
		ten[i]=ten[i]%7;
	}
	int S;
	CLR(f,0);
	for(int i=0;i<=9;i++){
		int is_235=0;
		if(i==2||i==3||i==5){
			is_235=1;
		}
		f[0][i][is_235][i%7]++;
	}
	cin>>S;
	while(S>0){
		CLR(num,0);
		S--;
		LL N,M;
		cin>>N>>M;
		cout<<solve(M)-solve(N-1)<<endl;
	}
}



