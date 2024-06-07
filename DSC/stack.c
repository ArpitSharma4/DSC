#include<stdio.h>
#define MAX 50

int stack[MAX];
int max = MAX;
int top = -1;

void push(){
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    if(top==max-1){
        printf("Overflow!\n");
    }
    else{
        top++;
        data = stack[top];
    }
}
void pop(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        printf("Popped element is %d\n",stack[top]);
    }
}
void peep(){
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(top>=pos-1){
        printf("Element peeped at %d",stack[pos-1]);
    }
    else{
        printf("Position is out of range");
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements:\n");
    }
    for(int i=0;i>=0;i--){
        printf("Displayed element is %d",&stack[i]);
    }
}
int main(){
    int ch;
    do{
        printf("Enter the choice from 1 to 5(0 to exit:)");
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
            printf("Invalid choice");
        }
    }
    while(ch!=0);
    return 0;
}
