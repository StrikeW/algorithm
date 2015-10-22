#include <iostream>
#include <map> 
using namespace std;

class interval_set{
public:
	map<int,int > range_map;
	void insert(int begin,int end){
		map<int,int >::iterator iter=range_map.find(begin);
		if(iter!=range_map.end()){
			if(range_map[begin]>=end){
				return ;
			} else {
				range_map[begin]=end;
			}
		} else {
			range_map[begin]=end;
			iter=range_map.find(begin);
		}
		//now we need try to merge with neighbors
		//right direction
		while(true){
			map<int,int >::iterator right_iter=iter;
			right_iter++;
			if(right_iter==range_map.end())
				break;
			if(right_iter->first<= iter->second){
				map<int,int >::iterator tmp=right_iter;
				iter->second=max(iter->second,tmp->second);
				range_map.erase(tmp);
			} else {
				break;
			}
		}
		//left direction
		while(true){
			if(iter==range_map.begin())
				break;
			map<int,int >::iterator left_iter=iter;
			left_iter--;
			if(left_iter->second >= iter->first){
				left_iter->second=max(left_iter->second,iter->second);
				range_map.erase(iter);
				iter=left_iter;
			} else {
				break;
			}
		}
	}
	bool try_malloc(int size,int* start_index){
		map<int,int >::iterator iter=range_map.begin();
		while(iter!=range_map.end()){
			if(iter->second-iter->first >= size){
				*start_index=iter->first;
				int new_start=iter->first+size;
				int new_end=iter->second;
				range_map.erase(iter);
				if(new_start!=new_end){
					range_map[new_start]=new_end;
				}
				return true;
			}
			iter++;
		}
		return false;
	}
	void print(){
		map<int,int >::iterator iter=range_map.begin();
		while(iter!=range_map.end()){
			cout<<iter->first<<","<<iter->second<<endl;
			iter++;
		}
	}
};


int main(){
	interval_set s;
	s.insert(1,2);
	s.insert(7,8);
	s.insert(5,6);
	s.insert(3,4);
	//s.print();
	s.insert(2,5);
	s.print();
	int ret;
	s.try_malloc(3,&ret);
	s.print();

}