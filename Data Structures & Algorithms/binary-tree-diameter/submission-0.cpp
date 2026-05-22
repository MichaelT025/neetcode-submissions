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
    int diam=0;
    int modheight(TreeNode* root){
        if(!root) return 0;
        int hleft = modheight(root->left);
        int hright = modheight(root->right);
        diam=max(diam, hright+hleft);
        return max(hleft, hright)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        modheight(root);
        return diam;
    }
};
