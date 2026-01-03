#include<iostream>
#include<algorithm>
#include<vector>



int main(){
    std::vector<double> a = {1.0,2.0,3.0};
    std::vector<double> b(a.size());

    std::transform(
        a.begin(),
        a.end(),
        b.begin(),
        [](double x){
            return x*x;
        }
    );
    
    for(auto& val : b) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

}