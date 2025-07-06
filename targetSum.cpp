#include<iostream>
#include<vector>
using namespace std;
int targetSum(vector<int>& nums, int target){
    int n = nums.size();
    int i =0; int j = n-1;
    while(i<j){
        if(nums[i]+nums[j]>target){
            j--;
        }
        else if (nums[i]+nums[j]<target){
            i++;
        }
        else{
            return i,j;
        }
    }


return i;
}

int main(){
 vector<int> nums = {2,3,5,7};
 int target = 12;
 cout<<targetSum(nums,target);

}