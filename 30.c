#include <stdio.h>
#include <stdlib.h>
struct Node{
    int c,e;
    struct Node*next;
};
struct Node*newNode(int c,int e){
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->c=c;
    temp->e=e;
    temp->next=NULL;
    return temp;
}
void print(struct Node*h){
    struct Node*t=h;
    while(t){
        if(t->e==0)printf("%d",t->c);
        else if(t->e==1)printf("%dx",t->c);
        else printf("%dx^%d",t->c,t->e);
        t=t->next;
        if(t)printf(" + ");
    }
    printf("\n");
}
int main(){
    int n,c,e;
    if(scanf("%d",&n)!=1)return 0;
    struct Node*h=NULL,*curr=NULL;
    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);
        struct Node*node=newNode(c,e);
        if(!h)h=curr=node;
        else{
            curr->next=node;
            curr=node;
        }
    }
    print(h);
    return 0;
}