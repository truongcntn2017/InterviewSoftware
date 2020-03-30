class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res = false;
        
        if (!nums.empty()){
            int length = nums[0] + 1; // length we cant from 0
        
            for (int i=1; i<nums.size();++i){
                if (i < length){
                    length = max(length, nums[i] + i + 1);
                }
            }
            
            res = (length >= nums.size());
        }
        
        return res;
    }
};
