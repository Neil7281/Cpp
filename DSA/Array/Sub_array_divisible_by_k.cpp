#include <iostream>
#include <vector>
using namespace std;


int SumDevisibleByK(vector<int>& arr, int k){
int n = arr.size();
int count = 0;

vector<int> new_arr = {};

for (int i =0; i<n; i++){
    int sum = 0;
    for (int j = i; j<n; j++){
        sum += arr[j]; 
            if(sum%k == 0){ 
                count +=1;
            }
        }
    }
    return count;
}

        
         

int main(){
    vector<int> v ={4,5,0,-2,-3,-1};
    int k = 5;
    cout<<SumDevisibleByK(v,k)<<endl;
    return 0;
}
