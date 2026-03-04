#include <stdio.h>

int stack[1000],top=-1;

void push(int val){
    stack[++top]=val;
}

void pop(){
    if(top==-1)printf("Stack Underflow\n");
    else printf("%d\n",stack[top--]);
}

void display(){
    for(int i=top;i>=0;i--)printf("%d%s",stack[i],(i==0?"":" "));
    printf("\n");
}

int main(){
    int n,choice,val;
    if(scanf("%d",&n)!=1)return 0;
    while(n--){
        scanf("%d",&choice);
        if(choice==1){
            scanf("%d",&val);
            push(val);
        }else if(choice==2)pop();
        else if(choice==3)display();
    }
    return 0;
}