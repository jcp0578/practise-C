#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* flattenInt(struct TreeNode* node){
    if(node == NULL) {
        return NULL;
    }
    struct TreeNode* rRes = flattenInt(node->right);
    struct TreeNode* lRes = flattenInt(node->left);
    if(lRes != NULL) {
        lRes->right = node->right;
        node->right = node->left;
        node->left = NULL;
    }
    if(rRes != NULL) {
        return rRes;
    } if(lRes != NULL) {
        return lRes;
    } else {
        return node;
    }
}

void flatten(struct TreeNode* root){
    flattenInt(root);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
