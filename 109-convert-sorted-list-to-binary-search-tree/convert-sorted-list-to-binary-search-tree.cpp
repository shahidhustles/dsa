/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getLen(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL) {
            count ++;
            temp = temp->next;
        }

        return count;
    }

    TreeNode* buildBST(ListNode* &head, int n) {
        if(head == NULL) return NULL; // head is already at null
        if(n <= 0) return NULL; // no nodes left

        // L 
        TreeNode* left = buildBST(head, n / 2);

        // N
        int rootVal = head->val;
        TreeNode* root = new TreeNode(rootVal);
        root->left = left;
        head = head->next; // head wont be a part of the right subtree.

        // R
        root->right = buildBST(head, n - (n / 2) - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLen(head);
        return buildBST(head, n);
    }
};