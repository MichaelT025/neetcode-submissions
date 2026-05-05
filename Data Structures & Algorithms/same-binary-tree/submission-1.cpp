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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Pq;
        queue<TreeNode*> Qq;
        Pq.push(p);
        Qq.push(q);
        while(!Qq.empty() && !Pq.empty()){
            TreeNode* pcurr=Pq.front(); Pq.pop();
            TreeNode* qcurr=Qq.front(); Qq.pop();
            if(!pcurr && !qcurr) continue;
            if(!pcurr || !qcurr) return false;
            if((pcurr->val)!=(qcurr->val)) return false;
            Pq.push(pcurr->left);
            Qq.push(qcurr->left);
            Pq.push(pcurr->right);
            Qq.push(qcurr->right);
        }
        if(!Qq.empty() || !Pq.empty()) return false;
        return true;
    }
};
