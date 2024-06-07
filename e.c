#include <stdio.h> 
#include <stdlib.h> 
struct node {
int num;
struct node *link;
}*head;
void create(int n); void printList(); void insert(); void delete();
int main()
{
int n,ch;
printf(" enter number of nodes : "); scanf("%d", &n);
create(n); printList();
printf("Your choices are\n"); printf("1.Insert a node at the end\n"); printf("2.Delete a node from the beg\n");
printf("3.Display the List\n");	printf("4.Exit\n"); printf("\n\n");
while(1)
{
printf("Enter any choice\n"); scanf("%d",&ch); switch(ch)
{
case 1: insert(); break; case 2: delete(); break; case 3: printList(); 

break;
case 4: exit(0); default:
printf("Invalid choice\n");
}
}
}
void create(int n)
{
struct node *newnode, *temp; int num,i;
head= (struct node *)malloc(sizeof(struct node*));
 printf(" Enter data for node 1 : ");
scanf("%d", &num); 
head->num = num;
 head->link = NULL; 
 temp = head;
for(i=1; i<n; i++)
{
newnode = (struct node *)malloc(sizeof(struct node));
 printf(" enter data for node %d : ", i+1);
scanf(" %d", &num);
 newnode->num = num; 
 newnode->link = NULL;
  temp->link = newnode; 
  temp = temp->link;
}
}
void printList()
{
struct node *temp; if(head == NULL)
{
printf(" List is empty.");
}
else
{ 

temp = head; printf("The list is:\n"); printf("head->"); while(temp!=NULL)
{
printf("%d->",temp->num); temp=temp->link;
}
printf("NULL\n"); printf("\n\n");
}
}
void insert()
{
struct node *node,*temp;
node=(struct node*)malloc(sizeof(struct node)); printf("enter the data of the node\n"); scanf("%d",&node->num);
node->link=NULL; temp=head;
while(temp->link!=NULL) { temp=temp->link;
}
temp->link=node; printf("After inserting\n"); printList();
}
void delete()
{
struct node *temp; temp=head; head=head->link; free(temp);
printf("After deleting\n"); printList();
} 
 

