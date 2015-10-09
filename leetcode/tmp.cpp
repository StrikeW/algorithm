#include <vector>
#include <string>

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
                
            }
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                ops.push_back( s[i]);
                i++;
                continue;
            }
            int val=0;
            while(i<s.size() && '0'<=s[i] && s[i] <='9'){
                val*=10;
                val+=s[i]-'0';
                i++;
            }
            nums.push_back(val);
            if(ops.size()>0 && (ops[ops.size()-1]=='*' || ops[ops.size()-1]=='/')){
                char op=ops[ops.size()-1];
                ops.pop_back();
                int second=nums.back();
                nums.pop_back();
                int first=nums.back();
                nums.pop_back();
                if(op=='*'){
                    nums.push_back(first*second);
                } else {
                    nums.push_back(first/second);
                }
            }
        }
        int result=nums[0];
        for(int i=0;i<ops.size();i++){
            if(ops[i]=='+'){
                result=result+nums[i+1];
            } else {
                result=result-nums[i+1];
            }
        }
        return result;
    }
};




int main(){
    //int arr[]={10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    //vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    
    Solution s;
    cout<<s.calculate("0")<<endl;
    // vector<int> result=s.diffWaysToCompute("2*3-4*5");
    // for(int i=0;i<result.size();i++)
    //     cout<<result[i]<<endl;
//    cout<<s.threeSum(v).size()<<endl;


}
