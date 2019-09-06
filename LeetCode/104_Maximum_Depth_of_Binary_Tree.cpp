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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        TreeNode* P;
        queue<TreeNode*> que;
        que.push(root);
        int cnt = 0;
        while(true){
            queue<TreeNode*> new_que;
            while(!que.empty()){
                P = que.front();
                que.pop();
                if(P->left != NULL) new_que.push(P->left);
                if(P->right != NULL) new_que.push(P->right);
            }
            if(new_que.empty()) return ++cnt;
            cnt++;
            que=new_que;
        }
    }
};