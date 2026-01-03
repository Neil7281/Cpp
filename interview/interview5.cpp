#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>


int longestSubstring(std::string str){
    int n = str.length();
    std::unordered_set<char> charSet;
    int left = 0;
    int maxLength = 0;
    
    for (int right = 0; right < n; right++) {
        // If character is already in the set, shrink the window from the left
        while (charSet.find(str[right]) != charSet.end()) {
            charSet.erase(str[left]);
            left++;
        }
        // Add the current character to the set
        charSet.insert(str[right]);
        // Update the maximum length
        maxLength = std::max(maxLength, right - left + 1);
    }
    
    return maxLength;
}


int main(){
    std::string s = "abcaacd";
    std::cout<<longestSubstring(s);
   return 0;
}