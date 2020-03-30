class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3] = {0};
        
        for (int i=0; i<nums.size();++i)
            freq[nums[i]]++;

        int curSum = 0;
        for (int i=0; i<3; ++i){
            for (int j=curSum; j<curSum+freq[i]; ++j){
                nums[j] = i;
            }
            curSum += freq[i];
        }

    }

};
