/*
stack push and pop array implementation
*/

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int * a;
    int top;
    int maxSize;
};

void initstack(struct stack * p, int maxSize)
{
    p->top = -1;
    p->maxSize = maxSize;
    p->a = calloc(maxSize, sizeof(int));
}

void push(struct stack *p, int item)
{
    if(p->top == p->maxSize - 1)
        printf("Stack is full\n");
    else
        p->a[++p->top] = item;
}

int pop(struct stack *p)
{
    if(p->top== -1)
    {
        printf("Stack is empty\n");
        return -1000;
    }
    else
        return p->a[p->top--];
}

void display(struct stack p)
{
    int i = 0;
    if(i > p.top)
        printf(" {}");
    else
        for(i = 0; i <= p.top; i++)
            printf(" %d", p.a[i]);
}

int main()
{
    struct stack p;
    int choice = 1, item, maxSize;
    printf("Enter the maximum size of the stack\n");
    scanf("%d", &maxSize);
    initstack(&p, maxSize);
    while(choice)
    {
        printf("Choice 1 : Push\nChoice 2 : Pop\nChoice 3 : Display\nAny other choice : Exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed\n");
                scanf("%d", &item);
                push(&p, item);
                break;
            case 2:
                item = pop(&p);
                if(item == -1000)
                    break;
                printf("The popped element is %d\n", item);
                break;
            case 3:
                printf("The contents of the stack are");
                display(p);
                printf("\n");
                break;
            default:
                choice = 0;
        }
    }
    return 0;
}
