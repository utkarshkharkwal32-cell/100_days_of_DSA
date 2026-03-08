#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void push(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop()
{
    if(top==NULL)
        return -1;

    struct Node* temp=top;
    int val=temp->data;
    top=top->next;
    free(temp);
    return val;
}

int main()
{
    char exp[100];
    int i=0,a,b,res;

    fgets(exp,100,stdin);

    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i]-'0');
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            b=pop();
            a=pop();

            if(exp[i]=='+') res=a+b;
            else if(exp[i]=='-') res=a-b;
            else if(exp[i]=='*') res=a*b;
            else if(exp[i]=='/') res=a/b;

            push(res);
        }
        i++;
    }

    printf("%d",pop());

    return 0;
}