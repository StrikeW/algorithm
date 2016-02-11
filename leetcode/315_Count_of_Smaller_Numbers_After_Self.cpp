#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    struct Node{
        int val,smaller;
        Node* left;
        Node* right;
        Node(int v,int s){
            left=NULL;
            right=NULL;
            val=v;
            smaller=s;
        }
    };
    int insert(Node* & root,int v){
        if(root==NULL){
            root=new Node(v,0);
            return 0;
        }
        if(v< root->val){
            root->smaller++;
            return insert((root->left),v);
        } else if(v==root->val){
            insert((root->right),v);
            return root->smaller;
        } else {
            return 1+root->smaller+insert((root->right),v);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        Node* root=NULL;
        result.resize(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            result[i]=insert(root,nums[i]);
        }
        return result;
    }
};

int main(){
    int a[] = {5,2,6,1};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> a_vec(a,a+a_len);
    Solution s;
    vector<int> ret=s.countSmaller(a_vec);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<endl;
    }
}
