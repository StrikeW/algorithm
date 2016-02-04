#include <iostream>
#include <vector>
using namespace std;

class segtree {
public:
	struct segnode{
		int start;
		int end;
		int sum;
		segnode * left;
		segnode * right;
	};
	segnode* build(vector<int> &nums,int start,int end){
		segnode* node=new segnode();
		node->start=start;
		node->end=end;
		if(start==end){
			node->left=NULL;
			node->right=NULL;
			node->sum=nums[start];
		} else {
			int middle=(start+end)/2;
			node->left=build(nums,start,middle);
			node->right=build(nums,middle+1,end);
			node->sum=node->left->sum+node->right->sum;
		}
		return node;
	}
	int sumRange(segnode* node,int i,int j){
		if(i==node->start && j ==node->end)
			return node->sum;
		// so [i,j] belongs to [start,end]
		int middle=node->left->end;
		if(j<=middle)
			return sumRange(node->left,i,j);
		else if(i >=middle+1)
			return sumRange(node->right,i,j);
		else {
			return sumRange(node->left,i,middle)+sumRange(node->right,middle+1,j);
		}
	}
	void update(segnode* node,int i,int val){
		if(i==node->start && i==node->end){
			node->sum=val;
			return ;
		}
		// so [i,j] belongs to [start,end]
		int middle=node->left->end;
		if(i<=middle){
			update(node->left,i,val);
		} else if(i >=middle+1){
			update(node->right,i,val);
		} 
		node->sum=node->left->sum+node->right->sum;
	}
	segnode* root;
    segtree(vector<int> &nums) {
    	root=build(nums,0,nums.size()-1);
    }

    void update(int i, int val) {
        update(root,i,val);
    }

    int sumRange(int i, int j) {
        return sumRange(root,i,j);
    }

};

int main(){
	int a[] = {3,2,5,4,1};
    vector<int> v(a,a+5);
    segtree s(v);

}