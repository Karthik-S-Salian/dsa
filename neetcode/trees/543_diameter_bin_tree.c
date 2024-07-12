#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode* root,int * diff){
    if(root==NULL) return 0;
    int a = depth(root->left,diff);
    int b = depth(root->right,diff);
    *diff = (a+b>*diff)?(a+b):*diff;
    return (a>b?a:b)+1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diff = 0;
    depth(root,&diff);
    return diff;
}