#include<iostream>
#include<vector>
using namespace std;


int SlidingWindowOptimization(vector<int>& arr, int k){
    int n = arr.size();
    int max_sum = 0;

    for (int i =0; i<k;i++){
        max_sum += arr[i];
    }
    int window_sum = max_sum;
    for (int j =k;j<n;j++){
        window_sum = arr[j] - arr[j-k];
        max_sum = max(window_sum,max_sum);
    }
    return max_sum;
}


int main(){
    vector<int> v = {5, 2, -1, 0, 3};
    int k = 3;
    cout<<SlidingWindowOptimization(v,k);
    return 0;
}