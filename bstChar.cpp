#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the BST
struct TreeNode {
    char day[10];
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(char day[]) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->day, day);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode* insert(struct TreeNode* root, char day[]) {
    if (root == NULL) {
        return createNode(day);
    }

    // Compare the day to decide whether to insert it to the left or right
    int cmp = strcmp(day, root->day);

    if (cmp < 0) {
        root->left = insert(root->left, day);
    } else if (cmp > 0) {
        root->right = insert(root->right, day);
    }

    return root;
}

// In-order traversal to print the BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->day);
        inorderTraversal(root->right);
    }
}

int main() {
    // Initialize the root of the BST as NULL
    struct TreeNode* root = NULL;

    // Days of the week in order
    char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Insert each day into the BST
    for (int i = 0; i < 7; i++) {
        root = insert(root, days[i]);
    }

    // Print the in-order traversal to verify the BST
    printf("In-order traversal of the BST:\n");
    inorderTraversal(root);

    // Free the memory used by the BST (optional)
    // You may want to implement a proper cleanup function
    // that recursively frees all nodes in the BST.

    return 0;
}
