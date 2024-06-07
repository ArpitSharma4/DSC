#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
};
struct node*head;

void create(int n)
{
    struct node*newnode,*temp;
    int num;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for node 1:");
    scanf("%d", &num);
    head->data=num;
    head->link=NULL;
    temp=head;
    for(int i=1;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node:",i+1);
        scanf("%d", &num);
        newnode->data=num;
        newnode->link=NULL;
        temp->link=newnode;
        temp=newnode;
    }
}

void display()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        printf("List is: ");
        while(temp!=NULL)
        {
            printf("%d", temp->data);
            temp=temp->link;
            printf("->");
        }    
    }
}

void insertsorted(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*temp=NULL;
    newnode->data=x;
    if(head==NULL || head->data > newnode->data)
    {
        temp=newnode;
        temp->link=head;
        head=temp;
        return;
    }
    temp = head;
while( temp->link != NULL && temp->link->data < newnode->data)
{
temp = temp->link;
}
struct node *t = newnode;
t->link = temp->link;
temp->link = t;
}

int main()
{
    int n,x;
    printf("Enter number of nodes to create:");
    scanf("%d", &n);
    printf("Enter data in sorted order\n");
    create(n);
    display();
    printf("Enter data to insert:");
    scanf("%d", &x);
    insertsorted(x);
    display();
    return 0;
}
