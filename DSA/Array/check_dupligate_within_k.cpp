#include<iostream>
#include<vector>
using namespace std;

bool checkDupligateWithinK(vector<int>& arr, int k){
    int n = arr.size();
    for (int i = 0; i<=k+1; i++){
        if (arr[i]==arr[i+k+1]){
            return true;
        }
        
    }
    return false;
}

int main(){
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    int k = 3;
    cout<<checkDupligateWithinK(arr, k);
}