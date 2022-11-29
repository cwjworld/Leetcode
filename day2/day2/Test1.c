#define _CRT_SECURE_NO_WARNINGS

// https://leetcode.cn/problems/binary-tree-preorder-traversal/

#include <stdio.h>
#include <string.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

void preorder(struct TreeNode* root, int* ret, int* returnSize)
{
    if (root == NULL)
    {
        return;
    }
    ret[(*returnSize)++] = root->val;
    preorder(root->left, ret, returnSize);
    preorder(root->right, ret, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    preorder(root, ret, returnSize);
    return ret;