#include<iostream>
#include<cmath>

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
        return ;
    }

    node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}

void solution(node * &newhead, node * &head1, node * &head2){
    node * temp1 = head1;
    node * temp2 = head2;

    while (temp1 != NULL && temp2 != NULL){
        // cout<<"YES"<<endl;
        if (temp1->data <= temp2->data){
            cout<<temp1->data<<"->";
            BuildList(newhead,temp1->data);
            temp1 = temp1->next;
        }
        else {
            cout<<temp2->data<<"->";
            BuildList(newhead,temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL){
        cout<<temp1->data<<"->";
        BuildList(newhead,temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        cout<<temp2->data<<"->";
        BuildList(newhead,temp2->data);
        temp2 = temp2->next;
    }

    cout<<"NULL"<<endl;
}

void display(node * head){
    node * temp = head;
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    int n;
    cin>>n;

    node * head1 = NULL;
    node * head2 = NULL;

    for (int i = 0;i<n;i++){
        int x;
        cin>>x;
        BuildList(head1,x);
    }
    for (int i = 0;i<n;i++){
        int x;
        cin>>x;
        BuildList(head2,x);
    }

    display(head1);
    display(head2);

    node * newhead = NULL;

    // display(newhead);

    solution(newhead,head1, head2);

    display(newhead);

    return 0;    
}