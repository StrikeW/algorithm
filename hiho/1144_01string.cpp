#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	
	if(n>=m){
		//010101...01000000
		while(m>0){
			printf("%d%d",0,1);
			n--;
			m--;
		}
		while(n>0){
			printf("%d",0);
			n--;
		}
		printf("\n");
	} else if(n+1==m){
		//10101...0101
		while(n>0){
			printf("%d%d",1,0);
			n--;
		}
		printf("1\n");
	} else {
		printf("NO\n");
	}

}