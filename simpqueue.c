/*
Queue
*/

  #include<stdio.h>
#include<stdlib.h>
struct queue
{
    int arr[5];
    int front,rear;

};
void init(struct queue *p)
{
    p->front=-1;
    p->rear=-1;
}
void insert(struct queue *p,int item)
{
    if(p->rear==4)
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        printf("Enter the element to be inserted :\n");
        scanf("%d",&item);
        if(p->front==-1)
        p->front=0;
        p->rear++;
        p->arr[p->rear]=item;
    }
}
int del(struct queue *p)
{
    int temp;
    if(p->front==-1)
    {
        printf("Queue Underflow\n");
        return -1000;
    }
    temp=p->arr[p->front];
    p->front++;
    if(p->front>p->rear)
    p->front=p->rear=-1;
    return temp;
}
void display(struct queue p)
{
    int i;
    if(p.front==-1)
    printf("Queue is empty\n");
    else
    {
        printf("Elements in the Queue :\n");
        for(i=p.front;i<p.rear;i++)
        printf("%d ",p.arr[i]);
        printf("%d \n",p.arr[p.rear]);
    }
}
int main()
{
    struct queue q;
    int choice,item=-1,p;
    init(&q);
    do
    {
        printf("1.Insert element to queue\n2.Delete element from queue\n3.Display all elements of queue\n4.Quit\nEnter your choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert(&q,item);
            break;
            case 2 : p=del(&q);
            if(p!=-1000)
            printf("Element deleted from queue is : %d\n",p);
            break;
            case 3 : display(q);
            break;
         //   case 4 : printf("Quit\n");
          //  break;
            default : exit(0);
            break;
        }
    }while(choice==1 || choice==2 || choice==3);
    return 0;
}
