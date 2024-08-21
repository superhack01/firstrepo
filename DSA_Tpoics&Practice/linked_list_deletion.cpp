#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

#define ll long long

using namespace std;

class node {
    public: 
    int data;
    node* next;

    //constructor
    node(int value){
        data = value;
        next = NULL;
    }

    //destructor
    ~node(){
        int value = this->data;
        ////memory free 
        if (this->next != NULL){
            delete next;
            this->next = NULL;

        }
        // cout<<"Memory is free!";
    }

};

void insertion(node* &head, int value){
    node* n = new node(value);
    if (head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp -> next = n;

}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp -> data<<"-->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void deleteAnElement(node* &head, int position){
    if (position == 1){
        node* temp  = head;
        head = head -> next;

        // memory free start node 
        temp-> next = NULL;
        delete temp;

    }
    else {
        // deleting any middle or end node 
        node* curr = head;
        node* prev = NULL;
        int count = 1;
        while(count<position){
            prev = curr;
            curr = curr -> next ;
            count++;
        }
        prev-> next = curr-> next;
        curr -> next = NULL;
        delete  curr;
    }

}

int main () {
    node* head = NULL;
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 3);
    insertion(head, 4);
    display(head);

    deleteAnElement(head, 2);
    display(head);

    return 0;
}

