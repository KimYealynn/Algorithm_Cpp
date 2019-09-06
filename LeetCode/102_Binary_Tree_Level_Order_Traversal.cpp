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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        
        queue<TreeNode*> que;
        que.push(root);
    
        while(true){
            TreeNode* P;
            queue<TreeNode*> new_que;
            vector<int> temp;
            while(!que.empty()){
                P = que.front();
                que.pop();
                temp.push_back(P->val);
                if(P->left!=NULL) new_que.push(P->left);
                if(P->right!=NULL) new_que.push(P->right);
            }
            result.push_back(temp); 
            if(new_que.empty()) break;
            que = new_que;
        }
        return result;
    }
};