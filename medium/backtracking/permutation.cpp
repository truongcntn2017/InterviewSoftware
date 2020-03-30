class Solution {
public:
    void permuteHelper(vector<vector<int>>& res, vector<int>& nums, vector<bool>& visited, vector<int>& temp) {
        if (temp.size() == nums.size()){
            res.push_back(temp);
        }
        else{
            for (int i=0; i<nums.size(); ++i){
                if (!visited[i]){
                    visited[i] = true;
                    temp.push_back(nums[i]);
                    permuteHelper(res, nums, visited, temp);
                    visited[i] = false;
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> temp;
        
        permuteHelper(res, nums, visited, temp);
        return res;
    }
};
