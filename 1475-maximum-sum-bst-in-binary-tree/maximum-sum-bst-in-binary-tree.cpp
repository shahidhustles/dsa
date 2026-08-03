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

class Info {
public :
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};

class Solution {
public:
    Info solve(TreeNode* root, int& maxSum) {
        if(root == NULL) {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true; // say null node is a bst too

            return temp;
        }

        // for current node, check left and right subtrees
        Info left = solve(root->left, maxSum);
        Info right = solve(root->right, maxSum);

        //for current node
        Info current;
        current.minVal = min(root->val, min(left.minVal, right.minVal));
        current.maxVal = max(root->val, max(left.maxVal, right.maxVal));
        current.sum = left.sum + right.sum + root->val; // update the sum but not the main maxSum

        // checking the three conditions of the question
        if(root->val > left.maxVal && root->val < right.minVal && left.isBST && right.isBST) {
            current.isBST = true;
            maxSum = max(current.sum, maxSum);
        }else {
            current.isBST = false;
        }

        return current;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);

        return maxSum;
    }
};