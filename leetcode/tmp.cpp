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
    int binary_search_left(vector<int>& nums, int target,int start,int end){
        if(start>=end)
            return -1;
        if(start+1==end){
            if(nums[start]==target)
                return start;
            return -1;
        }
        int mid=(start+end)/2;
        if(nums[mid]<target)
            return binary_search_left(nums,target,mid+1,end);
        if(nums[mid]>target)
            return binary_search_left(nums,target,start,mid);
        if(nums[mid]==target){
            int r=binary_search_left(nums,target,start,mid);
            if(r==-1)
                return mid;
            return r;
        }
    }
    int binary_search_right(vector<int>& nums, int target,int start,int end){
        if(start>=end)
            return -1;
        if(start+1==end){
            if(nums[start]==target)
                return start;
            return -1;
        }
        int mid=(start+end)/2;
        if(nums[mid]<target)
            return binary_search_right(nums,target,mid+1,end);
        if(nums[mid]>target)
            return binary_search_right(nums,target,start,mid);
        if(nums[mid]==target){
            int r=binary_search_right(nums,target,mid+1,end);
            if(r==-1)
                return mid;
            return r;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(binary_search_left(nums,target,0,nums.size()));
        result.push_back(binary_search_right(nums,target,0,nums.size()));
        return result;
    }
};


int main(){
    int arr[]={1};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    cout<<s.searchRange(nums,1).size()<<endl;
}
