class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        
        for (int cur = 0; cur<nums.size(); ++cur)
            a = a ^ nums[cur];
        
        return a;
    }
};
