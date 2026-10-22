class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            // While iterating, we find the minimum price of the stock
            minPrice = min(minPrice, prices[i]);
            // Profit is the difference between the current price
            // and maximum price
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};
