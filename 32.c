#include<stdio.h>

int main()
{
    int n,m,i;
    int stack[100];
    int top=-1;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&stack[++top]);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        if(top!=-1)
        {
            top--;
        }
    }

    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }

    return 0;
}