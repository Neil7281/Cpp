#include<iostream>
#include<vector>
int nonZeroPos = 0;

void pushZerosToEnd(std::vector<int>& arr) {
    int n = arr.size();
    int nonZer = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            // Swap current element with element at nonZeroPos
            std::swap(arr[i], arr[nonZeroPos]);
            nonZeroPos++;
        }
    }
}

int main(){
    std::vector<int> vec = {1,2, 0, 3,4,5};
    pushZerosToEnd(vec);

    for(int val : vec){
        std::cout<<val<<" ";
    }


    return 0;
}