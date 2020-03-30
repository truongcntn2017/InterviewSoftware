class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int res;

        for (int i=0; i<nums.size();++i)
            pq.push(nums[i]);

        for (int i=0; i<k-1;++i){
            pq.pop();
        }

        res = pq.top();

        return res;
    }
};
