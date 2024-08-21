#include<iostream>
#include<string>

using namespace std;

class node {
    public:
    int data;
    node * next;

    node(int value){
        this->data = value;
        this->next = NULL;
    }
};

void insertANode (node* &head,int position, int value){
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


void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverselist(node * &head){
    node * temp = head;
    node * Previ = NULL;

    node * curr = head;

    while(temp->next != NULL){
        temp = temp->next;

        curr->next = Previ;

        Previ = curr;
        curr = temp;

    }
    curr->next = Previ;

    head = temp;

}

int main(){
    node * head = NULL;

    insertANode(head,1,2);
    insertANode(head,2,3);
    insertANode(head,3,4);
    insertANode(head,4,5);
    insertANode(head,5,10);
    insertANode(head,1,1);

    display(head);

    reverselist(head);

    display(head);

    return 0;
}
