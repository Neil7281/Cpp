#include<iostream>
using namespace std;
int main(){
    int n = 5;
    int num = 1;
    // char character = 65;
    // int factorials = 1;
    for(int i =0; i<n;i++){
        for(int j = 0; j<i+1;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
        // character++;
    }
    // cout<<factorials<<endl;
    return 0;
}