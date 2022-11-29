#define _CRT_SECURE_NO_WARNINGS

// https://leetcode.cn/problems/same-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p != NULL && q == NULL)
    {
        return false;
    }
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p->val == q->val)
    {
        return isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
    else
    {
        return false;
    }
}