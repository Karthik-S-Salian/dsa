#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int r = maxDepth(root->left);
    int l = maxDepth(root->right);
    return (r > l ? r : l) + 1;
}