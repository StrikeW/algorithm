#include <iostream>
#include <vector>
using namespace std;
int count_bit(int Q){
	int count=0;
	while(Q!=0){
		if(Q%2==1)
			count++;
		Q=Q>>1;
	}
	return count;
}
vector<bool> valid_state(int M,int Q){
	vector<bool> vec;
	vec.resize(1<<M);
	for(int i=0;i<vec.size();i++){
		if(count_bit(i)<=Q)
			vec[i]=true;
		else
			vec[i]=false;
	}
	return vec;
}
//current state=i
//next state=((((1<<M)-1)>>1)&i)
int compress(int N,int M,int Q,vector<int>& value){
	vector<bool> state=valid_state(M,Q);
	vector<int> current;
	int current_N=1;
	current.resize(state.size());
	current[1]=value[0];
	while(current_N<N){
		vector<int> next;
		next.resize(state.size());
		for(int i=0;i<current.size();i++){
			if(state[i]){
				int next_i=i<<1;
				if(next_i>= (1<<M))
					next_i-=(1<<M);
				if(next[next_i]<current[i])
					next[next_i]=current[i];
				if(state[next_i+1] && next[next_i+1]<current[i]+value[current_N])
					next[next_i+1]=current[i]+value[current_N];
			}
		}
		current_N++;
		current=next;
	}
	int max=0;
	for(int i=0;i<current.size();i++){
		if(current[i]>max)
			max=current[i];
	}
	return max;
} 
int main(){
	int N,M,Q;
	cin>>N>>M>>Q;
	vector<int> value;
	value.resize(N);
	for(int i=0;i<N;i++){
		cin>>value[i];
	}
	cout<<compress(N,M,Q,value)<<endl;
	return 0;
}