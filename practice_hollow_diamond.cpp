#include<iostream>
using namespace std;
int main(){
    int n = 4;
    // char character = 65;
    // int num = 1;
    // int factorials = 1;
    for(int i = 0; i<n-1;i++){
        
        for(int j = 0; j<i;j++){
            cout<<" ";
        }
        cout<<"*";
        if (int (i!=(n-2))){
        for(int k = (n-2*i -1); k>0;k--){
            cout<<" ";
        }
        cout<<"*";
        }
        cout<<endl;
        
    }
    // cout<<factorials<<endl;
    return 0;
}