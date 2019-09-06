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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> Stack;
        TreeNode* NODE;
        if(! root) return result;
        Stack.push(root);
        
        while(!Stack.empty()){
            NODE = Stack.top();
            Stack.pop();
            
            result.push_back(NODE->val);
            if(NODE->right)
                Stack.push(NODE->right);
            if(NODE->left)
                Stack.push(NODE->left);
        
        }
        
        return result;
    }
};