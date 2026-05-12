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
    int preRoot=0;
    unordered_map<int, int> valtoIdx;
    TreeNode* built(vector<int>& preorder,int start, int end){
        if(start>end) return nullptr;
        TreeNode* root=new TreeNode(preorder[preRoot++]);
        int inRoot=valtoIdx[preorder[preRoot-1]];
        root->left=built(preorder,start, inRoot-1);
        root->right=built(preorder, inRoot+1, end);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) valtoIdx[inorder[i]]=i;
        return built(preorder,0, inorder.size()-1);
    }
};
