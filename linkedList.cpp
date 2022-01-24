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

int length(node *head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
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

void insertByPos(node *&head,int d,int p){
    //Insert after a position. (1 based indexing)
    //We have to make (p-1) jumps.
    if(head==NULL or p==0){
        insertAtHead(head,d);
        return;
    }
    else if(p>length(head)){
        insertAtTail(head,d);
        return;
    }
    else{
        int jump=1;
        node *temp=head;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        node *x=new node(d);
        x->next=temp->next;
        temp->next=x;
    }
}

void deleteHead(node *&head){
    if(head==NULL) return;
    node *temp=head->next;
    delete head;
    head=temp;
}

void deleteTail(node *&head){
    if(head==NULL) return;
    node *tail=head;
    while(tail->next->next!=NULL){
        tail=tail->next;
    }
    node *temp=tail->next;
    tail->next=NULL;
    delete temp;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}

node *reverse(node *head){
    if(head==NULL or head->next==NULL) return head;
    node *newHead = reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
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

bool detectCycle(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

node* detectMeetingPointInCycle(node *head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return slow;
    }
    return NULL;
}

node *detectCycleNode(node *head){
    //First node from where the cycle starts.
    node *meet=detectMeetingPointInCycle(head);
    node *start=head;
    while(start!=meet){
        start=start->next;
        meet=meet->next;
    }
    return start;
}

void deleteCycle(node *&head){
    node *slow=head;
    node *fast=head;
    while(slow!=NULL and fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow==head){
        while(fast->next!=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else if(slow==fast){
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}

int main(){
    node *head=NULL;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertByPos(head,4,3);
    insertAtTail(head,7);
    deleteHead(head);
    deleteTail(head);
    print(head);
    node *mid = midPoint(head);
    cout<<(mid->data)<<endl;
    node *revList = reverse(head);
    print(revList);
    return 0;
}
