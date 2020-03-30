class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> numCoins(amount+1, INT_MAX-1);
        numCoins[0] = 0;
        
        for (int i=0; i<coins.size();++i){
            for (int j=coins[i]; j<= amount; j++){
                numCoins[j] = min(numCoins[j], numCoins[j-coins[i]]+1);
            }
        }
        
        return (numCoins[amount] == INT_MAX-1) ? -1 : numCoins[amount];
    }
};
