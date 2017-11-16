/*
evaluate postfix
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct postfix
{
    int stack[50];
    char *s;
    int nn,top;
};
void initpostfix(struct postfix *p)
{
    p->top=-1;
}
void setexpr(struct postfix *p,char *e)
{
    p->s=e;
}
void push(struct postfix *p,int i)
{
    if(p->top==49)
    return;
    else
    {
        ++p->top;
        p->stack[p->top]=i;
    }
}
int pop(struct postfix *p)
{
    int i;
    if(p->top==-1)
    return 0;
    else
    {
        i=(p->stack[p->top]);
        --(p->top);
        return i;
    }
}
void calculate(struct postfix *p)
{
    int n1,n2,i=0;
    while (*(p->s+i)!='\0')
    {
        if(isdigit(*(p->s+i)))
        {
            p->nn=*(p->s+i)-48;
            push(p,p->nn);
        }
        else
        {
            n1=pop(p);
            n2=pop(p);
            switch(*(p->s+i))
            {
                case '+': p->nn=n1+n2;
                break;
                case '-': p->nn=n2-n1;
                break;
                case '*': p->nn=n1*n2;
                break;
                case '/': p->nn=n2/n1;
                break;
                default:printf("invalid operator");
            }
            push(p,p->nn);
        }
        i++;
    }
}
void show(struct postfix p)
{
    printf("Result is: %d",pop(&p));
}
int main()
{
    struct postfix st;
    char exp[50],*e;
    printf("Enter postfix expression to be evaluated:\n");
    scanf("%s",exp);
    e=exp;
    initpostfix(&st);
    setexpr(&st,e);
    calculate(&st);
    show(st);
    return 0;

}
