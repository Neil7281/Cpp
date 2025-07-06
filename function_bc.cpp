#include<iostream>
using namespace std;
int bionomialCoofficient(int n, int r){
    int bc = 1;
    for(int i = n; i>=n-r;i--){
        bc = bc*i;
    }
    return bc;
}
int main(){
    cout<<bionomialCoofficient(5,2)<<endl;
    return 0;
}