#include <stdio.h>
#include <stdlib.h>


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize <= 0 || inorderSize <= 0 || preorderSize != inorderSize || preorder == NULL || inorder ==NULL)
    {
        return NULL;
    }
    struct TreeNode* res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    res->val = preorder[0];

    int find_index=0;
    for(; find_index<preorderSize; find_index++)
    {
        if(inorder[find_index] == preorder[0])
        {
            break;
        }
    }

    if(find_index == preorderSize)
    {
        //error
        goto err;
    }

    if(find_index == 0)
    {
        res->left = NULL;
    }
    else
    {
        res->left = buildTree((preorder + 1),find_index,(inorder),find_index);
        if(res->left == NULL)
        {
            goto err;
        }
    }

    if(find_index == (preorderSize - 1))
    {
        res->right = NULL;
    }
    else
    {
        res->right = buildTree((preorder+find_index+1),(preorderSize - find_index - 1),(inorder + find_index +1),(preorderSize - find_index - 1) );
        if(res->right == NULL)
        {
            goto err;
        }
    }
    return res;


err:
    free(res);
    res = NULL;
    return NULL;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
