#include<iostream>
#include<vector>
using namespace std;

void Linearsearch(vector<int> &num, int goal){
    int index = 0;
    for(int val : num){
        if(val == goal){
            cout<<"The goal is reached at index ";
            cout<<index<<endl;
            index++;
            break;
        }else{
            cout<<"searching for goal...."<<endl;
        }
    }
}
int main(){
    vector<int> num = {1,2,3,4,5};
    int goal = 4;
    Linearsearch(num,goal);
}