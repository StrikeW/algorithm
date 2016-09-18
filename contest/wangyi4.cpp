#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <cstring> //memset
#include <string> //memset
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

struct user{
    int id;
    int t;
    int s;
    int e;
    int enter_t;
    int click_level;
};
bool t_cmp(user u0,user u1){
    //largest first
    return u0.t > u1.t;
}

class elevator{
    int curr_t;
    int curr_level;
    int waiting_goup;
    int waiting_godown;
public:
    int direction;
    vector<user> user_vec;
    vector<user> coming_list;
    // vector<vector<int > > wait_lists;
    // vector<int > leaving_lists;
    vector<vector<int > > wait_lists;
    vector<int > leaving_lists;
    void print(){
        for(int i=0;i<user_vec.size();i++){
            cout<<user_vec[i].enter_t-user_vec[i].t<<endl;
        }
        cout<<endl;
    }
    void init(){
        curr_t=1;
        curr_level=1;
        direction=0;
        waiting_goup=0;
        waiting_godown=0;

        int N;
        cin>>N;
        int max_level=1;
        for(int i=0;i<N;i++){
            user u;
            u.id=i;
            cin>>u.t>>u.s>>u.e;
            if(u.s>max_level){
                max_level=u.s;
            }
            if(u.e>max_level){
                max_level=u.e;
            }
            user_vec.push_back(u);
        }
        wait_lists.resize(max_level+1);
        leaving_lists.resize(max_level+1);
        coming_list=user_vec;
        sort(coming_list.begin(),coming_list.end(),t_cmp);
    }
    void update(){
        if(direction==0 && coming_list.size()>0 && coming_list.back().t>curr_t){
            curr_t=coming_list.back().t;
        }
        while(coming_list.size()>0 && coming_list.back().t==curr_t){
            int id=coming_list.back().id;
            coming_list.pop_back();
            // handle click
            //step1. add to wait_lists
            user_vec[id].click_level=curr_level;
            wait_lists[user_vec[id].s].push_back(id);
            if(user_vec[id].s<curr_level){
                waiting_godown++;
            }
            if(user_vec[id].s>curr_level){
                waiting_goup++;
            }

            //leaving_lists[user_vec[id].e]++;
            //TODO
        }
        //pick user
        for(int i=0;i<wait_lists[curr_level].size();i++){
            int id=wait_lists[curr_level][i];
            user_vec[id].enter_t=curr_t;
            if(user_vec[id].click_level>curr_level){
                waiting_godown--;
            }
            if(user_vec[id].click_level<curr_level){
                waiting_goup--;
            }
            leaving_lists[user_vec[id].e]++;
            if(user_vec[id].e<curr_level){
                waiting_godown++;
            }
            if(user_vec[id].e>curr_level){
                waiting_goup++;
            }
        }
        wait_lists[curr_level].clear();

        //leave user
        if(direction>0 && leaving_lists[curr_level]>0){
            waiting_goup-=leaving_lists[curr_level];
            leaving_lists[curr_level]=0;
        }
        if(direction<0 && leaving_lists[curr_level]>0){
            waiting_godown-=leaving_lists[curr_level];
            leaving_lists[curr_level]=0;
        }

        if(direction>0 ){
            if(waiting_goup>0){
                curr_level++;
                direction=1;
            } else if(waiting_godown>0){
                curr_level--;
                direction=-1;
            } else {
                direction=0;
            }
        } else if(direction < 0 ){
            if(waiting_godown>0){
                curr_level--;
                direction=-1;
            } else if(waiting_goup>0){
                curr_level++;
                direction=1;
            } else {
                direction=0;
            }
        } else {
            if(waiting_goup>0){
                curr_level++;
                direction=1;
            } else if(waiting_godown>0){
                curr_level--;
                direction=-1;
            } else {
                direction=0;
            }
        }

        curr_t ++;
        //decide direction
    }
};
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        elevator eva;
        eva.init();
        while(eva.coming_list.size()>0 || eva.direction!=0){
            eva.update();
        }
        eva.print();
    }
}
