class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int counter = 0;
        
        if (!nums.empty()){
            sort(nums.begin(), nums.end());
            
            for (int i=0; i<nums.size();++i)
                counter += (nums[i] == counter) ? 1 : 0;
        }
        
        return counter;
    }
};
