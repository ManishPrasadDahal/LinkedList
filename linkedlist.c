#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
int info;
struct node*link;
};

struct node*start = NULL;

void createList()
{
if(start == NULL) {
int n;
printf("\n Enter the number of nodes: ");
scanf("%d",&n);
if(n != 0)
{
int data,i;
struct node* newnode;
struct node* temp;
newnode = malloc(sizeof(struct node));
start = newnode;
temp = start;
printf("\n Enter number to be inserted: ");
scanf("%d",&data);
start->info=data;
for(i=2;i<=n;i++)
{
newnode = malloc(sizeof(struct node));
temp->link = newnode;
printf("\n Enter number to be inserted: ");
scanf("%d",&data);
newnode->info = data;
temp = temp->link;
}
}
printf("\nThe list is created \n");
}
else printf("\n The list is already created \n");
}

void traverse()
{
struct node* temp;
if(start == NULL) printf("\n List is empty \n");
else
{
temp = start;
while(temp != NULL)
{
printf("%d\t",temp->info);
temp = temp->link;
}
}
}

void insertAtFront()
{
int data;
struct node* temp;
temp = malloc(sizeof(struct node));
printf("\n Enter number to be inserted: ");
scanf("%d",&data);
temp->info = data;
temp->link =start;
start = temp;
}

void insertAtEnd()
{
int data;
struct node *temp, *head;
temp = malloc(sizeof(struct node));
printf("\n Enter number to be inserted: ");
scanf("%d",&data);
temp->link = 0;
temp->info = data;
head =start;
while(head->link != NULL)
{
head = head->link;
}
head->link = temp;
}

void insertAtPosition()
{
struct node *temp, *newnode;
int pos, data, i=1;
newnode = malloc(sizeof(struct node));
printf("\nEnter position and data:");
scanf("%d %d",&pos,&data);
temp = start;
newnode->info = data;
newnode->link = 0;
while(i<pos-1)
{
temp = temp->link;
i++;
}
newnode->link = temp->link;
temp->link = newnode;
}

void deleteFirst()
{
struct node* temp;
if(start == NULL) printf("\n List is empty \n");
else
{
temp = start;
start = start->link;
free(temp);
}
}

void deleteEnd()
{
struct node *temp, *prevnode;
if(start == NULL) printf("\n List is Empty \n");
else
{
temp = start;
while(temp->link != 0)
{
prevnode = temp;
temp = temp->link;
}
free(temp);
prevnode->link = 0;
}
}

void deletePosition()
{
struct node *temp,*position;
int i=1,pos;
if(start == NULL) printf("\n List is empty \n");
else
{
printf("\n Enter index:");
scanf("%d",&pos);
position = malloc(sizeof(struct node));
temp = start;
while(i<pos-1)
{
temp = temp->link;
i++;
}
position = temp->link;
temp->link = position->link;
free(position);
}
}

int main()
{
int choice;
while(1)
{
printf("\n\t 1 to see list \n");
printf("\t 2 For insertion at starting \n");
printf("\t 3 for insertion at end \n");
printf("\t 4 for insertion at any point\n");
printf("\t 5 for deletion of first element\n");
printf("\t 6 for deletion of last element\n");
printf("\t 7 for deletion of element at any position\n");
printf("\t 8 to exit\n");
printf("\nEnter Choice\n");
scanf("%d",&choice);
switch (choice)
{
case 1: traverse();
break;
case 2: insertAtFront();
break;
case 3: insertAtEnd();
break;
case 4: insertAtPosition();
break;
case 5: deleteFirst();
break;
case 6: deleteEnd();
break;
case 7: deletePosition();
break;
case 8: exit(1);
default:
printf("Incorrect Choice \n");
}
}
return 0;
}