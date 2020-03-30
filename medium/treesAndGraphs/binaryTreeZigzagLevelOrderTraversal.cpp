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
    void zigzagLevelOrderHelper(vector<vector<int>>& res, TreeNode* root, int level){
        if (root){
            if (level < res.size()){
                res[level].push_back(root->val);
            }
            else{
                vector<int> newLevel(1);
                newLevel = {root->val};
                res.push_back(newLevel);
            }
            
            zigzagLevelOrderHelper(res, root->right, level+1);
            zigzagLevelOrderHelper(res, root->left, level+1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagLevelOrderHelper(res, root, 0);
        
        for (int i=0; i<res.size();++i){
            if ((i+1) % 2){
                reverse(res[i].begin(), res[i].end());
            }
        }
        
        return res;
    }
};
