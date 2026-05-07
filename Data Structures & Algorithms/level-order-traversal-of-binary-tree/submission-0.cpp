/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> order;
        vector<vector<int>> result;
        order.push(root);
        while(!order.empty()){
            int size= order.size();
            vector<int> level;
            while(size--){
            TreeNode* curr=order.front(); order.pop();
            level.push_back(curr->val);
            if(curr->left) order.push(curr->left);
            if(curr->right) order.push(curr->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
