#include<iostream>
#include<string>
#include<cmath>

#define ll long long

using namespace std;

class queue{
	int * arr = new int[15];
	int top = -1;

	public:
	    void push(int value){
			top++;
			arr[top] = value;
		}
		void pop(){
			if (top == -1){
				cout<<"Can't pop! queue is empty."<<endl;
			}
			else {
				for (int i = 0;i<top;i++){
					arr[i] = arr[i+1];
				}
				top--;
			}
		}
		bool isempty(){
			if (top == -1){
				return true;
			}
			else return false;
		}
		int topelement(){
			if (top == -1){
				cout<<"Queue is empty!";
				return -1;
			}
			return arr[0];

		}
		void showqueue(){
			for (int i = 0;i<=top;i++){
				cout<<arr[i]<<" ";
			}cout<<endl;
		}

};

int main () {
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	q.showqueue();

	cout<<q.topelement()<<endl;;

	q.pop();

	q.showqueue();

	cout<<q.topelement()<<endl;


	return 0;
}