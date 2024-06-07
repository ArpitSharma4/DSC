#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        return create(data);
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }

    return node;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *min(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delete(struct node *root, int data)
{
    if (root == NULL)
    {
        printf("node not found\n");
        return NULL;
    }

    if (data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return (temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return (temp);
        }

        struct node *temp = min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

int main()
{
    int ch, x, num;
    struct node *root = NULL;

    printf("Your choices are\n");
    printf("1. Insert a node into the tree\n");
    printf("2. Inorder traversal\n");
    printf("3. Delete a given node in the tree\n");
    printf("4. Exit\n");
    printf("\n");

    while (1)
    {
        printf("\nEnter any choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the node to be inserted\n");
            scanf("%d", &num);
            root = insert(root, num);
            break;

        case 2:
            printf("Inorder traversal\n");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter the node to be deleted\n");
            scanf("%d", &x);
            root = delete(root, x);
            printf("Inorder traversal after deleting\n");
            inorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
