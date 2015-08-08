#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
typedef unsigned long long uint64_t ;
int data[9][9]={
	{2,2,2,0,0,0,2,2,2},
	{2,2,2,0,0,0,2,2,2},
	{2,2,2,1,1,0,2,2,2},
	{1,1,0,0,1,1,1,1,1},
	{1,1,0,0,0,0,1,1,0},
	{1,0,1,0,0,1,0,1,1},
	{2,2,2,0,0,1,2,2,2},
	{2,2,2,0,1,1,2,2,2},
	{2,2,2,1,0,1,2,2,2}
};

uint64_t data_2_uint64(){
	uint64_t result=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if((3<=i && i<6) || (3<=j && j<6)){
				result=result<<1;
				result+=data[i][j];
			}
		}
	}
	return result;
}
void uint64_2_data(uint64_t input){
	for(int i=8;i>=0;i--){
		for(int j=8;j>=0;j--){
			if((3<=i && i<6) || (3<=j && j<6)){
				data[i][j]=input%2;
				input=input>>1;
			}
		}
	}
}
void print_data(){
	printf("############################\n");
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if((3<=i && i<6) || (3<=j && j<6)){
				printf("%d ",data[i][j]);
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}
}
void shift_data(int type){
	if(type<3){
		int row=type+3;
		int tmp=data[row][0];
		for(int i=0;i<8;i++)
			data[row][i]=data[row][i+1];
		data[row][8]=tmp;
	} else if(type<6){
		int row=type;
		int tmp=data[row][8];
		for(int i=8;i>0;i--)
			data[row][i]=data[row][i-1];
		data[row][0]=tmp;
	} else if(type<9){
		int column=type-3;
		int tmp=data[0][column];
		for(int i=0;i<8;i++)
			data[i][column]=data[i+1][column];
		data[8][column]=tmp;
	} else {
		int column=type-6;
		int tmp=data[8][column];
		for(int i=8;i>0;i--)
			data[i][column]=data[i-1][column];
		data[0][column]=tmp;
	}
}
void print_type(int type){
	if(type<3){
		cout<< type << "  left"<<"\t"<<type<<endl;
	} else if(type<6){
		cout<< type-3 << "  right"<<"\t"<<type<<endl;
	} else if(type<9){
		cout<<type-6<<"  up"<<"\t"<<type<<endl;
	} else {
		cout<<type-9<<"  down"<<"\t"<<type<<endl;
	}
}
unordered_set<uint64_t> bfs_set;
struct queue_entry{
	int level;
	int type;
	uint64_t input;
	queue_entry* prev;
};
bool check_the_same_color(){
	int first=data[3][3];
	for(int i=3;i<6;i++){
		for(int j=3;j<6;j++){
			if(data[i][j]!=first)
				return false;
			}
		}
	return true;
}

queue<queue_entry*> bfs_queue;
void bfs(uint64_t input){
	queue_entry* e=new queue_entry();
	e->input=input;
	e->level=0;
	e->prev=NULL;
	bfs_queue.push(e);
	while(bfs_queue.size()>0){
		e=bfs_queue.front();
		bfs_queue.pop();
		if(bfs_set.find(e->input) !=bfs_set.end())
			continue;
		bfs_set.insert(e->input);
		for(int i=0;i<12;i++){
			uint64_2_data(e->input);
			shift_data(i);
			queue_entry* new_e=new queue_entry();
			new_e->input= data_2_uint64();
			new_e->level=e->level+1;
			new_e->type=i;
			new_e->prev=e;
			if(check_the_same_color()){
				cout<<"find in "<<new_e->level <<" step"<<endl;
				vector<int> type_array;
				while(new_e->prev!=NULL){
					type_array.push_back(new_e->type);
					new_e=new_e->prev;
					
				}
				for(int i=type_array.size()-1;i>=0;i--){
					//cout<<type_array[i]<<endl;
					print_type(type_array[i]);
				}
				return ;
			}
			bfs_queue.push(new_e);
		}
	}
}

int main(){
	uint64_t input=data_2_uint64();
	print_data();
	shift_data(3);
	print_data();
	shift_data(4);
	print_data();
	shift_data(11);
	print_data();
	bfs(input);
}