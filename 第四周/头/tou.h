#ifndef BST_H
#define BST_H

#include <stdbool.h>

// 定义二叉树结点
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新结点
TreeNode* createNode(int data);

// 插入结点
TreeNode* insert(TreeNode* root, int data);

// 查找结点
bool search(TreeNode* root, int data);

// 删除结点
TreeNode* delete(TreeNode* root, int data);

// 三序遍历递归
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);

// 三序遍历非递归
void inorderTraversalIterative(TreeNode* root);

// 层序遍历
void levelOrderTraversal(TreeNode* root);

#endif