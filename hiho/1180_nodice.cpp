#include <iostream>
#include <vector>
using namespace std;
struct node{
    node(bool p1,int p2,int p3,int p4){
        is_end=p1;
        coin=p2;
        left=p3;
        right=p4;
    }
    bool is_end;
    int coin;
    int left;
    int right;
};
vector<node> create_2(){
    vector<node> result;
    result.push_back(node(false,0,1,2));
    result.push_back(node(true,0,0,0));
    result.push_back(node(true,0,0,0));
    return result;
}
vector<node> multiple(vector<node>& tree1,vector<node>& tree2){
    vector<node> result;
    int offset=tree1.size()-1;
    int times=0;
    for(int i=0;i<tree1.size();i++){
        if(!tree1[i].is_end){
            result.push_back(tree1[i]);
        } else {
            node new_node(tree2[0]);
            new_node.left=tree2[0].left+offset;
            new_node.right=tree2[0].right+offset;
            times++;
            offset+=tree2.size()-1;
            result.push_back(new_node);
        }
    }
    offset=tree1.size()-1;
    for(int i=0;i<times;i++){
        for(int j=1;j<tree2.size();j++){
            node new_node(tree2[j]);
            if(!new_node.is_end){
                new_node.left=new_node.left+offset;
                new_node.right=new_node.right+offset;
            }
            result.push_back(new_node);
        }
        offset+=tree2.size()-1;
    }
    return result;
}
vector<node> plus_1(vector<node>& tree){
    vector<node> result;
    result.push_back(node(false,1,1,2));
    result.push_back(node(true,0,0,0));
    result.push_back(tree[0]);
    result[2].left=result[2].left+2;
    result[2].right=result[2].right+2;
    for(int j=1;j<tree.size();j++){
        node new_node(tree[j]);
        if(!new_node.is_end){
            new_node.left=new_node.left+2;
            new_node.right=new_node.right+2;
        }
        result.push_back(new_node);
    }
    return result;
}
void print_tree(vector<node>& tree,int second_coin){
    cout<<"YES"<<endl;
    cout<<1<<" "
        <<2<<" "
        <<1<<" "
        <<second_coin<<endl;
    cout<<tree.size()<<endl;    
    int face=0;
    for(int i=0;i<tree.size();i++){
        if(!tree[i].is_end){
//            cout<<i<<" :"<<"C "  <<tree[i].coin<<" "
            cout<<"C "  <<tree[i].coin<<" "
                        <<tree[i].left<<" "
                        <<tree[i].right<<endl;
        } else {
            //cout<<i<<" :"<<"E "<<face<<endl;
            cout<<"E "<<face<<endl;
            face++;
        }
    }
}
vector<node> create_tree(int N,int* second_coin){
    if(N==3 || N ==9 || N==27 || N == 81){
        *second_coin=3;
        vector<node> t2=create_2();
        vector<node> t3=plus_1(t2);
        vector<node> result=t3;
        while(N>3){
            result=multiple(result,t3);
            N=N/3;
        }
        return result;
    } else if(N==5 || N==25){
        *second_coin=5;
//        vector<node> t2=create_2();
        vector<node> t4=create_tree(4,second_coin);//multiple(t2,t2);
        vector<node> t5=plus_1(t4);
        vector<node> result=t5;
        while(N>5){
            result=multiple(result,t5);
            N=N/5;
        }
        return result;
    } else if(N%2==0){
        if(N==2){
            return create_2();
        } else {
            vector<node> t2=create_2();
            vector<node> half_N=create_tree(N/2,second_coin);
            if(half_N.size()==0)
                return half_N;
            else 
                return multiple(t2,half_N);
        }
    } else {
        int tmp=N-1;
        while(tmp%2==0){
            tmp=tmp/2;
        }
        if(tmp==1){
            vector<node> tree=create_tree(N-1,second_coin);
            vector<node> result=plus_1(tree);
            *second_coin=N;
            return result;
        } else {
            return vector<node>();
        }
    }
}
int main(){


    int N=5;
    int second_coin=3;
    cin >>N;
    vector<node> result=create_tree(N,&second_coin);
    if(result.size()==0){
        cout<<"NO"<<endl;
    } else {
        print_tree(result,second_coin);
    }
    // power of 2
    // power of 2 + 1
    // (power of 2 + 1)'s power
    // anything * 2





    
    
}









