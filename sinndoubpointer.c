/*
single and double pointer
*/

#include <stdio.h>

int main()
{
    float f, *pf1, **pf2;
    pf1 = &f;
    pf2 = &pf1;
    printf("Enter the number\n");
    scanf("%f", &f);
    printf("Value of f = %.3f, *pf1 = %.3f, **pf2 = %.3f\n", f, *pf1, **pf2);
    printf("Address of f = %p, Value of pf1 = %p, Value of pf2 = %p\n", &f, pf1, pf2);
    return 0;
}
