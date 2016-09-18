#include <iostream>
#include <queue>

using namespace std;

void int_queue(){
	//largest first
	priority_queue<int,vector<int> > int_queue;
	// the same as the following 
	//priority_queue<int,vector<int>,less<int> > int_queue;
	int_queue.push(1);
	int_queue.push(3);
	int_queue.push(2);
	while(int_queue.size()>0){
		cout<<int_queue.top()<<endl;
		int_queue.pop();
	}	
}

void int2_queue(){
	//smallest first
	priority_queue<int,vector<int>,greater<int> > int_queue;
	int_queue.push(1);
	int_queue.push(3);
	int_queue.push(2);
	while(int_queue.size()>0){
		cout<<int_queue.top()<<endl;
		int_queue.pop();
	}		
}
struct point{
	int x;
	int y;
	point(int _x,int _y):x(_x),y(_y){}
};
struct cmp{  
	bool operator()(point a,point b){  
		if(a.x==b.x)
			return a.y<b.y;
		return a.x<b.x;
	}  
};
void point_queue(){
	//largest first
	priority_queue<point,vector<point>,cmp > p_queue;
	p_queue.push(point(1,4));
	p_queue.push(point(2,3));
	p_queue.push(point(2,2));
	while(p_queue.size()>0){
		cout<<p_queue.top().x<< ","<< p_queue.top().y<<endl;
		p_queue.pop();
	}	
}

int main(){
	priority_queue<int> int_queue;
	int_queue.push(1);
	int_queue.push(3);
	int_queue.push(2);
	while(int_queue.size()>0){
		cout<<int_queue.top()<<endl;
		int_queue.pop();
	}	
//	point_queue();
}