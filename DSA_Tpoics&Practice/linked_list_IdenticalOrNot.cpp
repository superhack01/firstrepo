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

void insertt(node* &head, int value, int position){
    node* n = new node(value);
    if (position == 1){
        n->next = head;
        head = n;
    }
    else {
        node* temp = head;
        int count = 1;
        while(count<position-1){
            temp = temp->next;
            count++;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void identical(node* &a, node* &b){
    int x = 1;
    while((a != NULL)&&(b != NULL)){
        if (a->data == b->data){
            x = 1;
        }
        else {
            x = 0;
            break;
        }
        a = a->next;
        b = b->next;
    }
    if (x==1){
        cout<<"Identical!"<<endl;
    }
    else cout<<"Not Identical!."<<endl;

}

int main () {
    node* a = NULL;
    node* b = NULL;
    insertt(a, 1,1);
    insertt(a, 1,1);
    insertt(a, 2,3);
    insertt(a, 4,3);
    display(a);
    insertt(b, 1,1);
    insertt(b, 1,1);
    insertt(b, 3,3);
    insertt(b, 4,3);
    display(b);
    identical(a,b);

    return 0;
}
