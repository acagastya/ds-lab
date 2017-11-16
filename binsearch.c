/*
binary search
*/

#include <stdio.h>
int binary(int a[], int low, int high, int key)
{
    int mid;
    if(low > high)
        return 0;
    mid = (low + high)/2;
    return (a[mid] == key)?1:(a[mid] > key)?binary(a,low, mid - 1, key):binary(a, mid + 1, high, key);
}

int main()
{
    int n, a[10], i, key;
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &key);
    if(binary(a, 0, n-1, key))
        printf("Element Found");
    else
        printf("Element Not Found");
    return 0;
}

