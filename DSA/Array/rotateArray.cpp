#include<iostream>
#include<vector>

void rotateArray(std::vector<int> &arr, int d) { // brut force approach for the problem
        
    int n = arr.size();
    std::vector<int> temp = arr;
    int right = n-1; int left = 0;
    for (int i = 0; i<d; i++){
        arr[d-i-1] = temp[right];
        right--;
    }
    for (int j = d; j<n; j++){
        arr[j] = temp[left];
        left++;
    }   
}

void rotateArray2(std::vector<int> &arr, int d){ // optimized version of problem 
    int count = 0;
    int n = arr.size();
    d = d%n;
    while (count < d){
        int temp = arr.back();
        arr.insert(arr.begin(), temp);
        arr.pop_back();
        count++;
    }

}

int main(){
    std::vector<int> vec = {1,2,3,4, 5, 6};
    rotateArray2(vec, 10);

    for(int val : vec){
        std::cout<<val<<" ";
    }
    
}