#define _CRT_SECURE_NO_WARNINGS

// https://leetcode.cn/problems/invert-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void re_invertTree(struct TreeNode* root)
{
    if (root)
    {
        struct TreeNode* ret = root->left;
        root->left = root->right;
        root->right = ret;
        re_invertTree(root->left);
        re_invertTree(root->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    re_invertTree(root);
    return root;
}