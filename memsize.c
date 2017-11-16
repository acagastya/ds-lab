/*
variable memory size
*/

#include <stdio.h>
int main()
{
    char a;
    int b;
    float c;
    double d;
    printf("size of char = %tu\nsize of int = %tu\nsize of float = %tu\nsize of double = %tu\n", (char*)(&a + 1) - (char*) &a, (char*)(&b + 1) - (char*) &b, (char*)(&c + 1) - (char*) &c, (char*)(&d + 1) - (char*) &d);
    return 0;
}
