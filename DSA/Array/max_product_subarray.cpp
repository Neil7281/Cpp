#include<iostream>
#include<vector>

int maxSubarraySum(std::vector<int> &arr) {
        int n = prices.size();
    int min_price = prices[0];
    int max_profit = 0;
        
    for (int i = 1; i < n; i++){
        min_price = std::min(min_price, prices[i]);
        max_profit = std::max(max_profit, prices[i] - min_price);
    }
    
    return max_profit;
}

int main(){
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout<<maximumProfit(prices);
    return 0;
}