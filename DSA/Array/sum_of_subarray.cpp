#include<iostream>
#include<vector>
using namespace std;

void SubarraySum(vector<int>& arr){
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i<n; i++){
        sum += arr[i]*(i+1)*(n-i);
    }

    cout<<sum<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4};
    SubarraySum(arr);
    return 0;
}