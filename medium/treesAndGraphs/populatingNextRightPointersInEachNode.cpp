/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    void connectRightLeftHelper(Node* root){
        if (root && root->left){
            connectRightLeftHelper(root->left);
            connectRightLeftHelper(root->right);
            
            Node* leftNode = root->left;
            Node* rightNode = root->right;
            
            while (leftNode->right){
                leftNode->right->next = rightNode->left;
                leftNode = leftNode->right;
                rightNode = rightNode->left;
            }
        }
    }
    void connectLeftRightHelper(Node* root) {
        if (root){
            root->next = NULL;
            connectLeftRightHelper(root->left);
            connectLeftRightHelper(root->right);
            if (root->left){
                // Connect (left -> right)
                root->left->next = root->right;   
            }
        }
    }
    Node* connect(Node* root) {
        connectLeftRightHelper(root);
        connectRightLeftHelper(root);
        return root;
    }
};
