class Solution {
public:
    int searchPivot(vector<int>& nums, int left, int right){
        int res = left;
        
        if (left != right){
            int mid = left + (right - left)/2;
            res = (nums[mid] > nums[right]) ? searchPivot(nums, mid+1, right): searchPivot(nums, left, mid);
        }
        
        return res;
    }
    int search(vector<int>& nums, int target){
        int index = -1;
        
        if (!nums.empty()){
            int pivot = searchPivot(nums, 0, nums.size()-1);
            
            if (binary_search(nums.begin(), nums.begin() + pivot, target)){
                index = lower_bound(nums.begin(), nums.begin() + pivot, target) - nums.begin();
            }
        
            if (binary_search(nums.begin() + pivot, nums.end(), target)){
                index = lower_bound(nums.begin() + pivot, nums.end(), target) - nums.begin();
            }
        }
        
        return index;
    }
    
};
