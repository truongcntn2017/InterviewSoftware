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
    
    void inorder(TreeNode* root, vector<int>& res){
        if (root){
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
    
    bool isIncreasing(vector<int> a){
        bool increased = true;
        
        if (a.size() > 1){
            for (int i=1; i<a.size();++i){
                if (a[i-1] >= a[i]){
                    increased = false;
                    break;
                }
            }
        }
        
        return increased;
    }
    
    bool isValidBST(TreeNode* root) {
       vector<int> inorderNode;
       inorder(root, inorderNode);
        
       return isIncreasing(inorderNode);
    }
};
