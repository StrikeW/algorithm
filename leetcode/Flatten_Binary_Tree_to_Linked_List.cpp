#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void flatten_helper(TreeNode* root,vector<TreeNode*>& vec){
        if(!root)
            return;
        vec.push_back(root);
        flatten_helper(root->left,vec);
        flatten_helper(root->right,vec);
	}
    void flatten(TreeNode* root) {
    	vector<TreeNode*> vec;
    	if(!root)
    		return ;
    	flatten_helper(root,vec);
    	vec[0]->left=nullptr;
    	for(int i=1;i<vec.size();i++){
    	    vec[i]->left=vec[i-1];
    	}
    	for(int i=0;i<vec.size()-1;i++){
    	    vec[i]->right=vec[i+1];
    	}
    	vec[vec.size()-1]->right=nullptr;
    	        
    	
    }
};

int main(){
	Solution s;
	TreeNode* n1=new TreeNode(1);
	TreeNode* n2=new TreeNode(2);
	n1->right=n2;
	s.flatten(n1);
}