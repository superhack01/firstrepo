#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class node{
	public:
	int data;
	node * next;
	node * prev;
	node (int value){
		this->data = value;
		this->next = NULL;
		this->prev = NULL;
	}
};


void insertAtTail(node * &head,int value){
	node * n = new node(value);

	if (head == NULL){
		head = n;
	}
	else {
		node * temp = head;
		while(temp->next != NULL){
			temp = temp -> next;
		}
	
		temp -> next = n;
		n->prev = temp;
	}
	
}

void display(node * & head){
	node * temp = head;

	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp -> next;
	}cout<<"NULL"<<endl;

}

void reverseDoubly(node * &head){
	node * forward = head;
	node * temp;

	while (forward != NULL){
		temp = forward;
		forward = temp->next;
		swap(temp->next, temp->prev);
	}

	head = temp;

}

int main(){
	node * head = NULL;

	insertAtTail(head,2);
	insertAtTail(head,5);
	insertAtTail(head,10);
	insertAtTail(head,20);

	display(head);

	reverseDoubly(head);

	display(head);

	
	return 0;
}
