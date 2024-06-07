#include<stdio.h>
int main(){
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int result = nat(n);
    printf("Sum of natural numnber %d is %d",n,result);
}
int nat(int n){
    if(n==0){
        return 0;
    }
    else{
        return(nat(n-1)+n);
    }
}