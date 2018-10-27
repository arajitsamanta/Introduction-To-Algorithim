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

int max(int a, int b)
{
    return a > b ? a : b;
}

/*
Complexity
==========
Time : O(n). n is number of nodes.
Space: O(h). h is the height
*/
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
Complexity
==========
Time : O(n). n is number of nodes.
Space: O(h). h is the height
*/
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

/*
Complexity
==========
Time : O(n). n is number of nodes.
Space: O(h). h is the height
*/
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

//1 = Equal , 0 = Not Equal
int equals(struct node *root1, struct node *root2)
{
    //base case
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    //Check if the data of both roots is same and data of left and right  subtrees are also same
    return root1->data == root2->data && equals(root1->left, root2->left) && equals(root1->right, root2->right);
}

/*
Function return 1(true) if source(s) is a subtree of target(t), otherwise 0(false).

Complexity Analysis
===================
Time: O(m*n). In worst case(skewed tree) traverse function takes O(m*n) time.
Space : O(n). The depth of the recursion tree can go upto nn. nn refers to the number of nodes in ss.
*/
int isSubtree(struct node *t, struct node *s)
{

    //Base case
    if (s == NULL)
    {
        return 1;
    }

    if (t == NULL)
    {
        return 0;
    }

    //Check the equality of t and s with root as current node
    if (equals(t,s))
    {
        return 1;
    }

    //If the tree with root as current node doesn't match then try left and right subtrees one by one
    return isSubtree(t->left, s) || isSubtree(t->right, s);
}

/*
Complexity
==========
Time : O(n) n is number of nodes.
Space: O(h + 1) = O(h) 
*/
int depth(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(depth(root->left), depth(root->right));
}

/*
Height of a binary tree.

Time Complexity: O(n) where n is number of nodes in given binary tree.
*/
int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    /*
            1
          /   \
        2       3
       /  \
      4     5

    */
    //Level 0 - root
    struct node *root = newNode(1);

    //Level 1- Add 2 child to the root
    root->left = newNode(2);
    root->right = newNode(3);

    //Level 2- Add left and right to the left
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    //Get depth of tree
    printf("***** Max depth: %d, height: %d", depth(root), height(root));

    //inorder traversal
    printf("\n***** Inorder traversal ***** ");
    inorder(root);

     //preorder traversal
    printf("\n***** Preorder traversal ***** ");
    preorder(root);

     //postorder traversal
    printf("\n***** Postorder traversal ***** ");
    postorder(root);

    //Subtree S
    /*
        2
       /  \
      4    5  
    */
   struct node* s=newNode(2);
   s->left=newNode(4);
   s->right=newNode(5);
   printf("\n***** Is subtree: %s", isSubtree(root,s) ? "true" : "false");
   //Adding one more to the left left of S
   s->left->left=newNode(6);
   printf("\n***** Is subtree(After adding more node to S): %s", isSubtree(root,s) ? "true" : "false");

}