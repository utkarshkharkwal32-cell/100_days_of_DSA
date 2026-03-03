#include <iostream>
using namespace std;
struct Node{
    int coeff;
    int exp;
    Node*next;
};
Node*createNode(int c,int e){
    Node*n=new Node;
    n->coeff=c;
    n->exp=e;
    n->next=nullptr;
    return n;
}
void display(Node*h){
    Node*t=h;
    while(t!=nullptr){
        if(t->exp==0)cout<<t->coeff;
        else if(t->exp==1)cout<<t->coeff<<"x";
        else cout<<t->coeff<<"x^"<<t->exp;
        t=t->next;
        if(t!=nullptr)cout<<" + ";
    }
    cout<<endl;
}
int main(){
    int n,c,e;
    cin>>n;
    Node*head=nullptr;
    Node*curr=nullptr;
    for(int i=0;i<n;i++){
        cin>>c>>e;
        Node*newNode=createNode(c,e);
        if(head==nullptr){
            head=newNode;
            curr=newNode;
        }else{
            curr->next=newNode;
            curr=newNode;
        }
    }
    display(head);
    return 0;
}