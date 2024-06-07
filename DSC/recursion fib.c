#include<stdio.h>
int main(){
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int result =fib(n);
    printf("The fibonacci series of %d is %d\n",n,result);
}
int fib(int n){
    int result;
    if(n=1){
        return 0;
    }
    if(n=2){
        return 1;
    }
    else{
        return(fib(n-1)+fib(n-2));
    }
}