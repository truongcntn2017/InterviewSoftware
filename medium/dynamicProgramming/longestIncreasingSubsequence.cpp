class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        
        if (!nums.empty()){
            seq.push_back(nums[0]);
            
            for (int i=1; i<nums.size();++i){
                if (seq.back() < nums[i]){
                    seq.push_back(nums[i]);
                }
                else if (!binary_search(seq.begin(), seq.end(), nums[i])){
                    int index = upper_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                    seq[index] = nums[i];
                }
            }
        }
        
        return seq.size();
    }
};
