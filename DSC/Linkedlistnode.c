#include<stdio.h>
#include<stdlib.h>
void main(){
    struct node{
        int info;
        struct node *next;
        
    };
    struct node *P,*Q;
    P=(struct node *) malloc(sizeof(struct node));
    P->info=10;
    Q=(struct node *) malloc(sizeof(struct node));
    Q->info=20;
    P->next=Q;
    Q->next=NULL;

}