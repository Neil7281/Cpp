#include<iostream>
using namespace std;
int main(){
    int n = 4;
    // char character = 65;
    // int num = 1;
    // int factorials = 1;
    for(int i = 0; i<n;i++){
        for(int j = 0; j < i+1; j++){
            cout<<"*";
        }
        if (i!=(n - 1)){
            for (int j = (2*(n-i)-2); j>0; j--){
                cout<<" ";
            }
        }
        for(int j = 0; j < i+1; j++){
                cout<<"*";
        }
        cout<<endl;
        
    }
    // cout<<factorials<<endl;
    return 0;
}