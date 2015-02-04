#include<stdio.h>

int * fun()
{
    int x=10;
    int *a;
    a=(int *)malloc(sizeof(int));
    *a=10;
    //printf("The address inside fun is %p\n",&x);
    return a;
}
int main()
{
    printf("The address is %p\n",fun());
    return 0;
}
