/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int count;
	TreeNode* prev;
	TreeNode* p1;
	TreeNode* p2;
	TreeNode* p3;
	TreeNode* p4;
	void in_order(TreeNode* root){
		if(root==NULL)
			return ;
		in_order(root->left);
		if(prev==NULL){
			prev=root;
		} else {
			if(root->val < prev->val){
				if(count==0){
					p1=prev;
					p2=root;
				} else {
					p3=prev;
					p4=root;
				}
				count++;
			}
			prev=root;
		}
		in_order(root->right);
	}
    void recoverTree(TreeNode* root) {
        count=0;
        prev=NULL;
        in_order(root);
        if(count==2){
        	int tmp=p1->val;
        	p1->val=p4->val;
        	p4->val=tmp;
        } else {
        	int tmp=p1->val;
        	p1->val=p2->val;
        	p2->val=tmp;
        }
    }
};