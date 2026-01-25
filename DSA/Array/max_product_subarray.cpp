#include<iostream>
#include<vector>
#include<algorithm>

int maxProductSubarray(std::vector<int> &arr) {
    int n = arr.size();
        int max_product = arr[0];
        int curr_max = arr[0];
        int curr_min = arr[0];
        for(int i = 1; i<n; i++){
            int temp = std::max({arr[i], curr_max*arr[i], curr_min*arr[i]});
            
            curr_min = std::min({arr[i], curr_max*arr[i], curr_min*arr[i]});
            
            curr_max = temp;
            
            max_product = std::max(max_product, curr_max);
        }
        return max_product;
    }

    int main(){

        std::vector<int> vec = {2, 3, -8, 7, -1, 2, 3};
        std::cout<<"maximum product subarray = " << maxProductSubarray(vec);

    }