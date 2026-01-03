#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>



void mergeArrays(std::vector<int>& a, std::vector<int>& b) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        for (int i = 0; i<n2; i++){
            a.push_back(b[i]);
        }
        std::sort(a.begin(),a.end());
        int temp = 0;
        for (int j = n1+n2; j>n1; j--){
            b[n2- temp] = a[j];
            a.pop_back();
            temp++;
        }
    }



bool isBinary(std::string& s) {
        // Your code here
        int n = s.size();
        for (int i = 0; i<n; i++){
            if(s[i]!='0' && s[i]!='1'){
                return false; 
                break;
            }
        }
        return true;
    }


    bool searchKey(Node* head, int key) {
        // Code here
        Node* curr = head;
        
        while(curr != nullptr){
            if(*curr == key){
                return true;
                break;
            }
        }
        return false;
    }


void isPalindrome(std::string str){
        int n = str.length();
        bool resulst = true;
        for(int i = 0; i<n/2;i++){
            if (str[i]!=str[n-i-1]){
                resulst = false;
                break;
            }else {
                resulst = true;
            }
        }
        if(resulst){
            std::cout<<"is a palindrome";
        }else{
            std::cout<<"is not a palidrome";
        }
        // return;
    }

int main(){
    std::string stng = "neen";
    isPalindrome(stng);

    // std::stack<char> s;


    // for (auto val = vec.begin(); val != vec.end(); val++){
    //     s.push(*val);
    // }
    // vec.clear();

    // while (!s.empty()){
    //     vec.push_back(s.top());
    //     s.pop();
    // }

    //  for (auto val : vec){
    //     std::cout<<val<<" ";
    // }

    
   
    std::vector<int> vec = {1,2,3,4};
    std::vector<int> result;
    int n = vec.size();
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            if(vec[j>vec[i]]){
                result.push_back(vec[j]);
                // result.swap(i,j)
                break;
            }
            else{
                result.push_back(-1);
            }

        }
       
    }
    result.push_back(-1);
    // for (int val : result){
    //     std::cout<<val<<" ";
    // }
    
}