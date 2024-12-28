#include <iostream>

using namespace std;


class Node{
    public:
    Node * prev; // points at another node
    int data;
    Node * next; // points at another node
        Node(){
            prev=nullptr;
            data=0;
            next=nullptr;
        }
        Node(int dataa){
            prev=nullptr;
            data=dataa;
            next=nullptr;
        }
        ~Node(){}
};

class LinkedList{
    private:
    Node * head;
    Node * tail;
    int counter;


    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
            counter = 0;
        }
        ~LinkedList(){
        }

        void addNode(int data){
            Node * newNode = new Node(data);
            if(head == NULL){ // no nodes available, inserting 1st node
                newNode->data=data;
                //prev=next=NULL;
                head=newNode;
                tail=newNode;
                counter++;
                return;
            }
            tail->next=newNode; // N1(head=tail) - N2(tail)
            //tail=newNode; // check what the tail is gonna point at THEN move it
            newNode->prev=tail;
            tail=newNode;
            counter++;
            //tail->next=NULL;
            //tail->prev=head;
        }
        void remove(int data){ // removing 1 element that contains 'data'
            Node* newHead = head; // made a ptr to NOT move the head
            if(newHead == NULL){
                cout<<"Empty List!!!"<<endl;
                return;
            }
            while(newHead->data!=data){ // if the node's data ! = data we want , increment
                newHead = newHead->next;
            }
            // REMOVE //
            // 3 cases // removing 1st node, a node in the middle, last node //
            // FIRST node //
            if(newHead == head){
                if(newHead == tail){ // only 1 node in the list, remove it --> empty list
                    head=tail=NULL;
                    counter=0;
                    cout<<"list is empty now!!"<<endl;
                }
                else{ // remove 1st node
                head = head->next;
                head->next->prev = NULL; // **
                //cout<<"1st"<<endl;
                counter--;
                }
            }
            // LAST node //
            else if(newHead == tail){ // newHead->next = NULL
                tail = tail->prev; // let the tail point at the pvs one ?? tail->prev->next
                tail->next = NULL; // node before the last one now points at NULL
                counter--;
            }
            else{
            // a node in the MIDDLE //
                newHead->prev->next = newHead->next;
                newHead->next->prev = newHead->prev;
                counter--;
                //cout<<"middle"<<endl;
            // newHead->prev  <--
            }
            //delete newHead;
        }
        int getCount(){
            return counter;
    }
    void display(){
        Node * loopNode = head;
        while(loopNode!=NULL){
            cout<<loopNode->data<<" ";
            loopNode = loopNode->next;
        }
    }
    void insertAfter(int data, int afterData){
        // loop & check the node which has 'data' , insert a new node after it that consists of 'afterData'
        if(head==NULL){
            cout<<"Empty List!!!";
            return;
        }
        Node * AfterHead = head;
        while(AfterHead->data!=data){
            AfterHead = AfterHead->next;
        }
        // DATA FOUND //
        // INSERT A NEW NODE //
        // cases: insert after last node
        Node * AfterNode = new Node(afterData);
        if(AfterHead == tail){ // DONE
            tail->next = AfterNode;
            tail = AfterNode;
            return;
        }
        /*AfterHead->next = AfterNode;
        AfterHead = AfterNode->prev;*/

        AfterNode->next = AfterHead->next;
        AfterHead->next->prev = AfterNode;
        AfterNode->prev = AfterHead;
        AfterHead->next = AfterNode;

        //AfterNode->next = AfterHead->next->next; // maybe
        //AfterNode->prev = AfterNode->next->prev;

        //AfterHead = AfterNode;
        //AfterNode->next = AfterHead->next;

        //AfterNode = AfterHead->next;
        //AfterNode = AfterHead->prev;
        //AfterNode = AfterHead;

        //AfterNode->prev->next = AfterHead->next;
        //AfterNode->next->prev = AfterHead->prev;
    }
    void insertBefore(int data, int beforeData){
        if(head==NULL){
            cout<<"Empty List!!!";
            return;
        }
        Node * current = head;
        while(current->data!=data){
            current = current->next;
        }
        Node * BeforeNode = new Node(beforeData);
        // case: insert before 1st element
        if(head->data == data){
            //cout<<"HERE\n";
            //BeforeNode->prev = head->prev;
            //head->prev = BeforeNode;
            //BeforeNode = head;
            //BeforeNode->next = head;
            head->prev = BeforeNode;
            BeforeNode->next = head;
            head = BeforeNode; // NOT BeforeNode = head
            return;
        }
        /*BeforeNode->prev = current->prev;
        BeforeNode = current->prev;*/
        //BeforeNode->next = current;
        //cout<<"here\n";

        /*BeforeNode->prev = current->prev;
        current->prev = BeforeNode;*/

        //cout<<"HERE";
        BeforeNode->prev = current->prev;
        BeforeNode->next = current->prev->next;
        BeforeNode->prev->next = BeforeNode;
        //BeforeNode = current->prev;
}

    int getDatabyIndex(int index){ // 5,10,20 (012) index = 2 --> get 20
        Node * loopNodee = head;
        int c=0;
        while(loopNodee!=NULL){
            //cout<<loopNodee->data<<" ";
            if(c==index){
                //cout<<"here\n";
                //cout<<loopNodee->data;
                int x = loopNodee->data;
                cout<<"Data in index "<<c<<": ";
                return x;
            }
            loopNodee = loopNodee->next;
            c++;
        }
        //cout<<"INDEX NOT FOUND ";
        return 0;
    }


};

int main()
{
    LinkedList l;
    l.addNode(70);
    l.addNode(80);
    l.addNode(90);
    l.addNode(100);

    //l.display();
    //cout<<endl;
    //cout<<"count before removing: "<<l.getCount()<<endl;
    //l.remove(90);
    //l.remove(20);
    //l.remove(6);
    //cout<<endl;
    //l.display();
    //cout<<endl;
    //cout<<"count after removing: "<<l.getCount()<<endl;

    //l.insertAfter(90,102);
    //l.display();

    //l.insertBefore(70,7);
    l.display();

    //cout<<l.getDatabyIndex(3);



    return 0;
}
