#include <stdio.h>
#include "best.h"

// 测试
int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal (recursive): ");
    inorderTraversal(root);
    printf("\n");

    printf("Inorder traversal (iterative): ");
    inorderTraversalIterative(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level order traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}