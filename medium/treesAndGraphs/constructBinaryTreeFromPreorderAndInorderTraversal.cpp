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
    int getIndexIn(vector<int>& a, int left, int right, int value){
        int index = -1;
        
        for (int i=left; i<=right; ++i)
            if (a[i] == value){
                index = i;
                break;
            }
        
        return index;
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int leftPre, int rightPre, vector<int>& inorder, int leftIn, int
                              rightIn) 
    {
        TreeNode* root = NULL;
        
        if (rightPre - leftPre >= 0){
            root = new TreeNode(preorder[leftPre]);
            int index = getIndexIn(inorder, leftIn, rightIn, root->val);
            
            root->left = buildTreeHelper(preorder, leftPre + 1, leftPre + index-leftIn, inorder, leftIn, index-1);
            root->right = buildTreeHelper(preorder, leftPre + index-leftIn+1, rightPre, inorder, index+1, rightIn);
        }
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
