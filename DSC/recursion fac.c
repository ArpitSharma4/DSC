#include<stdio.h>
int main(){
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int result = fact(n);
    printf("The factorial of %d is %d",n,result);
}
int fact(int n){
    int result;
    if(n==0 || n==1){
        return 1;
    }
    else{
        return (n*fact(n-1));
    }
}