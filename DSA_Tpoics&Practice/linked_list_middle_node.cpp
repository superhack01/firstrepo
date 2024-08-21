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

void middleNode(node * &head){
    node * fast = head;
    node * slow = head;

    while (fast != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    cout<<slow->data<<endl;
}

void middlenodebyrecursion(node * &head, node * curr, node * prev){
    if (curr == NULL){
        head = prev;
        return ;
    }

    node * forward = curr->next;
    middlenodebyrecursion(head, forward, curr);
    curr->next = prev;
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

    // reverselist(head);

    // display(head);

    // middleNode(head);

    middlenodebyrecursion(head,head,NULL);
    display(head);


    return 0;
}
