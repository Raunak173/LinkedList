#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){ //Constructor
        data=d;
        next=NULL;
    }
};

void print(node *head){
    while(head->next!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<head->data;
    cout<<endl;
}

void insertAtHead(node *&head,int data){ //We are passing head by reference, that's why we used & symbol.
    if(head==NULL){
        head = new node(data);
        return;
    }
    node *x = new node(data);
    x->next=head;
    head=x;
}

void insertAtTail(node *&head,int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node *x= new node(d);
    tail->next=x;
}

node *midPoint(node *head){
    if(head==NULL or head->next==NULL) return head;
    node *slow=head;
    node *fast=head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node *merge(node *a,node *b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    node *c;
    if((a->data)<(b->data)){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

node *mergeSort(node *&head){
    if(head==NULL or head->next==NULL) return head;
    node *mid = midPoint(head);
    node *a=head;
    node *b=mid->next;
    a=mergeSort(a);
    b=mergeSort(b);
    node *c=merge(a,b);
    return c;
}

int main(){
    node *head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,8);
    insertAtTail(head,1);
    insertAtTail(head,4);
    insertAtTail(head,2);
    print(head);
    head=mergeSort(head);
    print(head);
    return 0;
}