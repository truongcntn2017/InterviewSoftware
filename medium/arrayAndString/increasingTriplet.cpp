class Solution {
public:

bool increasingTriplet(vector<int>& nums) {
        int top = 0;
        int isIncreasingTriplet = false;

        
        for (int i=1; i<nums.size(); ++i){
            if (nums[top] < nums[i]){
                nums[++top] = nums[i];
                if (top == 2){
                    isIncreasingTriplet = true;
                    break;
                }
            }
            else{
                int cur = top;
                while (cur >= 0 && nums[cur] >= nums[i])
                    cur--;
                
                nums[++cur] = nums[i];
            }
        }
        
        return isIncreasingTriplet;
}

};
