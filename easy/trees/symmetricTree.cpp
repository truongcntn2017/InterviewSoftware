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
    
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        bool symmetriced = false;
        
        if (left && right){
            if (left->val == right->val){
                symmetriced = isSymmetricHelper(left->right, right->left) & isSymmetricHelper(left->left, right->right);
            }
        }
        else if (!left && !right){
            symmetriced = true;
        }
        
        return symmetriced;
    }
    bool isSymmetric(TreeNode* root) {
        bool symmetriced = true;
        if (root){
            symmetriced = isSymmetricHelper(root->left, root->right);
        }
        
        return symmetriced;
    }
};
