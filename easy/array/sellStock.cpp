
class Solution {
public:
    // Case: 1 2 3 4 5 7 1 8
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int indexMin, indexMax;
    
        if (prices.size()){
            indexMin = indexMax = 0;

            for (int i=1; i<prices.size();i++)
                if (prices[indexMax] >= prices[i]){
                    profit += prices[indexMax] - prices[indexMin];
                    indexMax = indexMin = i;
                }
                else{
                    indexMax = i;
                }

            profit += prices[indexMax] - prices[indexMin];
        }

        return profit;
        }
};

