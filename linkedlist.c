/*
Write a C program using dynamic variables and pointers, to construct a singly linked list. The operations to be supported are:
a) Insert at the front of a list.
b) Insert at any position in the list.
c) Deleting a node based on specified value.
d) Searching a node based on specified value.
e) Displaying all the nodes in the list.
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node* NODE;
NODE create()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("allocation failed\n");
    return 0;
    }
    else
    return p;
}
void nodefree(NODE x)
{
    free(x);
}
NODE insertfront(NODE first)
{int item;
    NODE temp;
    temp=create();
    printf("Enter the element to be inserted :\n");
    scanf("%d",&item);
    temp->data=item;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    else
    {
    temp->link=first;
    return temp;
    }

}

void insertany(NODE first)
{int item,count=1,pos;//num=1;
NODE temp,cur,prev;//next;

    temp=create();
    printf("Enter the position at which you want to add another node\n");
    scanf("%d",&pos);
    printf("Enter the element to be inserted :\n");
    scanf("%d",&item);
    cur=first;
    prev=first;
    while(cur->link!=NULL && count!=pos)
    {    prev=cur;
        cur=cur->link;
        count++;
    }
    if(count==pos)
    {
        temp->data=item;
        temp->link=prev->link;
        prev->link=temp;
    }
    else if(pos==count+1)
    {
        temp->data=item;
        temp->link=cur->link;
        cur->link=temp;
    }
    else if(pos>=count+1)
    {
        printf("There are less than %d elements in the linked list\n",pos);
    }

}

void display(NODE first)
{NODE cur;
    if(first == NULL)
    {
        printf(" {}\n");
        return;
    }
    else if(first->link==NULL)
    {
        printf(" {}\n");
        return;
    }

    else
    {
        cur=first;
        while(cur!=NULL)
        {

            printf(" %d",cur->data);
            cur=cur->link;
        }

    printf("\n");
    }
}

void deleteany(NODE first)
{   int item;
NODE temp,cur;
    printf("Enter the element to be deleted : \n");
    scanf("%d",&item);
    if(first==NULL)
    {
        printf("Linked list is empty\n");
    }
    else if(first->data==item)
    {
      temp=first;
      first=first->link;

      nodefree(temp);
    }
    else
    {
      cur=temp=first;
      while(cur->link!=NULL && cur->data!=item)
      {
          temp=cur;
          cur=cur->link;
      }
      if(cur->data==item)
      {
          temp->link=cur->link;
          nodefree(temp);
      }
      else{
          printf("%d is not present in the linked list\n",item);      }
    }

}


void search(NODE first)
{NODE temp;
int item;
    printf("Enter the element to be searched :\n");
    scanf("%d",&item);
    temp=first;
    while(temp!=NULL && temp->data!=item)
    {
        temp=temp->link;
    }

   if(temp==NULL)
   {
       printf("%d is not present in the linked list\n",item);
   }
   else if(temp->data==item)
   {
       printf("element found\n");
   }
}

int main()
{
    int ch;
    NODE first;
    first=NULL;
    printf("1 - Add at Beginning\n2 - Add at position\n3 - Delete any node\n4 - search and update\n5 - Display\n6 - Exit\n");
    for(;;)
    {
        printf("Enter your choice :\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: first=insertfront(first);
            break;
            case 2: insertany(first);
            break;
            case 3: deleteany(first);
            break;
            case 4:search(first);
            break;
            case 5:printf("Elements in the List are");
            display(first);
            break;
            case 6:exit(0);
            break;
            default:printf("Choice is incorrect, Enter a correct choice\n");

            break;


        }
    }
    return 0;
}
