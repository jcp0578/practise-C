#include <stdio.h>
#include <stdlib.h>

/*
 * AC
 * https://leetcode-cn.com/submissions/detail/75251482/
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric_node(struct TreeNode* node1,struct TreeNode* node2){
    if(node1 == NULL || node2 == NULL) {
        if(node1 == node2) {
            return true;
        } else {
            return false;
        }
    }
    if(node1->val == node2->val) {
        return (isSymmetric_node(node1->left,node2->right) &&
                isSymmetric_node(node2->left,node1->right));
    } else {
        return false;
    }
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL) {
        return true;
    }
    return (isSymmetric_node(root->left,root->right));
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
