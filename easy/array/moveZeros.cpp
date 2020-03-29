class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNoneZeroAt = 0;
        
        for(int cur=0; cur <nums.size(); ++cur){  // Move all none zero into begin of nums
            if (nums[cur]){// nums[cur] != 0
                nums[lastNoneZeroAt++] = nums[cur]; 
            }
        }
        
        for (int cur = lastNoneZeroAt; cur<nums.size(); ++cur)
            nums[cur] = 0;
    }
};
