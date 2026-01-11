#include<iostream>
#include<vector>
#include<algorithm>

void nextPermutation(std::vector<int> &arr) { // brut force approach for the problem
        
    int n = arr.size();
    int pivot = -1;
    for (int i = n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        std::reverse(arr.begin(), arr.end());
        return;
    }

    for (int j = n-1; j>pivot; j--){
        if(arr[j]>arr[pivot]){
            std::swap(arr[j], arr[pivot]);
            break;
        }
    }

    std::reverse(arr.begin()+pivot+1, arr.end()); // to find the next permutation
}
    
void nextPermutation2(std::vector<int> &arr){  // using Direct function next_permutation from stl library
    std::next_permutation(arr.begin(), arr.end());
}


int main(){
    std::vector<int> vec = {1, 4, 3, 2};
    nextPermutation(vec);

    for(int val : vec){
        std::cout<<val<<" ";
    }
    
}