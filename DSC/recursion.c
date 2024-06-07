#include<stdio.h>
void main(){
    int a,b,c;
    printf("Enter the value of A and B\n");
    scanf("%d %d",&b,&c);
    a = Sum(b,c);
    printf("%d",a);
}
int Sum(int x,int y){
    return x+y;
}