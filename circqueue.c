/*
circular queue
*/

  #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 5
struct queue
{
    char alpha[MAXSIZE][200];
    int front;
    int rear;
};
void insert(struct queue* p,char s[])
{
    if(p->front==-1)
    p->front=0;
    p->rear=(p->rear+1)%MAXSIZE;
    strcpy(p->alpha[p->rear],s);
}
void delete(struct queue* p)
{
    printf("The deleted element is %s\n",p->alpha[p->front]);
    if(p->front==(p->rear))
    {
        p->front=-1;
        p->rear=-1;
    }
    else
    {
       p->front=(p->front+1)%MAXSIZE;

    }
}
void display(struct queue p)
{
    int i;
    for(i=p.front;i<=p.rear;i++)
    printf(" %s",p.alpha[i]);

    printf("\n");
}
int main()
{
    struct queue p;
    p.front=p.rear=-1;
    char s[5];
    int ch;
    while(1)
    {
        printf("Choice 1 : Enter element into Queue\nChoice 2 : Delete element from Queue\nChoice 3 : Display\nAny other choice : Exit\nEnter your choice\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            if((p.front==p.rear+1)||(p.front==0&&p.rear==MAXSIZE-1))
            printf("Queue is full\n");
            else
            {
                printf("Enter the string to be inserted = \n");
                scanf("%s",s);
                insert(&p,s);
            }
        }
        else if(ch==2)
        {
            if(p.front==-1)
            printf("Queue is empty\n");
            else
            delete(&p);
        }
        else if(ch==3)
        {
            if(p.front==-1)
            printf("The contents of the queue are {}\n");
            else
            {
                printf("The contents of the queue are");
                display(p);
            }
        }
        else
        exit(0);
    }
    return 0;
}
