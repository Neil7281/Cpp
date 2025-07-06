#include<iostream>
using namespace std;

int binaryToDecimal(int n){
    int ans = 0, rem = 0, pov = 1;
    while(n>0){
        rem = (n%10); //remainder 
        ans = ans +rem*pov;  
        pov*=2;
        n/=10;
        
    }
    return ans;
} 


int main(){
    int marks[] = {10,15,50,3,60,30,46,92};
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int size = 8;
    for(int i = 0; i<size;i++){
        smallest = min(marks[i],smallest);
        largest = max(marks[i],largest);
    }
    cout<<smallest<<endl;
    cout<<largest<<endl;
    // cout<<binaryToDecimal(110010);
    return 0;
}