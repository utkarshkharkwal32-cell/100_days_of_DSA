#include <stdio.h>

int main()
{
    int n,m,i;
    
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
    scanf("%d",&m);
    
    int front=0;
    
    for(i=0;i<m;i++)
        front=(front+1)%n;
        
    for(i=0;i<n;i++)
        printf("%d ",arr[(front+i)%n]);
    
    return 0;
}