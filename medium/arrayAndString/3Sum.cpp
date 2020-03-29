class Solution {
public:
    
    vector<int> createSolution(int a, int b, int c){
        vector<int> res(3, 0);
        res = {a, b, c};
        return res;
    }
    void moveUp(vector<int> nums, int& left){
        int value = nums[left++];
        
        while (left < nums.size() && nums[left] == value){
            left++;
        }
    }
    void moveDown(vector<int> nums, int& right){
        int value = nums[right--];
        
        while (right >=0 && nums[right] == value){
            right--;
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {    
            vector<vector<int>> res;
            unordered_set<int> used;
        
            if (!nums.empty()){
                sort(nums.begin(),nums.end());
            
                for (int i=0; i<nums.size()-1;++i){
                    if (!used.count(nums[i])){
                        int left = i + 1;
                        int right = nums.size() - 1;
                        int k = -nums[i];
                    
                        while (left < right){
                            if (nums[left] + nums[right] < k){
                                left++;
                            }
                            else if (nums[left] + nums[right] > k){
                                right--;
                            }
                            else{
                                res.push_back(createSolution(nums[i], nums[left], nums[right]));
                                moveUp(nums, left);
                                moveDown(nums, right);
                            }
                        }
                        
                        used.insert(nums[i]);
                    }
                }
            }
            
            return res;
    }
};
