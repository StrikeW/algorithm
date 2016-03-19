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

struct line{
	int x0,y0,x1,y1;
	int type;
	void lineswap(){
		swap(x0,x1);
		swap(y0,y1);
	}
	int len(){
		return max(abs(x1-x0) , abs(y1-y0) );
	}
	line(){};
	void set_type(){
		if(y0==y1){ // 0
			type=0;
			if(x0>x1){
				lineswap();
			}
		} else if(x0==x1){ // 90
			type=1;
			if(y0>y1){
				lineswap();
			}
		} else if((y1-y0)==(x1-x0)){ //45
			type=2;
			if(x0>x1){
				lineswap();
			}
		} else { //135
			type=3;
			if(x0>x1){
				lineswap();
			}
		}
	}
	bool overlap(line another){
		if(type !=another.type){
			return false;
		}
		if(type==0){
			if (y0!=another.y0){
				return false;
			}
		}
		if(type==1){
			if (x0!=another.x0){
				return false;
			}
		}
		if(type==2 ){
			if (y0-x0!=another.y0-another.x0){
				return false;
			}
		}
		if(type==3 ){
			if (y0+x0!=another.y0+another.x0){
				return false;
			}
		}
		line possible_merge_line=merge(another);
		if(possible_merge_line.len()<=len()+another.len()){
			return true;
		}
		return false;
	}

	line merge(line another){
		line result;
		if(type==0){
			result.y0=y0;
			result.y1=y1;
			result.x0=min(x0,another.x0);
			result.x1=max(x1,another.x1);
		}
		if(type==1){
			result.x0=x0;
			result.x1=x1;
			result.y0=min(y0,another.y0);
			result.y1=max(y1,another.y1);
		}
		if(type==2 || type ==3){
			if(x0<another.x0){
				result.x0=x0;
				result.y0=y0;
			} else {
				result.x0=another.x0;
				result.y0=another.y0;
			}
			if(x1<another.x1){
				result.x1=another.x1;
				result.y1=another.y1;
			} else {
				result.x1=x1;
				result.y1=y1;
			}
		}
		result.set_type();
		return result;
	}
};	
int main(){

	int S;
	cin>>S;
	while(S>0){
		S--;
		int N;
		cin>>N;
		vector<line> line_vec;
		while(N>0){
			N--;
			line newline;
			cin>>newline.x0>>newline.y0>>newline.x1>>newline.y1;
			newline.set_type();
			line_vec.push_back(newline);
		}
		int sum_lines=0;
		while(line_vec.size()!=0){
			line last=line_vec.back();
			line_vec.pop_back();
			sum_lines++;
			for(int i=0;i<line_vec.size();i++){
				if(line_vec[i].overlap(last)) {
					line_vec[i]=line_vec[i].merge(last);
					sum_lines--;
					break;
				}
			}
		}
		cout<<sum_lines<<endl;

	}
}