#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* bt_create_node(int val);
TreeNode* bt_insert(TreeNode *root, int val);
void bt_inorder(TreeNode *root);
void bt_free(TreeNode *root);

#endif
