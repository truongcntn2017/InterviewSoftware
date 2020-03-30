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
    void inorderTraversal(TreeNode* root, vector<int>& res){
        if (root){
            inorderTraversal(root->left, res);
            res.push_back(root->val);
            inorderTraversal(root->right, res);
        }
    }
    int kthSmallest(TreeNode* root, int k) { 
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        return inorder[k-1];
    }
};
