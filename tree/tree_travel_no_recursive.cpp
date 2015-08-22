#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void pre_order(TreeNode * root){
	stack<TreeNode *> s;
	if(root==NULL)
		return ;
	s.push(root);
	while(s.size()>0){
		TreeNode * curr=s.top();
		s.pop();
		cout<<curr->val;
		if(curr->right!=NULL)
			s.push(curr->right);
		if(curr->left!=NULL)
			s.push(curr->left);
	}
	cout<<endl;
}

struct entry{
	TreeNode * ptr;
	bool visited;
	entry(TreeNode * p,bool v){
		ptr=p;
		visited=v;
	}
};
void in_order(TreeNode * root){
	if(root==NULL)
		return ;
	stack< entry > s;
	s.push(entry(root, false));
	while(s.size()>0){
		entry curr=s.top();
		s.pop();
		if(!curr.visited){
			if(curr.ptr->right!=NULL)
				s.push(entry(curr.ptr->right,false));
	
			s.push(entry(curr.ptr,true));
			
			if(curr.ptr->left!=NULL)
				s.push(entry(curr.ptr->left,false));
			

		} else {
			cout<<curr.ptr->val;
		}
	}
	cout<<endl;
}

void post_order(TreeNode * root){
	if(root==NULL)
		return ;
	stack< entry > s;
	s.push(entry(root, false));
	while(s.size()>0){
		entry curr=s.top();
		s.pop();
		if(!curr.visited){
			s.push(entry(curr.ptr,true));

			if(curr.ptr->right!=NULL)
				s.push(entry(curr.ptr->right,false));
			
			if(curr.ptr->left!=NULL)
				s.push(entry(curr.ptr->left,false));
			
			
		} else {
			cout<<curr.ptr->val;
		}
	}
	cout<<endl;
}

int main(){
	TreeNode * r1=new TreeNode(1);
	TreeNode * r2=new TreeNode(2);
	TreeNode * r3=new TreeNode(3);
	TreeNode * r4=new TreeNode(4);
	TreeNode * r5=new TreeNode(5);
	TreeNode * r6=new TreeNode(6);
	TreeNode * r7=new TreeNode(7);
	r1->left=r2;
	r1->right=r3;
	r2->left=r4;
	r2->right=r5;
	r3->left=r6;
	r3->right=r7;
	//	   1
	//	 2	 3
	//  4 5 6 7
	pre_order(r1);	//1245367
	in_order(r1);  //4251637
	post_order(r1);//4526371
}