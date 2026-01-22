#include<iostream>
#include<vector>

int maxSubarraySum(std::vector<int> &arr) {
        int n = arr.size();
        int res = arr[0];   //max subarray sum 
        
        int maxEnding = arr[0];
        
        for(int i = 1; i<n; i++){
            
            maxEnding = std::max(arr[i], maxEnding + arr[i]);
            
            res = std::max(res, maxEnding);
        }
        
        return res;
    }

    int main(){

        std::vector<int> vec = {2, 3, -8, 7, -1, 2, 3};
        std::cout<<"maximum subarray sum = " << maxSubarraySum(vec);

    }