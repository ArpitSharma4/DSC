#include<stdio.h>
void toh(int n,char s,char t,char d){
    if(n>0){
        toh(n-1,s,d,t);
        printf("Move disk %d from %c to %c\n",n,s,d);
        toh(n-1,t,s,d);
    }
}
int main(){
    int n;
    printf("Enter the no. of discs\n");
    scanf("%d",&n);
    toh(n,'A','C','B');
}