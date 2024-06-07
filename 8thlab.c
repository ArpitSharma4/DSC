#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *inserttree(struct Node *root,int value){
    if(root==NULL){
        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=value;
        newnode->left=NULL;
        newnode->right=NULL;
    }
    else{
        if(root->data<=value){
            root->right=inserttree(root->right,value);
        }
        else{
            root->left=inserttree(root->left,value);
        }
        return root;
    }
}
struct Node *createbst(struct Node *root){
    int val;
    printf("Enter the value to be inserted\n");
    scanf("%d",&val);
    while(val!=-1){
        root=inserttree(root,val);
        printf("Enter the value to be inserted\n");
    scanf("%d",&val);
        
    }
    return root;
}
void preorder(struct Node *root){
    if(root==NULL){
        printf("In preorder base\n");
        return;
    }
    else{
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root){
    if(root==NULL){
        printf("In postorder base\n");
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void inorder(struct Node *root){
    if(root==NULL){
        printf("In inorder base\n");
        return;
    }
    else{
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
int main() {
    struct Node *root = NULL;
    root = createbst(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    return 0;
}