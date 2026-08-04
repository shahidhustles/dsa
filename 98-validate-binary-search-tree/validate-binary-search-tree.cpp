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
    long long minVal;
    long long maxVal;
    bool isBST;

    Info(long long minVal, long long maxVal, bool isBST) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->isBST = isBST;
    }

    //defualt ctor
    Info() {
        this->minVal = 0;
        this->maxVal = 0;
        this->isBST = false;
    }
};

Info validateBST(TreeNode* root) {
    if(root == NULL) {
        return Info(LLONG_MAX, LLONG_MIN, true); // let null be a true BST
    }

    Info left = validateBST(root->left);
    Info right = validateBST(root->right);

    Info current;
    current.minVal = min((long long)root->val, min(left.minVal, right.minVal));
    current.maxVal = max((long long)root->val, max(left.maxVal, right.maxVal));

    //check if current node is BST : 
    if(
        left.isBST &&
        right.isBST &&
        root->val > left.maxVal && 
        root->val < right.minVal
    ){
        current.isBST = true;
    }

    return current;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        Info ans = validateBST(root);

        return ans.isBST;
    }
};