class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minPrices(prices.size()+1);
        int maxProfit = 0;
        
        if (!prices.empty()){
            minPrices[0] = prices[0];
            
            for (int i=1;i<prices.size();++i)
                 minPrices[i] = (min(minPrices[i-1], prices[i]));
            
            for (int i=1;i<prices.size();++i)
                maxProfit = max(maxProfit, prices[i] - minPrices[i-1]);
        }
        
        return maxProfit;
    }
};
