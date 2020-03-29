class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> index; 
        
        if (nums.size()){
            index.insert(pair<int, int>(nums[0], 0));
            
            for (int cur=1; cur<nums.size();++cur){
                if (index.count(target - nums[cur])){// Finding 
                    result.push_back(index[target - nums[cur]]);
                    result.push_back(cur);
                    break;
                }
                
                if (!index.count(nums[cur])){
                    index.insert(pair<int, int>(nums[cur], cur));
                }
            }
        }
        
        return result;
    }
};
