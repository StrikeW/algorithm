#include <iostream>
#include <queue>
using namespace std;

struct candy{
	int weight;
	int others;
};
struct cmp{  
	bool operator()(candy a,candy b){  
		return a.weight<b.weight;
	}  
};

int main(){
	priority_queue<candy,vector<candy>,cmp> candy_queue;
	int N;
	cin >>N;
	while(N>0){
		N--;
		char type;
		cin>>type;
		if(type=='A'){
			candy c;
			cin>>c.weight;
			candy_queue.push(c);
		} else {
			cout<<candy_queue.top().weight<<endl;
			candy_queue.pop();
		}
	}
}