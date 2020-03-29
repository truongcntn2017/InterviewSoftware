class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      vector<int> maxSum(nums.size()+1);
        int res = INT_MIN;
        
        if (!nums.empty()){
            maxSum[0] = nums[0];
            
            for (int i=1;i<nums.size();++i)
                maxSum[i] = max(maxSum[i-1], 0) + nums[i];
            
            res = maxSum[0];
            for (int i=1; i<nums.size();++i)
                res = max(res, maxSum[i]);
        }
        
        return res;
    }
};
