#include <stdio.h>

int main() {
    int rev(int n);
    int n;
    printf("Enter the number you want to reverse\n");
    scanf("%d", &n);
    int result = rev(n);
    printf("The reverse order of %d is %d\n", n, result);
    return 0;
}

int rev(int n) {
    static int reversed = 0;  
    if (n > 0) {
        reversed = reversed * 10 + n % 10;
        n = n / 10;
        rev(n);
    }

    return reversed;
}
