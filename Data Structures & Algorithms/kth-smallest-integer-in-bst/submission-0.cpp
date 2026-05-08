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
    void inorder(TreeNode* node, vector<int> &values){
        if(!node) return;
        if(node->left) inorder(node->left, values);
        if(node) values.push_back(node->val);
        if(node->right) inorder(node->right, values);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        vector<int> values;
        inorder(root, values);
        return values[k-1];
    }
};
