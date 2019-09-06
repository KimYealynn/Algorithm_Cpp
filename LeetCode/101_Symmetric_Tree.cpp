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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return recursive(root->left, root->right);
    }
    bool recursive(TreeNode* L, TreeNode* R){
        if(L==NULL && R==NULL) return true;
        if(L==NULL || R==NULL) return false;
        if(L->val != R->val) return false;
        
        return recursive(L->left, R->right) 
            && recursive(L->right, R->left);
    }
};