#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

#define ll long long

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtHead(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    head = n;

}

void insertAtTail(node* &head, int value){
    node* n = new node(value);
    if (head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertInMiddle (node* &head,int position, int value){
    node* n = new node(value);
    if (position==1){
        n->next = head;
        head = n;
        return;
    }
    node* temp = head;
    int count = 1;
    while(count<(position-1)){
        temp = temp->next;
        count++;
    }

    n->next = temp->next;
    temp->next = n;

}


int main () {
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);

    insertInMiddle(head,3,4);
    display(head);

    insertInMiddle(head,1,4);
    display(head);

    insertInMiddle(head,6,44);
    display(head);

    insertInMiddle(head,7,100);
    display(head);
    
    return 0;
}
