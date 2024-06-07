#include<stdio.h>
#include<stdlib.h>
#define maxsize 50

int a[maxsize];
int front=-1;
int rear=-1;

void insert(int item){
    if(rear==maxsize-1){
        printf("QUEUE IS FULL\n");
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
            a[rear]=item;
        }
    }
    rear=rear+1;
    a[rear]=item;
}
void delete(){
    int item;
    if(front==-1){
        printf("QUEUE IS EMPTY\n");
    }
    else{
        item=a[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
    front=front+1;
    }
    printf("Deleted element is %d\n",item);
    }
}
void display(){
    if(front==-1){
        printf("QUEUE IS EMPTY\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("ELEMENTS ARE %d\n",a[i]);
        }
    }
}
int main(){
    int ch;
    int val;
    do{
        printf("Enter the choice\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");

        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the value to be inserted\n");
            scanf("%d",&val);
            insert(val);
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 0:
            printf("Exiting\n");
            break;

            default:
            printf("Invalid choice\n");
        }
    }while(ch!=0);
    return 0;
}
