#define _CRT_SECURE_NO_WARNINGS

// https://leetcode.cn/problems/maximum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }

    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    if (right > left)
    {
        return right;
    }
    return left;
}