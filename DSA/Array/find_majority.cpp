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
                if (ans.size()==0 || arr[i] != ans[0])
                    ans.push_back(arr[i]);
                }
            if (ans.size() == 2){
                if (ans[0]>ans[1]){
                    std::swap(ans[0], ans[1]);
                    break;
                }
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