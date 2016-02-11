#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    struct Node{
        long long val,smaller;
        Node* left;
        Node* right;
        Node(long long v,long long s){
            left=NULL;
            right=NULL;
            val=v;
            smaller=s;
        }
    };
    void insert(Node* & root,long long v){
        if(root==NULL){
            root=new Node(v,0);
            return ;
        }
        if(v< root->val){
            root->smaller++;
            insert((root->left),v);
        } else {
            insert((root->right),v);
            return ;
        }
    }
    long long count_smaller_than(Node* & root,long long v){
        if(root==NULL){
            return 0;
        }
        if(v < root->val){
            return count_smaller_than(root->left,v);
        } else if(v == root->val){
            return root->smaller;
        } else {
            return 1+root->smaller+count_smaller_than(root->right,v);
        }
    }
    long long countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix_sum;
        long long sum=0;
        prefix_sum.push_back(sum);
        for(long long i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix_sum.push_back(sum);
        }
        long long ret=0;
        Node* root=NULL;
        //tmp= lower<=Scurrent-Si<=upper ?
        //tmp1: Si<= Scurrent-lower
        //tmp2: Si< Scurrent-upper
        //tmp=tmp1-tmp2
        for(long long i=0;i<prefix_sum.size();i++){
            ret+=count_smaller_than(root,prefix_sum[i]-lower+1)-
                count_smaller_than(root,prefix_sum[i]-upper);
            insert(root,prefix_sum[i]);
        }
        return ret;
    }
};

int main(){
    int a[] = {2147483647,-2147483648,-1,0};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> a_vec(a,a+a_len);
    Solution s;
    cout<<s.countRangeSum(a_vec,-1,0)<<endl;
}
