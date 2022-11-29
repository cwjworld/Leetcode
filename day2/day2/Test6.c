#define _CRT_SECURE_NO_WARNINGS

// https://leetcode.cn/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool re_isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    if (left == NULL || right == NULL)
    {
        return false;
    }
    return left->val == right->val
        && re_isSymmetric(left->left, right->right)
        && re_isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    return re_isSymmetric(root->left, root->right);
}