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


LL f[20][10];
LL num[20];
LL dfs(LL i, LL s, bool e) {
    if (i==0) return s!=4 && s!=7;
    if (!e && f[i][s]!=0) return f[i][s];
    LL res = 0;
    LL u = e?num[i-1]:9;
    for (LL d = 0; d <= u; ++d){
    	if(d==4 ||  d==7 ){
    		continue;
    	}
        res += dfs(i-1, d , e&&(d==u));
    }
    return e?res:f[i][s]=res;
}
LL solve(LL n){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	LL len=0;
	while(n>0){
		num[len]=n%10;
		n=n/10;
		len++;
	}
	return dfs(len,0,true);
}
LL numberofgood(LL n){
	return n- (solve(n) - solve(0));
}

LL binary_search(LL target,LL begin,LL end){
	if(end<begin){
		return -1;
	}
	LL mid=begin+(end-begin)/2;
	LL m_val=numberofgood(mid);
	if(m_val<target){
		return binary_search(target,mid+1,end);
	} else if(m_val>target){
		return binary_search(target,begin,mid-1);
	} else {
		LL b_val=binary_search(target,begin,mid-1);
		if(b_val==-1){
			return mid;
		} else {
			return b_val;
		}
	}
}
int main(){
	CLR(f,0);
	CLR(num,0);
	LL a;
	cin>>a;
	LL end=100000000000000000L;
	cout<<binary_search(a,1,LONG_MAX)<<endl;
//	cout<<numberofgood(a)<<endl;
}