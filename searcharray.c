/*
searching an array
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *a, i, key, flag = 0;
    a = calloc(15, sizeof(int));
    printf("Enter the number of elements in an array\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("Enter the element to be searched\n");
    scanf("%d", &key);
    for(i = 0; i < n; i ++)
        if(*(a + i) == key)
        {
            flag = 1;
            break;
        }
    printf("%d is ", key);
    if(flag == 0)
        printf("not ");
    printf("present in the array\n");
    return 0;
}
