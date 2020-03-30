class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        auto range = equal_range(nums.begin(), nums.end(), target);
    
        if (range.second > range.first){
            res[0] = range.first - nums.begin();
            res[1] = range.second - nums.begin() - 1;
        }
    
        return res;
    }

};
