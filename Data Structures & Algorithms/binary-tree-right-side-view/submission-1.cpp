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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            int size=level.size();
            for(int i=size; i>0; i--){
                TreeNode* curr= level.front(); level.pop();
                if(i==size) result.push_back(curr->val);
                if(curr->right) level.push(curr->right);
                if(curr->left) level.push(curr->left);
            }
        }
        return result;
    }
};
