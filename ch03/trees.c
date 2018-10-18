#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    //Allocate memory
    struct node *node = (struct node *)malloc(sizeof(struct node));

    //Assign data to the node
    node->data = data;

    //Set left and right as null
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node* lca(struct node* root, int v1, int v2)
{

    if (root == NULL)
        return NULL;

    if (root->data > v1 && root->data > v2)
        return lca(root->left, v1, v2);

    if (root->data < v1 && root->data < v2)
        return lca(root->right, v1, v2);

    return root;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

/*
Height of a binary tree.

Time Complexity: O(n) where n is number of nodes in given binary tree.
*/
int height(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    //Initialize root
    struct node* root = newNode(1);

    //Add 2 child to the root
    root->left = newNode(2);
    root->right = newNode(3);

    //Get height of tree
    printf("Current  height of tree is %d", height(root));

    //Add one more to the left
    root->left->left = newNode(4);
    //Get height of tree
    printf("\nCurrent  height of tree is %d", height(root));

    //inorder traversal
    printf("\n***** Inorder traversal *****");
    inorder(root);
}