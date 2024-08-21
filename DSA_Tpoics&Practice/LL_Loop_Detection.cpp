#include<iostream>
#include<cmath>
// #include<algorithm>

#define ll long long 

using namespace std;

class node{
    public :
     int data;
     node * next;

     node(int value){
        this->data = value;
        this->next = NULL;
     }

};

void BuildList(node * &head, int d){
    node * n = new node(d);

    if (head == NULL){
        head = n;
        // n->next = head;
        return ;
    }

    node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    // n->next = head;

}

void display(node * head){
    node * temp = head;

    ////for singly linked list
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;

}

bool isLooped(node * head){
    node * slow = head;
    node * fast = head;

    while (fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin>>n;

    node * head = NULL;

    node * tail = NULL;

    for (int i = 0;i<n;i++){
        int x;
        cin>>x;
        BuildList(head,x);
    }
   
    display(head);

    if (isLooped(head)){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

    return 0;    
}
