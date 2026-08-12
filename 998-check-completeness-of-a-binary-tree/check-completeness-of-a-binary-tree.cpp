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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> cbt;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front(); q.pop();
                if(front != NULL) {
                    cbt.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                } else {
                    cbt.push_back(0);
                }
            }
        }

        int n = cbt.size();
        for(int i = 0; i < n; i++) {
            if(cbt[i] == 0 && i + 1 < n && cbt[i + 1] != 0) {
                return false;
            }
        }

        return true;
    }
};