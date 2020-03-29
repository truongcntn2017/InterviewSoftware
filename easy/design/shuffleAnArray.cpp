class Solution {
public:
    vector<int> arr;
    vector<int> original;
    
    Solution(vector<int>& nums) {
        arr = nums;
        original = vector<int>(nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = original;
        original = vector<int>(original);
        
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int index = 0;
        
        for (int i=0; i<arr.size(); ++i){
            index = rand() % arr.size();
            swap(arr[i], arr[index]);
        }
        
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
