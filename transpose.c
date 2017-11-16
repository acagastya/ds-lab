/*
transpose of matrix
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a, n, i, j;
    printf("Enter order of matrix\n");
    scanf("%d", &n);
    a = calloc(n, sizeof(int *));
    for(i = 0; i < n; i ++)
        *(a + i) = calloc(n, sizeof(int));
    printf("Enter matrix values\n");
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
            scanf("%d", (*(a + i) + j));
        }
    }
    printf("The given matrix is\n");
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
            printf("%d", *(*(a + i) + j));
            if(j == n - 1)
                continue;
            printf(" ");
        }
        printf("\n");
    }
    printf("Transpose matrix is\n");
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
            printf("%d", *(*(a + j) + i));
            if(j == n - 1)
                continue;
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
