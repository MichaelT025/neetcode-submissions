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
    int dfs(TreeNode* root, int max){
        if(!root) return 0;
        int num=0;
        if(root->val>=max){
            num++;
            max=root->val;
        }
        return num+dfs(root->left, max)+ dfs(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, INT_MIN);

    }
};
