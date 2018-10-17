#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    //Allocate memory
    struct node* node=(struct node*)malloc(sizeof(struct node));

    //Assign data to the node
    node->data=data;

    //Set left and right as null
    node->left=NULL;
    node->right=NULL;

    return node;
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

//Height of a binary tree considering height of root is 0
int height(struct node* root){
    if(root==NULL){
        return -1;
    }
    return 1+max(height(root->left),height(root->right));
}

int main(){
    //Initialize root
    struct node* root=newNode(1);

    //Add 2 child to the root
    root->left        = newNode(2); 
    root->right       = newNode(3); 

    //Get height of tree
    printf("Current  height of tree is %d",height(root));

    //Add one more to the left
    root->left->left=newNode(4);
    //Get height of tree
    printf("\nCurrent  height of tree is %d",height(root));

    //inorder traversal
    printf("\n***** Inorder traversal *****");
    inorder(root);
}