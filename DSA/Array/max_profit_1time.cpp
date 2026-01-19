#include<iostream>
#include<vector>
#include<algorithm>

int maximumProfit(std::vector<int> &prices) {
    int n = prices.size();
    int min_price = prices[0];
    int max_price = prices[0];
    int max_profit = 0;
    std::vector<int> MAX_PROFITE = {};
        
    for (int i = 0; i<n-1; i++){
        if (prices[i+1]>prices[i]){
            max_price = std::max(max_price, prices[i+1]);
                           
        }else(prices[i+1]<=prices[i]);{
            max_profit = max_price - min_price;
            MAX_PROFITE.push_back(max_profit);
            min_price = prices[i+1];
            max_price = prices[i+1];
            continue;
        }
    }
    int ans = *std::max_element(MAX_PROFITE.begin(), MAX_PROFITE.end());
    return ans;
}

int main(){

    std::vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    std::cout<<maximumProfit(prices);

    return 0;
}
