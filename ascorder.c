/*
sort in ascending
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *a, i, flag = 0, j;
    a = calloc(15, sizeof(int));
    printf("Enter the number of elements in an array\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(i = 0; i < n; i ++)
        scanf("%d", a + i);
    for(i = 0; i < n; i ++)
    {
        flag = 1;
        for(j = 0; j < n - 1; j ++)
        {
            if(*(a + j) > *(a + j + 1))
            {
                flag = 0;
                *(a + j) += *(a + j + 1);
                *(a + j + 1) = *(a + j) - *(a + j + 1);
                *(a + j) -= *(a + j + 1);
            }
        }
        if(flag == 1)
            break;
    }
    printf("Sorted array\n");
    for(i = 0; i < n; i ++)
        printf("%d ", *(a + i));
    return 0;
}
