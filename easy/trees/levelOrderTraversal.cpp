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
    void levelOrderHelper(TreeNode* root, vector<vector<int>>& result, int level)
    {
        if (root){
            if (level<result.size()){
                result[level].push_back(root->val);
            }
            else{
                vector<int> temp;
                temp.push_back(root->val);
                result.push_back(temp);
            }
            levelOrderHelper(root->left, result, level + 1);
            levelOrderHelper(root->right, result, level + 1);
        }   
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderHelper(root, result, 0);
        return result;
    }
};
