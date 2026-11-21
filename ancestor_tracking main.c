#include <stdio.h>
#include <stdlib.h>
// Structure of a node
struct Node {
 int data;
struct Node* left;
struct Node* right;
};
// Create new node
struct Node* newNode(int data) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = data;
node->left = node->right = NULL;
return node;
}
// Function to print ancestors
int printAncestors(struct Node* root, int target)
{
if (root == NULL)
return 0;
 if (root->data == target)
 return 1;
 if (printAncestors(root->left, target) ||
 printAncestors(root->right, target)) {
 printf("%d ", root->data);
 return 1;
 }
 return 0;
}

int main() {
   /*
   1
  / \
2   3
  / \
4    5
  */
  struct Node* root = newNode(1);
  root->left = newNode(2);
 root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  int target;
  printf("Enter the target node to find its ancestors: ");
   scanf("%d", &target);
  printf("Ancestors of node %d are: ", target);
  if (!printAncestors(root, target)) {
  printf("Node not found in the tree.");
}
   return 0;
}
