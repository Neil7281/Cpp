#include<iostream>
using namespace std;
int main(){
    int n = 4;
    // char character = 65;
    // int num = 1;
    // int factorials = 1;
    for(int i = 0; i<n;i++){
        
        for(int j = 0; j<n-i-1;j++){
            cout<<" ";
        }
        for(int j = 0; j<i+1;j++){
            cout<<(j+1);
        }
        for(int j = i; j>0;j--){
            cout<<j;
        }
        cout<<endl;
        
    }
    // cout<<factorials<<endl;
    return 0;
}