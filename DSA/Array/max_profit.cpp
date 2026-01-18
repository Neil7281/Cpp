#include<iostream>
#include<vector>

int maximumProfit(std::vector<int> &prices) {
    int n = prices.size();
    int min_price = prices[0];
    int max_price = prices[0];
    int max_profit = 0;
        
    for (int i = 0; i<n-1; i++){
        if (prices[i+1]>prices[i]){
            max_price = std::max(max_price, prices[i+1]);
                           
        }else(prices[i+1]<=prices[i]);{
            max_profit = max_profit + max_price - min_price;
            min_price = prices[i+1];
            max_price = prices[i+1];
            continue;
        }
    }
    return max_profit;
        
}

int main(){

    std::vector<int> prices = {4,2,2,2,4};
    std::cout<<maximumProfit(prices);

    return 0;
}
