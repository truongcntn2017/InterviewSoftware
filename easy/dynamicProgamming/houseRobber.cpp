class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        vector<int> maxMoney(nums.size()+2, 0);
        
        if (!nums.empty()){
            maxMoney[0] = nums[0];
            maxMoney[1] = (nums.size() > 1) ? max(nums[0], nums[1]) : 0;
            
            for (int i=2;i<nums.size();++i){
                maxMoney[i] = max(maxMoney[i-1], nums[i] + maxMoney[i-2]);
            }
            
            res = maxMoney[nums.size()-1];
        }
        
        return res;
    }
};
