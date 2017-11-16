/*
Stack : Linked List Implementation : Push and Pop

Consider implementing a stack using a Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void push(struct node **q, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = num;
    temp->link = NULL;
    if(*q == NULL)
        *q = temp;
    else
    {
        temp->link = *q;
        *q = temp;
    }

}

void display(struct node *q)
{
    struct node *cur = q;
    if(cur == NULL)
        printf(" {}\n");
    else
    {
        while(cur != NULL)
        {
            printf(" %d", cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
}

int pop(struct node **q)
{
    struct node *temp = *q;
    int data;
    if(temp == NULL)
    {
        printf("Stack is empty\n");
        return -1000;
    }
    else
    {
        (*q) = (*q)->link;
        data = temp->data;
        free(temp);
        return data;
    }
}

int main()
{
    int choice = 1, data;
    struct node *q = NULL;
    while(choice)
    {
        printf("Choice 1 : Push\nChoice 2 : Pop\nChoice 3 : Display\nAny other choice : Exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed\n");
                scanf("%d", &data);
                push(&q, data);
            break;
            case 2:
                data = pop(&q);
                if(data != -1000)
                    printf("The popped element is %d\n", data);
            break;
            case 3:
                printf("The contents of the stack are");
                display(q);
            break;
            default:
                choice = 0;
        }
    }
    return 0;
}
