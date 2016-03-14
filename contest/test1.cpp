#include <iostream>
using namespace std;
int data[3][3];
bool recover_row(int i){
    int count=0;
    int sum=0;
    for(int j=0;j<3;j++){
        if(data[i][j]!=0){
            count++;
            sum+=data[i][j];
        }
    }
    if(count!=2){
        return false;
    }
    for(int j=0;j<3;j++){
        if(data[i][j]==0){
            data[i][j]=15-sum;
        }
    }
    return true;
}
bool recover_column(int j){
    int count=0;
    int sum=0;
    for(int i=0;i<3;i++){
        if(data[i][j]!=0){
            count++;
            sum+=data[i][j];
        }
    }
    if(count!=2){
        return false;
    }
    for(int i=0;i<3;i++){
        if(data[i][j]==0){
            data[i][j]=15-sum;
        }
    }
    return true;
}

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>data[i][j];
        }
    }
    if(data[1][1]==0){
        data[1][1]=5;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int ii=2-i;
            int jj=2-j;
            if(data[i][j]!=0 &&data[ii][jj]==0 ){
                data[ii][jj]=10-data[i][j];
            }
        }
    }
    while(true){
        bool success=false;
        for(int i=0;i<3;i++){
            if(recover_row(i)){
                success=true;
            }
            if(recover_column(i)){
                success=true;
            }
        }
        if(!success){
            break;
        }
    }
    if(data[0][1]!=0 && data[1][0]!=0){
        if(data[0][1]+data[1][0]==12){
            data[0][0]=4;
        }
        if(data[0][1]+data[1][0]==16){
            data[0][0]=2;
        }
        if(data[0][1]+data[1][0]==8){
            data[0][0]=6;
        }
        if(data[0][1]+data[1][0]==4){
            data[0][0]=8;
        }
    }
    while(true){
        bool success=false;
        for(int i=0;i<3;i++){
            if(recover_row(i)){
                success=true;
            }
            if(recover_column(i)){
                success=true;
            }
        }
        if(!success){
            break;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(data[i][j]==0){
                cout<<"Too Many";
                return 0;
            }
        }
    }
    for(int i=0;i<3;i++){
        cout<<data[i][0]<<" "<<data[i][1]<<" "<<data[i][2]<<endl;
    }
    return 0;
}
