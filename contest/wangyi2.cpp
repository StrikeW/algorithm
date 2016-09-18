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
using namespace std;

class keyboard{
public:
    vector<string> data;
    void read_data(){
        data.push_back("..........");
        for(int i=0;i<8;i++){
            string tmp;
            cin>>tmp;
            tmp="."+tmp+".";
            data.push_back(tmp);
        }
        data.push_back("..........");
    }
    void put(int x,int y,int color){
        char input;
        char another;
        if(color==0){
            input='*';
            another='o';
        } else {
            input='o';
            another='*';
        }
        data[x+1][y+1]=input;
        int x_array[8]={1,-1,0,0,1,1,-1,-1};
        int y_array[8]={0,0,1,-1,1,-1,1,-1};
        for(int i=0;i<8;i++){
            int curr_x=x+1 + x_array[i];
            int curr_y=y+1 + y_array[i];
            bool replace=false;
            while(true){
                if(data[curr_x][curr_y]=='.'){
                    break;
                }
                if(data[curr_x][curr_y]==another){
                    curr_x += x_array[i];
                    curr_y += y_array[i];
                    continue;
                }
                if(data[curr_x][curr_y]==input){
                    replace=true;
                    break;
                }
            }
            if(replace){
                curr_x=x+1 + x_array[i];
                curr_y=y+1 + y_array[i];
                while(true){
                    if(data[curr_x][curr_y]==another){
                        data[curr_x][curr_y]=input;
                        curr_x += x_array[i];
                        curr_y += y_array[i];
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    void final(){
        int black=0;
        int white=0;
        for(int i=0;i<data.size();i++){
            for(int j=0;j<data[i].size();j++){
                if(data[i][j]=='*'){
                    black++;
                }
                if(data[i][j]=='o'){
                    white++;
                }
            }
        }
        cout<<black<<" "<<white<<endl;
    }
};
int main(){
    int S;
    cin>>S;
    for(int i=0;i<S;i++){
        keyboard board;
        board.read_data();
        int N;
        cin>>N;
        for(int j=0;j<N;j++){
            int a,b,c;
            cin>>a>>b>>c;
            board.put(a,b,c);
        }
        board.final();
    }
}
