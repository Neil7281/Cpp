#include<iostream>
#include<vector>
using namespace std;

void SubArray(vector<int>& arr){
    int n = arr.size();
    int sum = 0;
    for (int i = 0;i<n;i++){
        for (int j = i;j<n;j++){
            for (int k = i;k<=j;k++){
                 cout<<arr[k]<<"";
                 sum += arr[k];
            }
            cout<<endl;
        }
    }
    cout<<sum;
}

int main(){
    vector<int> arr = {1,2,3,4};
    SubArray(arr);
    return 0;
}