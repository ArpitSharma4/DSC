#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the two numbers\n");
    scanf("%d %d",&a,&b);
    int result =prod(a,b);
    printf("The product of %d and %d is %d",a,b,result);
}
int prod(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    if(b==0){
        return a;
    }
    else{
        return (prod(a,b-1)+a);
    }
}