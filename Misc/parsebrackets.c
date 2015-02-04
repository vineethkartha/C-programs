#include<stdio.h>
int main()
{
    char str[100];
    scanf(" %[^\n]s ",str);
    int i,cntp=0,cntsqb=0,cntflb=0;
    for(i=0;str[i]!='\0';i++)
    {
        switch(str[i])
        {
            case '{':cntflb++;break;
            case '}':cntflb--;break;
            case '[':cntsqb++;break;
            case ']':cntsqb--;break;
            case '(':cntp++;break;
            case ')':cntp--;break;
        }
    }
    printf("\n The Square brakets are: %d\n The flower brackets are %d\n The parantheses are %d\n",cntsqb,cntflb,cntp);
    return 0;
}
