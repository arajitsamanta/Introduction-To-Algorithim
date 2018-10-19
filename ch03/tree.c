#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
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
Maximum Depth of a binary tree.

Time Complexity: O(n) where n is number of nodes in given binary tree.
*/
int maxDepth(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int height(struct node* root)
{
    if (root == NULL)
    {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    //Level 0 - root
    struct node* root = newNode(1);

    //Level 1- Add 2 child to the root
    root->left = newNode(2);
    root->right = newNode(3);

    //Level 2- Add left and right
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    //Get depth of tree
    printf("***** Max depth: %d, height: %d", maxDepth(root),height(root));

    //inorder traversal
    printf("\n***** Inorder traversal ***** ");
    inorder(root);
}