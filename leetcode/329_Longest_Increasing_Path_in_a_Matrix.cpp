#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    vector<vector<int> > score_matrix;
    int bfs(vector<vector<int> >& matrix,int x,int y){
        int max_score=0;
        queue<pair<int,int> > work_queue;
        work_queue.push(pair<int,int>(x,y));
        while(work_queue.size()>0){
            pair<int,int> current=work_queue.front();
            work_queue.pop();
            int x_offset[4]={0,0,1,-1};
            int y_offset[4]={1,-1,0,0};
            int old_value=matrix[current.first][current.second];
            int old_score=score_matrix[current.first][current.second];
            if(old_score>max_score){
                max_score=old_score;
            }
            for(int i=0;i<4;i++){
                int new_x=current.first+x_offset[i];
                int new_y=current.second+y_offset[i];
                if(new_x<0 || new_x>=matrix.size() || new_y<0 || new_y>=matrix[0].size()){
                    continue;
                }
                int new_value=matrix[new_x][new_y] ;
                int new_score=score_matrix[new_x][new_y] ;
                if(new_value > old_value && old_score+1>new_score){
                    score_matrix[new_x][new_y]=old_score+1;
                    work_queue.push(pair<int,int>(new_x,new_y));
                }
            }
        }
        return max_score;
    }
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        score_matrix.clear();
        score_matrix.resize(matrix.size());
        for(int i=0;i<matrix.size();i++){
            score_matrix[i].resize(matrix[i].size(),1);
        }
        int max_score=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                max_score=max(max_score,bfs(matrix,i,j));
            }
        }
        return max_score;
    }
};

int main(){
    Solution s;
}
