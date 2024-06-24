#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int a = height(root->left);
    if (a == -1)
        return -1;
    int b = height(root->right);
    if (b == -1)
        return -1;
    if (((a - b) > 1) || ((a - b) < -1))
        return -1;
    return (a > b ? a : b) + 1;
}

bool isBalanced(struct TreeNode *root)
{
    int h = height(root);
    if (h == -1)
        return false;
    return true;
}