#include<stdio.h>
#include<stdlib.h>
struct Node{
    int num;
    struct node *next;
}*head;
void create(int n);
void Printlist();
void insert();
void delete();
int main(){
    int n,ch;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    create(n);
    printf("1.To insert a node at the end\n");
    printf("2.To delete a node at the beginning\n");
    printf("3.To display the nodes\n");
    while(1){
        printf("Enter your choice between 1 to 3\n");
        scanf("%d",&ch);
    switch(ch){
        case 1:
        insert();
        break;

        case 2:
        delete();
        break;

        case 3:
        Printlist();
        break;

        default:
        printf("Invalid choice\n");
    }
}
}
void create(int n){
    struct Node *newnode,*temp;
    int num,i;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data for node \n");
    scanf("%d",&num);
    head->num=num;
    head->next=NULL;
    temp=head;
    for(i=1;i<n;i++){
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the node %d\n",i+1);
        scanf("%d",&num);
        newnode->num=num;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;

    }
}
void Printlist(){
    struct Node *temp;
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        temp=head;
        printf("The list is\n");
        printf("head->");
        while(temp!=NULL){
            printf("%d",temp->num);
            temp=temp->next;
        }
    }
}
void insert(){
    struct Node *node,*temp;
    node=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data of the node\n");
    scanf("%d",&node->num);
    node->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    printf("After inserting\n");
    Printlist();

}
void delete(){
    struct Node *temp;
    temp=head;
    head=head->next;
    free(temp);
    printf("After deleting\n");
    Printlist();

}