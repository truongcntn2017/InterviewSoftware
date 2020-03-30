class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>(0));
        
        for (int i=0; i<nums.size(); ++i){
            for (int j=0; j<res.size(); j++){
                vector<int> newSubset(res[j]);
                newSubset.push_back(nums[i]);
                res.push_back(newSubset);
            }
        }
        
        return res;
    }
};
