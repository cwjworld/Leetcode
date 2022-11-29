#define _CRT_SECURE_NO_WARNINGS

// https://leetcode.cn/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int D_value(struct TreeNode* root)
{
    return root ? 1 + fmax(D_value(root->left), D_value(root->right)) : 0;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    int left = D_value(root->left);
    int right = D_value(root->right);
    return abs(left - right) <= 1
        && isBalanced(root->left)
        && isBalanced(root->right);
}