//hiho 1049 
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string get_postorder(string preorder,string inorder){
	if(preorder=="")
		return "";
	char root=preorder[0];
	int root_pos=inorder.find(root);// it means left tree size = root_pos
	string left_preorder=preorder.substr(1,root_pos); //[1,root_pos]
	string right_preorder=preorder.substr(1+root_pos);// [root_pos+1,end]

	string left_inorder=inorder.substr(0,root_pos); //[0,root_pos-1]
	string right_inorder=inorder.substr(1+root_pos);  //[root_pos+1,end]

	string middle=" ";
	middle[0]=root;
	return get_postorder(left_preorder,left_inorder)+get_postorder(right_preorder,right_inorder)+middle;

}
int main(){
	string preorder;
	string inorder;
	cin>>preorder>>inorder;
	cout<<get_postorder(preorder,inorder)<<endl;
}
