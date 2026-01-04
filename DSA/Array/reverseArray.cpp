#include<iostream>
#include<vector>

void reverseArray(std::vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int left = 0; int right = n-1;
        
        while (left<right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
        
}

int main(){
    std::vector<int> vec = {1,2,3,4};
    reverseArray(vec);

    for(int val : vec){
        std::cout<<val<<" ";
    }
    
}