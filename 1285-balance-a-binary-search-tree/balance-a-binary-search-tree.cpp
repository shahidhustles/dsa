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
    void inorder(TreeNode* root, vector<TreeNode*>& ans) {
        if(root == NULL) return;

        //L 
        inorder(root->left, ans);

        // N 
        ans.push_back(root);

        // R
        inorder(root->right, ans);
    }

    TreeNode* buildBST(vector<TreeNode*>& sortedArr, int s, int e) {
        if(s >= e) return NULL;

        int mid = s + (e - s) / 2;

        auto root = sortedArr[mid];

        root->left = buildBST(sortedArr, s, mid);
        root->right = buildBST(sortedArr, mid + 1, e);

        return root; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sortedArr;

        inorder(root, sortedArr);

        int s = 0; 
        int e = sortedArr.size();
        return buildBST(sortedArr, s, e);
    }
};