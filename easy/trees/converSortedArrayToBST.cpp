/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
        TreeNode* root = NULL;
        
        if (left<right){
            int mid = left + (right - left)/2;
            TreeNode* leftNode = sortedArrayToBSTHelper(nums, left, mid-1);
            TreeNode* rightNode = sortedArrayToBSTHelper(nums, mid+1, right);
            
            root = new TreeNode(nums[mid]);
            root->left = leftNode;
            root->right = rightNode;
        }
        else if (left == right){
            root = new TreeNode(nums[left]);
        }
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};
