
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
    int maxDepth(TreeNode* root) {
        int length = 0;
        
        if (root){
            length = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
        
        return length;
    }
};
