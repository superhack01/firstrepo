#include<iostream>
#include<string>
#include<cmath>
#include<stack>

#define ll long long

using namespace std;

class Stack{
	public : 
		int top;
		int size;
		int * arr;

		Stack(int size){
			this->size = size;
			arr = new int[size];
			top = -1;
		}

		void push(int value){
			if ((size-top) > 1){
				top++;
				arr[top] = value;
			}
			else {
				cout<<"Stack Overflow!!, No Space!"<<endl;

			}
		}

		void pop(){
			if ((top) >= 0){
				top--;
			}
			else {
				cout<<"Stack is empty. Stack Underflow!!"<<endl;

			}
		}

		int peek(){
			if (top < 0){
				cout<<"Stack is empty! : ";
				return 0;
			}
			return arr[top];
		}

		int sizeofstack(){
			return (top+1);
		}

};

int main () {
	
	Stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);

	cout<<s.peek()<<endl;

	s.pop();
	s.pop();
	s.pop();
	cout<<s.peek()<<endl;


	return 0;
}