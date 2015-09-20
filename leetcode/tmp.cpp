#include <vector>
#include <string>

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    vector<vector<vector<int> > > dp;
    void compute(vector<int>& numbers,vector<char>& ops,int start,int end){
        vector<int> result;
        if(start==end){
            dp[start][start].push_back(numbers[start]);
            return ;
        }
        // 0 1 2 3
        // 2*3+4-5
        for(int mid=start;mid<end;mid++){
            if(dp[start][mid].size()==0)
                compute(numbers,ops,start,mid);
            if(dp[mid+1][end].size()==0)
                compute(numbers,ops,mid+1,end);
            for(int i=0;i<dp[start][mid].size();i++){
                for(int j=0;j<dp[mid+1][end].size();j++){
                    if(ops[mid]=='+')
                        dp[start][end].push_back(dp[start][mid][i] + dp[mid+1][end][j]);
                    else if (ops[mid]=='-')   
                        dp[start][end].push_back(dp[start][mid][i] - dp[mid+1][end][j]);
                    else
                        dp[start][end].push_back(dp[start][mid][i] * dp[mid+1][end][j]);
                }
            }
        }
    }
    vector<int> diffWaysToCompute(string input) {
        //parse the input first
        vector<int> numbers;
        vector<char> ops;
        bool meet_op=false;
        for(int i=0;i<input.size();i++){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                ops.push_back(input[i]);
                meet_op=true;
                continue;
            }
            if(i==0 || meet_op){
                numbers.push_back(input[i]-'0');
            } else {
                numbers.back()=numbers.back()*10+(input[i]-'0');
            }
            meet_op=false;
        }
        //calculate
        dp.clear();
        dp.resize(numbers.size());
        for(int i=0;i<dp.size();i++){
            dp[i].resize(numbers.size());
        }
        compute(numbers,ops,0,numbers.size()-1);
        return dp[0][numbers.size()-1];
    }
};




int main(){
    //int arr[]={10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    //vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    
    Solution s;
    vector<int> result=s.diffWaysToCompute("2*3-4*5");
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
//    cout<<s.threeSum(v).size()<<endl;


}
