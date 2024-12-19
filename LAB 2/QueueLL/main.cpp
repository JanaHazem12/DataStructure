#include <iostream>

using namespace std;

class QueueNode{
		public:
		int data;
		QueueNode * next;
		QueueNode(int dataa){
			data=dataa;
			next=NULL;
	}
};

class QueueLL{
		public:
		QueueNode * front;
		QueueNode * rear;
		QueueLL(){
			front=rear=NULL;
		}
		void enqueue(int data){
			QueueNode * newNode = new QueueNode(data);
			// case: empty list //
			if(front == NULL && rear == NULL){
				front=rear=newNode;
				return;
			}
			// case: NOT empty //
			rear->next=newNode;
			//newNode->next=NULL; // NOT needed, I already handled it
			rear=newNode;

		}
		int dequeue(){
			// case: empty queue //
			int data = 0;
			if(front == NULL && rear == NULL){
				throw "Empty Queue";
			}
			QueueNode * temp = front; // temp to store the data in before removing it
			data=front->data;
			front=front->next;
			if(front == NULL){
				rear=NULL;
			}
			delete temp;
			return data;
		}
		void display(){
			// case: empty queue //
			QueueNode * current = front;
			if(front == NULL){
				cout<<"Empty Queue!!!";
			}

			while(current != NULL){
				cout<<current->data<<" ";
                current = current->next;
			}
		}

};

int main(){
	QueueLL ll;
	ll.enqueue(10);
	ll.enqueue(20);
	ll.enqueue(30);
	ll.enqueue(40);
	ll.enqueue(50);
    cout<<"queue =>  ";
	ll.display();
	cout<<endl;

	try{
	cout<<"\ndequeued value: "<<ll.dequeue()<<endl;
	cout<<"dequeued value: "<<ll.dequeue()<<endl;
	cout<<"dequeued value: "<<ll.dequeue()<<endl;
    cout<<"dequeued value: "<<ll.dequeue()<<endl;
    cout<<"dequeued value: "<<ll.dequeue()<<endl;
    cout<<"dequeued value: "<<ll.dequeue()<<endl;
	}
	catch(const char* msg){
		cout<<msg<<endl;
	}
	cout<<"\nafter dequeueing =>  ";
	ll.display();
	cout<<endl;
	return 0;
}


