#include <iostream>
#include <vector>
//f[i][v] means knapsack size == v , and consider whether to put item i
//f[i][v]=max{ f[i-1][v], f[i-1][v-w[i]]+v[i] }
//final result = max{f[N][M],f[N][M-1],...,f[N][0]}
using namespace std;
int knapsack(int N,int M,vector<int>& weight, vector<int>& value){
	//weight and value size == M+1, first item is used for padding
	vector<vector<int> >f;
	f.resize(N+1);
	for(int i=0;i<N+1;i++){
		f[i].resize(M+1);
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(j<weight[i]){
				// cannot choose it 
				f[i][j]=f[i-1][j];
			} else {
				f[i][j]=max(f[i-1][j],f[i-1][j-weight[i]]+value[i]);
			}
		}
	}
	int max_value=0;
	for(int i=1;i<=M;i++){
		if(f[N][i]>max_value)
			max_value=f[N][i];
	}
	return max_value;
}
int knapsack_save_space(int N,int M,vector<int>& weight, vector<int>& value){
	//weight and value size == M+1, first item is used for padding
	vector<int> f;
	f.resize(M+1);
	for(int i=1;i<=N;i++){
		for(int j=M;j>=1;j--){
			if(j<weight[i]){
				// do nothing
			} else {
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
			}
		}
	}
	int max_value=0;
	for(int i=1;i<=M;i++){
		if(f[i]>max_value)
			max_value=f[i];
	}
	return max_value;
}
int main(){
	int N,M;
	cin >>N>>M;
	vector<int> weight;
	vector<int> value;
	weight.push_back(0);
	value.push_back(0);
	int count=0;
	while(count<N){
		count++;
		int A,B;
		cin>>A>>B;
		weight.push_back(A);
		value.push_back(B);
	}
	cout<<knapsack_save_space(N,M,weight,value)<<endl;
}





