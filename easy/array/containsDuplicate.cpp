class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool isDuplicate = false;
        unordered_set<int> contains; 

        if (nums.size()){
            contains.insert(nums[0]);
        
            for (int i=1; i<nums.size();++i){ // [1, n-1]
                if (contains.count(nums[i])){ // Finding in contains
                    isDuplicate = true;
                    break;
                }

                contains.insert(nums[i]); // Update contain
            }
        } 

        return isDuplicate;
    }
};
