#include <iostream>

using namespace std;

class stackedNode{
		public:
		int data;
		stackedNode * prev;
		stackedNode(int dataa){
			data=dataa;
			prev=NULL;
	}
};

class stackedLL{
		public:
		stackedNode * tail;
		stackedLL(){
			tail=NULL;
		}
		void push(int data){
			// case: empty list //
			stackedNode * newNode = new stackedNode(data);
			if(tail == NULL){
				tail=newNode;
				return;
			}
			// case: NOT empty //
			newNode->prev=tail;
			tail=newNode; // moved the tail

		}
		int pop(){
		// case: empty list //
			int data = 0;
			if(tail == NULL){
				throw "Empty List";
			}
			stackedNode * temp = tail; // temp to store the data in before removing it
			data=tail->data;
			tail=tail->prev;
			delete temp;
			return data;
		}

		int peek(){
			// case: empty list //
			if(tail == NULL){
				throw "Empty List";
			}
			cout<<"Last Node: ";
			return tail->data;
		}

		void display(){
			// case: empty list //
			stackedNode * current = tail;
			if(tail == NULL){
				cout<<"Empty List!!!";
			}

			while(current != NULL){
				cout<<current->data<<" ";
				current = current->prev;
			}
		}

};

int main()
{
    stackedLL ll;
	ll.push(10);
	ll.push(20);
	ll.push(30);
	ll.push(40);
	ll.push(50);
	ll.push(60);
    cout<<"list =>  ";
	ll.display();
	cout<<endl;

	try{
	cout<<"\npopped value: "<<ll.pop()<<endl;
	cout<<"popped value: "<<ll.pop()<<endl;
	cout<<"popped value: "<<ll.pop()<<endl;
	cout<<"popped value: "<<ll.pop()<<endl;
	cout<<"popped value: "<<ll.pop()<<endl;
    cout<<"popped value: "<<ll.pop()<<endl;
	}
	catch(const char& msg){
		cout<<msg<<endl;
	}
	cout<<"\nafter poping =>  ";
	ll.display();
	cout<<endl;
    return 0;
}
