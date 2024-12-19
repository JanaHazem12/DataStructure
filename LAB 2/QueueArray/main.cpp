#include <iostream>

using namespace std;

class QueueArray{
    public:
    int *elements;
    int front;
    int rear;
    int size; // always a fixed array

    QueueArray(int sizee=5){ // assign a default value
        elements = new int[sizee];
        size = sizee;
        front=rear=-1;
    }

    int isEmpty(){
        if(front == -1 && rear == -1){
            return 1;
        }
        return 0;
    }

    int isFull(){
        if(front == 0 && rear == size-1){
            return 1;
        }
        if(front == rear + 1){ // OR rear = front - 1
            return 1;
        }
        return 0;
    }
    int enqueue(int data){
        // case: full queue //
        if(isFull()){ // front is at index 0 && rear is at the last index --> FULL
            //throw "Full list!!";
            //cout<<"full "<<endl;
            return 0;
        }
        // case: empty queue //
        if(isEmpty()){
            //front++; // front=rear=0
            //rear++; // ^^
            //cout<<"empty "<<endl;
            front=rear=0;
            //return 0;
            //elements[rear] = data; - for better readability
        }
        // case: not empty and not full //
        else if(front != 0 && rear == size - 1){ // front is NOT at 0 && rear is at the last index --> put rear in 0
            //cout<<"c "<<endl;
            rear = 0;
            //elements[rear] = data;
        }
        else{
            //cout<<"else "<<endl;
            rear++;
            //elements[rear] = data; - for better readability
        }
        //cout<<"REAR: "<<rear<<endl;
        elements[rear] = data;
        return 1;
    }

    int dequeue(){
        // case: empty list //
        int data = elements[front];
        if(isEmpty()){
            throw "Empty Queue";
        }
        // case: 1 element only //
        if(front==rear){
            front=rear=-1;
        }
        //is(isFull()){
        else if(front == size-1){
            //int temp = front;
            //data = elements[front];
            //front++;
            //rear++;
            front = 0;
        }
        else{
            front++;
        }
        return data;
    }
    void display(){
        for(int i=0; i<size; i++){
            cout<<elements[i]<<" ";
        }
    }
};

int main()
{
    int data;
    QueueArray qa(5);
    qa.enqueue(10)?cout<<"SUCCESS ":cout<<"FAILURE ";
    qa.enqueue(20)?cout<<"SUCCESS ":cout<<"FAILURE ";
    qa.enqueue(30)?cout<<"SUCCESS ":cout<<"FAILURE ";
    qa.enqueue(40)?cout<<"SUCCESS ":cout<<"FAILURE ";
    qa.enqueue(50)?cout<<"SUCCESS ":cout<<"FAILURE "; // failed
    //qa.enqueue(60)?cout<<"SUCCESS ":cout<<"FAILURE "; // failed
    cout<<endl<<"Queue => ";
    qa.display();
    cout<<endl;

    try{
        //cout<<"data dequeued: "<<data<<" ";
        //data=qa.dequeue();
        cout<<"data dequeued: "<<qa.dequeue()<<endl;
        //cout<<"data dequeued: "<<qa.dequeue();
        //qa.display();
    }
    catch(const char* msg){
        cout<<msg<<"\n";
    }
    /*qa.enqueue(80)?cout<<"SUCCESS ":cout<<"FAILURE ";
    cout<<"data dequeued: "<<qa.dequeue()<<endl;
    cout<<"data dequeued: "<<qa.dequeue()<<endl;
    cout<<"data dequeued: "<<qa.dequeue()<<endl;
    cout<<"data dequeued: "<<qa.dequeue()<<endl;
    cout<<"data dequeued: "<<qa.dequeue()<<endl;
    cout<<"data dequeued: "<<qa.dequeue()<<endl;
    qa.display();*/


    return 0;
}
