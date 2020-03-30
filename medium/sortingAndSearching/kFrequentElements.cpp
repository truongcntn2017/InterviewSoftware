class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> pq;
    vector<int> res;

    for (int i=0; i<nums.size();++i){
        if (!freq.count(nums[i])){
            freq.insert(pair<int, int>(nums[i], 1));
        }
        else{
            freq[nums[i]]++;
        }
    }

    for (auto it = freq.begin(); it != freq.end(); ++it){
        pq.push(pair<int, int>(it->second, it->first));
    }

    for (int i=0; i<k;++i){
        int value = pq.top().second;
        pq.pop();
        res.push_back(value);
    }

    return res;
}
};
