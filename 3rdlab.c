#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX];
int max=MAX;
int top=-1;
void push(){
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    if(top==max-1){
        printf("Overflow\n");
    }
    else{
        top++;
        stack[top]=data;
    }
}
void pop(){
    if(top==-1){
        printf("Underflow\n");
    }
    else{
        printf("The popped element is %d\n",stack[top]);
        top--;
    }
}
void peep(){
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(top>=pos-1){
        printf("The element is peeped at %d\n",stack[pos-1]);
    }
}
void display(){
    if(top==-1){
        printf("The list is empty\n");
    }
    else{
        printf("Stack elements\n");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}
int main(){
    int ch;
    do{
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            push();
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

            default:
            printf("Invalid choice\n");
        }
    }
    while(ch!=0);
    return 0;

}