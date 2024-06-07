#include<stdio.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node *next;
};
struct node *start,*temp,*p;
struct node *create() {
 int item;
 printf("Enter the elements (-999 to stop): ");
 scanf("%d", &item);
 while (item != -999) {
 p = (struct node *)malloc(sizeof(struct node));
 p->info = item;
 p->next = NULL;
 if (start == NULL) {
 start = p;
 } else {
 temp=start;
 while(temp->next!=NULL)
 {
 temp=temp->next;
 }
 temp->next = p;
 }
 scanf("%d", &item);
 }
 return start;
}
struct node *insertany(struct node *start,int pos,int item)
{
 int i=1;
 temp=start;
 while(i<pos-1 && temp!=NULL)
 {
 temp=temp->next;
 i++;
 }
 p = (struct node *)malloc(sizeof(struct node));
 p->info=item;
 p->next=temp->next;
 temp->next=p;
 return start;
}
void display()
{
 if (start == NULL)
 {
 printf("cannot display as the linked list is empty");
 }
 else
 {
 temp = start;
 while (temp != NULL)
 {
 printf("%d\n", temp->info);
 temp = temp->next;
 }
 }
}
int main()
{
 int im,po;
 create();
 printf("enter the element to be inserted\n");
 scanf("%d",&im);
 printf("enter the position where the element has to be entered\n ");
 scanf("%d",&po);
 start=insertany(start,po,im);
 display();
 return 0;
}