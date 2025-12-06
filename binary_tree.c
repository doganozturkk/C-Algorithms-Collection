#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

TreeNode* bt_create_node(int val) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val; node->left = node->right = NULL;
    return node;
}

TreeNode* bt_insert(TreeNode *root, int val) {
    if (!root) return bt_create_node(val);
    if (val < root->val) root->left = bt_insert(root->left, val);
    else root->right = bt_insert(root->right, val);
    return root;
}

void bt_inorder(TreeNode *root) {
    if (!root) return;
    bt_inorder(root->left);
    printf("%d ", root->val);
    bt_inorder(root->right);
}

void bt_free(TreeNode *root) {
    if (!root) return;
    bt_free(root->left);
    bt_free(root->right);
    free(root);
}
