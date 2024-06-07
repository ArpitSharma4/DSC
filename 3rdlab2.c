#include <stdio.h>
#include<stdlib.h>
#define max 10
struct node
{
    int data;
    struct node *next;
};
struct node*top=NULL;
void push(int data)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    top=new;
}

int pop()
{
    if(top==NULL)
    {
        printf("\nStack is empty.");
    }
    else
    {
        struct node*temp=top;
        int temp_data=top->data;
        top=top->next;
        free(temp);
        printf("\nPopped element is %d",temp_data);
    }
}
 void peep()
 {
     if(top==NULL)
     {
         printf("\nStack empty.");
     }
     else
     {
         printf("Topmost element is %d",top->data);
     }
 }
 void display()
 {
     int i=0;
     if(top==NULL)
     {
         printf("\nStack empty.");
     }
     else
     {
         struct node *temp=top;
         while(top!=NULL)
         {
             printf("%d",temp->data);
             temp=temp->next;
         }
     }
     printf("\n");
 }

int main() {
    // Write C code here
    int ch;
    while(1)
    {
        printf("\n Enter your choice:\n1.Push\n2.Pop\n3.Peep\n4.Dispaly\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                int data;
                printf("Enter data to be pushed:");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice.");
        }
    }

    return 0;
}
