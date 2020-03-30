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
    int kthSmallestHelper(TreeNode* root, int k, int level, int& value) {
        int nChild = 0;
        if (root){
            int nLeftChild = kthSmallestHelper(root->left, k, level+1, value);
            int nRightChild = kthSmallestHelper(root->right, k-nLeftChild-1, level+1, value);
            
            nChild = nLeftChild + nRightChild +1;
            if (nLeftChild+1 == k){
                value = root->val;
            }
        }
        
        return nChild;
    }
    int kthSmallest(TreeNode* root, int k) {   
        int value = INT_MIN;
        kthSmallestHelper(root, k, 0, value);
        return value;
    }
};
