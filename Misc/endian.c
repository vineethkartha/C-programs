#include<stdio.h>

int main()
{
    int a=2;
    char *b=(char *)&a;
    printf("%d--%d--%d--%d\n",*b,*(b+1),*(b+2),*(b+3));
    return 0;
}
