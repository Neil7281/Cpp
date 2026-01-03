#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;

vector<int> MissingRepeating(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n-1; i++){
        if(arr[i+1]==arr[i]){
            ans.push_back(arr[i]);
            arr.erase(arr.begin() + i);
        }
    }

    for(int j = 0; j<arr.size(); j++){
        if(arr[j+1]!=arr[j]+1){
            ans.push_back(arr[j]+1);
        }
    }
    return ans;
} 

int main(){
    vector<int> arr = {1, 2, 4, 1};
    vector<int> result = MissingRepeating(arr);
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

}
