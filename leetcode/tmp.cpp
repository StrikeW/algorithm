#include <vector>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool binary_search(vector<int>& nums,int start,int end,int target){
        if(start>=end)
            return false;
        if(start+1==end)
            return nums[start]==target;
        int mid=(start+end)/2;
        if(nums[mid]==target)
            return true;
        if(nums[mid]<target)
            return binary_search(nums,mid+1,end,target);
        else 
            return binary_search(nums,start,mid,target);
    }
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                //find k in [j+1,nums.size() )
                int target=0-nums[i]-nums[j];
                if(binary_search(nums,j+1,nums.size(),target)){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(target);
                    result.push_back(v);
                } 
            }
        }
        return result;
    }
};


int main(){
    int arr[]={13,14,1,2,-11,-11,-1,5,-1,-11,-9,-12,5,-3,-7,-4,-12,-9,8,-13,-8,2,-6,8,11,7,7,-6,8,-9,0,6,13,-14,-15,9,12,-9,-9,-4,-4,-3,-9,-14,9,-8,-11,13,-10,13,-15,-11,0,-14,5,-4,0,-3,-3,-7,-4,12,14,-14,5,7,10,-5,13,-14,-2,-6,-9,5,-12,7,4,-8,5,1,-10,-3,5,6,-9,-5,9,6,0,14,-15,11,11,6,4,-6,-10,-1,4,-11,-8,-13,-10,-2,-1,-7,-9,10,-7,3,-4,-2,8,-13};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    cout<<s.threeSum(nums).size()<<endl;
}
