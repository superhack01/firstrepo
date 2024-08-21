#include<iostream>

using namespace std;

class node {
	public:
	int data;
	node * next;
	node * prev;

	node(int value){
		this->data = value;
		this->next = NULL;
		this->prev = NULL;
	}

	~node(){
		int value = this->data;
		////memory free
		if (this->next != NULL){
			delete next;
			this->next = NULL;
			this->prev = NULL;
		}
	}
};

void insertAtHead(node* &head,int value){
	node * n = new node(value);
    if (head == NULL){
		head = n;
	}
	else {
		n->next = head;
	 	head -> prev = n;
	 	head = n;
	}
}


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

void deleteNode(node * &head, int position){
	node * pervious = NULL;
	node * currentNode = head;

	if (position == 1){
		node * temp = head;

		head = head->next;
		head->prev = NULL;

		temp->next = NULL;
		delete temp;

		return ;
	}
	int cnt = 1;
	while(cnt < position){
		pervious = currentNode;
		currentNode = currentNode->next;
		cnt++;
	}
	if (currentNode->next == NULL){
		pervious->next = NULL;
		currentNode -> prev = NULL;
	}
	else {
		pervious->next = currentNode->next;
		currentNode -> next -> prev = pervious;

		currentNode->next = NULL;
		currentNode->prev = NULL;
	}

	delete currentNode;

}


void display(node * &head){
	node * temp = head;

	while(temp->next != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}cout<<temp->data<<"->"<<"NULL"<<endl;

}

int main (){
	// node * n = new node(5);
	node * head = NULL;

	// display(head);

	insertAtTail(head,10);
	insertAtTail(head,20);
	insertAtTail(head,30);
	insertAtTail(head,40);
	insertAtTail(head,50);
	display(head);

	deleteNode(head,1);
	display(head);

	deleteNode(head,2);
	display(head);

	deleteNode(head,3);
	display(head);


	return 0;	
}
