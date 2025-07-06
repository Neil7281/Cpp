#include<iostream>
#include<vector>
using namespace std;

int uniqueValue(vector<int>& arr){
    int uq= 0;
    for(int val : arr){
        uq = uq^val;
        
    }
    return uq;
}

int main(){
    vector<int> arr = {1,1,2,4,4};
    cout<<uniqueValue(arr)<<endl;
}