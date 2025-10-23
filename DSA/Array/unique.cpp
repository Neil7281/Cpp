#include<iostream>
#include<vector>
using namespace std;

int UniqueNumber(vector<int>& arr){
    int n = arr.size();
    
    for (int i = 0; i<n; i++){
        int count = 0;
        for (int j = 0; j<n;j++){
            if (arr[i] == arr[j]){
                count++;
            }
        }
        if (count == 1){
            return arr[i];
        }
        
    }
    return -1;
}


int main(){
    vector<int> arr = {1,1,3,2,2,3,4};
    cout<<UniqueNumber(arr);
}