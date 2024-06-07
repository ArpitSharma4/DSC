#include<stdio.h>
int main(){
    int GCD(int a,int b);
    int a,b;
    printf("Enter the two numbers\n");
    scanf("%d %d",&a,&b);
    int result = GCD(a,b);
    printf("GCD of %d and %d is %d",a,b,result);
}
int GCD(int a,int b){
    if(b==0)
        return a;
    else
        return(GCD(b,a%b));

}
