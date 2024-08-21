#include<iostream>
#include<cmath>
#include<algorithm>

#define ll long long 

using namespace std;

class node{
    public :
     int data;
     node * prev;
     node * next;

     node (int value){
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
     }
};

void BuildList(node * &head, node * &tail,int d){
    node * n = new node(d);

    if (head == NULL){
        head = n;
        tail = n;
        return ;
    }

    node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    tail = n;

    return ;
}

void display(node * head){
    node * temp = head;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void reverseprint(node * tail){
    node * temp = tail;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->prev;
    }cout<<"NULL"<<endl;

}

void solve(node * &head, node * &tail, int pos,int n){
    int position = 1;
    node * temp = tail;

    while (position != pos){
       temp = temp->prev;
       position++;
    }

    if (pos == 1){
            tail = temp->prev;
            temp->prev->next =  NULL;
            temp->prev = NULL;
            delete temp;
    }
    else if (pos == n){
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev == NULL;
        delete temp;
    }
}

int main() {
    int n;
    cin>>n;

    node * head = NULL;
    node * tail = NULL;

    for (int i = 0;i<n;i++){
        int x;
        cin>>x;

        BuildList(head,tail,x);
    }

    // display(head);
    // reverseprint(tail);

    int pos;
    cin>>pos;

    solve(head,tail,pos,n);

    display(head);

    return 0;
}