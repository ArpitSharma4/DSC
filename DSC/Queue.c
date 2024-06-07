#include <stdio.h>

#define maxsize 100

int rear = -1; // Global variable to track rear
int front = -1; // Global variable to track front

void insertlg(int a[], int item) {
    if (rear == maxsize - 1) {
        printf("The Queue is full\n");
    } else if (front == -1) {
        front = 0;
        rear = 0;
        a[rear] = item;
    } else {
        rear = rear + 1;
        a[rear] = item;
    }
}
