#include<stdio.h>
#include<stdlib.h>

int main()
{
    float x[100],alpha=0.98;
    int i;
    int duration=100;
    int size_y=100*duration;
    float y[10000];
    srand(time(NULL));
    for(i=0;i<100;i++)
    {
        x[i]=((double) rand() / (RAND_MAX));
        y[i]=x[i];
        //printf("%f\n",y[i]);
    }
    for(i=100;i<10000;i++)
    {
        y[i]=alpha*y[i-100];
    }
    for(i=0;i<10000;i++)
        printf("%f\n",y[i]);
    return 0;
}
