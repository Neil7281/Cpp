#include<iostream>
#include<vector>
#include<algorithm>

void removeLargestElement(std::vector<int> vec){
     int n = vec.size();
     auto m = std::max_element(vec.begin(), vec.end());

    vec.erase(m);


}

int main(){

    std::vector<int> vec = {1,2,3,4};

    removeLargestElement(vec);

    for (int val : vec){
        std::cout<<val<<" ";
    }

}