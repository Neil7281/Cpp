#include<iostream>
#include<vector>
#include<algorithm>

int getMinDiff(std::vector<int> &arr, int k) {
    int n = arr.size();
    std::sort(arr.begin(), arr.end());
    int result = arr[n-1] - arr[0];  // Initial difference
    
    // Try all split points
    for (int i = 0; i < n - 1; i++) {
        int minVal = std::min(arr[0] + k, arr[i+1] - k); //get the min value among arr after operation
        int maxVal = std::max(arr[n-1] - k, arr[i] + k);
        
        if (minVal >= 0) {  // Ensure no negative heights
            result = std::min(result, maxVal - minVal);
        }
    }
    
    return result;
}


    int main(){
        std::vector<int> vec = {1, 5, 8, 10};
        std::cout<<getMinDiff(vec, 2)<<" ";

        for(int val : vec){
            std::cout<<val<<" ";
        }

        return 0; 
    }