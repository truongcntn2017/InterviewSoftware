class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end()); // reverse [0, n-1]
        reverse(nums.begin(), nums.begin()+k); //reverse [0, k-1]
        reverse(nums.begin()+k, nums.end()); // reverse[k, n-1]
    }
};
