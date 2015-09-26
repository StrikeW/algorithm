#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct car{
	int l;
	double exit_time;
	car(){
		exit_time=0;
	}
};
struct point{
	bool is_start;
	int p;
	int index;
	double min_time;
	point(bool start,int i){
		is_start=start;
		index=i;
		min_time=0;
	}
};
bool point_cmp(point a,point b){
    return a.p<b.p;
}
int main(){
	int N;
	cin>>N;
	vector<car> car_vec;
	vector<point> point_vec;
	car_vec.resize(N);
	for(int i=0;i<N;i++){
		point p_start(true,i);
		point p_end(false,i);
		cin>>p_start.p;
		cin>>p_end.p;
		cin>>car_vec[i].l;
		point_vec.push_back(p_start);
		point_vec.push_back(p_end);
	}
	sort(point_vec.begin(),point_vec.end(),point_cmp);
	for(int i=point_vec.size()-1;i>=0;i--){
		if(!point_vec[i].is_start)
			continue;
		int speed=car_vec[point_vec[i].index].l;
		int iter=i;
		while(true){
			if(point_vec[iter].index == point_vec[i].index && iter!=i){
				break;
				//now iter is the end point ;
			}
			double current_time=point_vec[iter].min_time;
			double spend_time=(point_vec[iter+1].p-point_vec[iter].p)*1.0/speed;
			if(current_time+spend_time > point_vec[iter+1].min_time){
				point_vec[iter+1].min_time=current_time+spend_time;
			}
			iter++;
		}
		car_vec[point_vec[i].index].exit_time=point_vec[iter].min_time;
	}
	for(int i=0;i<car_vec.size();i++){
		printf("%0.2f\n", car_vec[i].exit_time);
	}

}