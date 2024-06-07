//Prg 7 DLL
#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node* prev;
    struct node* next;
};

struct node *head=NULL;

void createdLL(){
    struct node *flow;
    int n,val;
    printf("Enter the no.of nodes \n");
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        struct node * temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value\n");
        scanf("%d",&val);
        temp->info=val;
        temp->prev=NULL;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            flow=temp;
        }
        else{
            
            flow->next=temp;
            temp->prev=flow;
            flow=temp;
        }
    }
}
void display(){
    if(head==NULL){
        printf("DLL is empty \n");
        return ;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        printf("%d  ",temp->info);
        temp = temp->next;
    }
    printf("%d   \n",temp->info);
    
    // while(temp!=NULL){
    //     printf("%d  ",temp->info);
    //     temp = temp->prev;
    // }
    
}

void delmidnode(){
    if(head==NULL){
        printf("DLL is empty \n");
        return ;
    }
    if(head->next==NULL){
        printf("DLL has only one element \n");
        return ;
    }
    // if(head->next->next==NULL){
    //     printf("DLL has only two element \n");
    //     return ;
    // }
    if(head->next->next==NULL){
        head=head->next;
        free(head->prev);
        head->prev=NULL;
        return;

    }
    struct node *slow=head;
    struct node *fast=head;
    struct node*temp=head;
    while(fast->next!=NULL){
        
        fast=fast->next;
        
        if(fast->next!=NULL){
            temp=slow;
            fast=fast->next;slow=slow->next;
        }
    }
    int del=slow->info;
    printf("The deleted element is %d \n",del);
    temp->next=slow->next;
    slow->next->prev=temp;
    free(slow);
    
}

void insertbeforekey(int key){
    if(head==NULL){
        printf("DLL is empty \n");
        return ;
    }
    
    printf("Enter the value to be entered \n");
    int data;
    scanf("%d",&data);
    struct node* naya=(struct node*)malloc(sizeof(struct node));
    naya->info=data;
    naya->next=NULL;
    naya->prev=NULL;
    struct node*temp=head;
    if(head->info==key){
        naya->next = head;
        head->prev=naya;
        head = naya;
        return ;
    }
    while( temp!=NULL && key!=temp->info){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not found \n");
        return ;
    }
    
    
    
    naya->info=data;
    naya->next=temp;
    naya->prev=temp->prev;
    temp->prev=naya;
    naya->prev->next=naya;
}


int main()
{
    createdLL();
    display();
    printf("\n");
    delmidnode();
    printf("After deleting middle element \n");
    display();
    printf("\n");
    printf("Enter the key to be searched \n");
    int key;
    scanf("%d",&key);
    insertbeforekey(key);
    display();
    printf("\n");
    //display();
    return 0;
}
