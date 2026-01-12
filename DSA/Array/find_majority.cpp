#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> findMajority(std::vector<int>& arr) {
        int n = arr.size();
        int flor = n/3;
        int count;
        std::vector<int> ans = {};
        for (int i = 0; i<n; i++){
            count = 0;
            for (int j = 0; j<n; j++){
                if (arr[i]==arr[j]){
                    count++;
                }
            }
            if (count > flor){
                ans.push_back(arr[i]);
            }
        }
    return ans;
        
}

int main(){
    std::vector<int> vec = {2, 2, 3, 1, 3, 2, 1, 1};
    std::vector<int> result = findMajority(vec);

    for(int val : result){
        std::cout<<val<<" ";
    }
    
}