#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct str_info{
	string str;
	vector<int> child;
	int wait;
};

struct queue_item{
	string str;
	int index;
	queue_item(string _str,int _index):str(_str),index(_index){}
};
struct cmp{  
	bool operator()(queue_item a,queue_item b){  
		return a.str>b.str;
	}  
};

int main(){
	int T;
	cin>>T;
	while(T>0){
		T--;
		int N;
		cin>>N;
		vector<str_info> info_vec;
		info_vec.resize(N);
		for(int n=0;n<N;n++){
			int m;
			cin>>info_vec[n].str>>m;
			info_vec[n].wait=m;
			while(m>0){
				m--;
				int dep;
				scanf("%d",&dep);
				//cin>>dep;
				info_vec[dep].child.push_back(n);
			}
		}

		priority_queue<queue_item,vector<queue_item>,cmp > int_queue;
		for(int n=0;n<N;n++){
			if(info_vec[n].wait==0){
				int_queue.push(queue_item(info_vec[n].str,n));
			}
		}
		vector<string> output;
		while(int_queue.size()>0){
			queue_item item=int_queue.top();
			int curr=item.index;
			int_queue.pop();
			output.push_back(item.str);
			for(int c=0;c<info_vec[curr].child.size();c++){
				int cc=info_vec[curr].child[c];
				info_vec[cc].wait--;
				if(info_vec[cc].wait==0){
					int_queue.push(queue_item(info_vec[cc].str,cc));
				}
			}
		}

		if(output.size()==N){
			for(int i=0;i<output.size();i++){
				cout<<output[i]<<endl;
			}
		} else {
			cout<<"ERROR"<<endl;
		}
		cout<<endl;
	}
}









