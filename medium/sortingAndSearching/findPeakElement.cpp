class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right){
        int res = left;
        
        if (left != right){
            int mid = left + (right - left)/2;
            res = (nums[mid] > nums[mid+1]) ? binarySearch(nums, left, mid) : binarySearch(nums, mid+1, right);
        }
        
        return res;
    }
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1); 
    }
};
