/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>

class Solution {
public:
    vector<int> out;
    int num=0, x;
    queue<TreeNode*> que;
    TreeNode* temp;
    
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return out; 
        que.push(root);
        while(!que.empty()){
            num = que.size();
            x = INT_MIN;
            
            while(num-->0){
                temp = que.front();
                que.pop();
                x = max(x, temp->val);
                    
                if(temp->left!=NULL)
                    que.push(temp->left);
                if(temp->right!=NULL)
                    que.push(temp->right);
            }
            out.push_back(x);
            
        }    
        return out;
    }
    
   
};