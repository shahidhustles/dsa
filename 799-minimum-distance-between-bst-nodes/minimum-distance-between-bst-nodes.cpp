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
    void solve(TreeNode* root, TreeNode*& prev, int& minm) {
        if(root == NULL) return;

        // L 
        solve(root->left, prev, minm);

        // N 
        if(prev != NULL) {
            minm = min((root->val - prev->val), minm);
        }
        prev = root;

        // R
        solve(root->right, prev, minm);
    }

    int minDiffInBST(TreeNode* root) {
        int min = INT_MAX;
        TreeNode* prev = NULL;
        solve(root, prev, min);
        return min;
    }
};