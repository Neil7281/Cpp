#include<iostream>
using namespace std;


int main(){
    int marks[] = {10,15,50,60,30,3,92};
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int size = sizeof(marks)/sizeof(int);
    int smallestIndex, largestIndex = 0;
    for(int i = 0; i<size;i++){
        if(smallest > marks[i]){
            smallest = marks[i];
            smallestIndex = i;
        }
        if(largest < marks[i]){
            largest = marks[i];
            largestIndex = i;
        }
        // smallest = min(marks[i],smallest);
        // largest = max(marks[i],largest);
    }
    // cout<<smallest<<endl;
    cout<<smallestIndex<<endl;
    cout<<largestIndex<<endl;
    // cout<<binaryToDecimal(110010);
    return 0;
}