#include<iostream>
#include<vector>
using namespace std;

void SubArrayOpti(vector<int>& arr, int start, int end){
    int n = arr.size();
    if(end == n){
        return;
    }

    else if (start>end){
        SubArrayOpti(arr, 0, end +1);
    }

    else {
        for (int i=start;i<=end;i++){
            cout<<arr[i]<<" ";

        }
        cout<<endl;
        SubArrayOpti(arr, start+1, end);

    }
}

int main(){
    vector<int> arr = {1,2,3,4};
    SubArrayOpti(arr, 0, 0);
    return 0;
}