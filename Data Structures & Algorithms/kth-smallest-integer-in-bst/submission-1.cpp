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
    void inorder(TreeNode* node, int* values){
        if(!node) return;
        if(node->left) inorder(node->left, values);
        if(values[0]==0) return;
        if(values[0]==1){
            values[1]=node->val;
        }
        values[0]--;
        if(node->right) inorder(node->right, values);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int values[2]={k, -1};
        inorder(root, values);
        return values[1];
    }
};
