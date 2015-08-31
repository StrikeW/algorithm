#include <iostream>
#include <deque>
//	deque has following methods:
//	front(),back()
//	push_front(),pop_front(),push_back(),pop_back()
#include <queue>
//	queue has following methods:
//	front(),back()
//	push(),pop()

using namespace std;

class max_queue{
	//o(1) time to get max in a queue
	int id;
	struct entry{
		int id;
		int val;
		entry(int _id,int _val):id(_id),val(_val){}
	};
	queue<entry> v_queue;
	deque<entry> m_queue;
public:
	max_queue():id(0){
	}
	void push(int val){
		v_queue.push(entry(id,val));
		while(m_queue.size()>0 && m_queue.back().val<val)
			m_queue.pop_back();
		m_queue.push_back(entry(id,val));
		id++;
	}
	int max(){
		return m_queue.front().val;
	}
	
	void pop(){
		if(m_queue.front().id==v_queue.front().id)
			m_queue.pop_front();
		v_queue.pop();
	}

};

void test_max_queue(){
	max_queue mq;
	int array[8]={1,3,-1,-3,5,3,6,7};
	mq.push(array[0]);
	mq.push(array[1]);
	for(int i=2;i<8;i++){
		mq.push(array[i]);
		cout<<"max:"<<mq.max()<<endl;
		mq.pop();
	}
}

int main(){
	test_max_queue();
}
