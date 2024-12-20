#include <iostream>

using namespace std;
#include <iostream>


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
                else{ // head bas ba3dee elements
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
                cout<<"middle"<<endl;
            // newHead->prev  <--
            }
            //delete newHead;
        }
        Node* removeSpecific(int data){ // removing 1 element that contains 'data'
            Node* newHead = head; // made a ptr to NOT move the head
            if(newHead == NULL){
                cout<<"Empty List!!!"<<endl;
                return NULL;
            }
            while(newHead->data!=data){ // if the node's data ! = data we want , increment
                newHead = newHead->next;
            }

            if(newHead == head){
                if(newHead == tail){ // only 1 node in the list, remove it --> empty list
                    head=tail=NULL;
                    counter=0;
                    cout<<"list is empty now!!"<<endl;
                }
                else{ // head bas ba3dee elements
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
                cout<<"middle"<<endl;
            }
            newHead->next = NULL;
            newHead->prev = NULL;
            return newHead;
        }
        int removeSpecificNext(int data){ // removing 1 element that contains 'data'
            Node* newHead = head; // made a ptr to NOT move the head
            if(newHead == NULL){
                cout<<"Empty List!!!"<<endl;
                return 0;
            }
            while(newHead->data!=data){ // if the node's data ! = data we want , increment
                newHead = newHead->next;
            }
            int temp = newHead->data;
            if(newHead == head){
                if(newHead == tail){ // only 1 node in the list, remove it --> empty list
                    head=tail=NULL;
                    counter=0;
                    cout<<"list is empty now!!"<<endl;
                }
                else{ // head bas ba3dee elements
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
                cout<<"middle"<<endl;
            // newHead->prev  <--
            }
            delete newHead;
            return temp;
        }
        int getNextData(int data){
            Node* newHead = head;
            while(newHead->data!=data){ // if the node's data ! = data we want , increment
                newHead = newHead->next;
            }
            int nextDataa = newHead->next->data;
            return nextDataa;
        }
        int getCount(){
            return counter;
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


        AfterNode->next = AfterHead->next;
        AfterNode->next->prev = AfterNode;
        AfterNode->prev = AfterHead->next;
        AfterHead->next = AfterNode;
    }
    void insertAfterSpecificData(int Searcheddata, int newData){
        // loop & check the node which has 'data' , insert a new node after it that consists of 'afterData'
        int dataa = removeSpecificNext(Searcheddata);
        if(head==NULL){
            cout<<"Empty List!!!";
            return;
        }
        Node * AfterHead = head;
        while(AfterHead->data!=Searcheddata){
            AfterHead = AfterHead->next;
        }
        // DATA FOUND //
        // INSERT A NEW NODE //
        // cases: insert after last node
        Node * AfterNode = new Node(newData);
        if(AfterHead == tail){ // DONE
            tail->next = AfterNode;
            tail = AfterNode;
            return;
        }
        AfterNode->next = AfterHead->next;
        AfterNode->next->prev = AfterNode;
        AfterNode->prev = AfterHead->next;
        AfterHead->next = AfterNode;
    }
    void insertAfterSpecific(int data, Node * AfterNode){
        // loop & check the node which has 'data' , insert a new node after it that consists of 'afterData'
        int dataa = removeSpecificNext(data);
        AfterNode = removeSpecific(data);
        if(head==NULL){
            cout<<"Empty List!!!";
            return;
        }
        Node * AfterHead = head;
        while(AfterHead->data!=dataa){
            AfterHead = AfterHead->next;
        }
        if(AfterHead == tail){ // DONE
            tail->next = AfterNode;
            tail = AfterNode;
            return;
        }

        AfterNode->next = AfterHead->next;
        AfterNode->next->prev = AfterNode;
        AfterNode->prev = AfterHead->next;
        AfterHead->next = AfterNode;
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
        if(current == head){
            head->prev = BeforeNode;
            BeforeNode->next = head;
            head = BeforeNode; // NOT BeforeNode = head
            return;
        }
        BeforeNode->prev = current->prev;
        BeforeNode->next = current->prev->next;
        BeforeNode->prev->next = BeforeNode;
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

    Node* getNodebyIndex(int index){ // 5,10,20 (012) index = 2 --> get 20
        Node * loopNodee = head;
        int c=0;
        while(loopNodee!=NULL){
            //cout<<loopNodee->data<<" ";
            if(c==index){
                //cout<<"here\n";
                //cout<<loopNodee->data;
                //int x = loopNodee->data;
                //cout<<"Data in index "<<c<<": ";
                return loopNodee;
            }
            loopNodee = loopNodee->next;
            c++;
        }
        //cout<<"INDEX NOT FOUND ";
        return 0;
    }
    void display(){
        Node * loopNode = head;
        while(loopNode!=NULL){
            cout<<loopNode->data<<" ";
            loopNode = loopNode->next;
        }
    }

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    LinkedList BubbleSortData(){
        int NumofIterations = 0;
        int sorted = 0; // unsorted
        Node * current = head;
        //while(current!=NULL){
            //current = current->next;
            for(int outer=0; sorted==0; outer++){
                sorted = 1;
                current=head;
                for(int i=0; i<counter-1-outer; i++){
                    if((current->data)>current->next->data){
                        swap(current->data, current->next->data);
                        //current = current->next;
                        sorted = 0;
                        }

                    current = current->next;
                    NumofIterations++;
                    }
                    //cout<<"ff";
                    //current = current->next;
                    //current = current->next;
                }
        //}
        this->display();
        cout<<endl<<"Num of Iterations: "<<NumofIterations<<endl;
    }

    LinkedList BubbleSortNode(){
            int NumofIterations = 0;
            int sorted = 0; // unsorted
            Node * current = head;
            //while(current!=NULL){
                //current = current->next;
                for(int outer=0; sorted==0; outer++){
                    sorted = 1;
                    current=head;
                    for(int i=0; i<counter-1-outer; i++){
                        if((current->data)>current->next->data){
                            //cout<<"hi";
                            int putData = getNextData(current->data);
                            int insertedDataa = removeSpecificNext(current->data);
                            insertAfterSpecificData(putData, insertedDataa);
                            sorted = 0;
                            }

                        current = current->next;
                        NumofIterations++;
                        }
                        //cout<<"ff";
                        //current = current->next;
                        //current = current->next;
                    }
            //}
            this->display();
            cout<<endl<<"Num of Iterations: "<<NumofIterations<<endl;
        }

        /*LinkedList BubbleSortNode(){
            int NumofIterations = 0;
            int sorted = 0; // unsorted
            Node * current = head;
            //while(current!=NULL){
                //current = current->next;
                for(int outer=0; sorted==0; outer++){
                    sorted = 1;
                    current=head;
                    for(int i=0; i<counter-1-outer; i++){
                        if((current->data)>current->next->data){
                            cout<<"hi";
                            int nextData = removeSpecificNext(current->data);
                            //int nextData = current->next->data;
                            Node* nextNode = removeSpecific(current->data);
                            insertAfterSpecific(nextData, nextNode);
                            //insertAfterSpecific(current->data, nextNode);
                            sorted = 0;
                            }

                        current = current->next;
                        NumofIterations++;
                        }
                        //cout<<"ff";
                        //current = current->next;
                        //current = current->next;
                    }
            //}
            this->display();
            cout<<endl<<"Num of Iterations: "<<NumofIterations<<endl;
        }*/
};



int main(){
    LinkedList l;

    l.addNode(100);
    l.addNode(40);
    l.addNode(110);
    l.addNode(30);
    l.addNode(10); // 10 30 40 100 110

    //l.display();
    //cout<<endl;
    //cout<<"count before removing: "<<l.getCount()<<endl;
    //l.remove(5);
    //l.remove(20);
    //l.remove(6);
    //cout<<endl;
    //l.display();
    //cout<<endl;
    //cout<<"count after removing: "<<l.getCount()<<endl;

    /*l.insertAfter(100,7);
    l.display();*/

    //l.insertBefore(100,7);
    //l.display();
    //cout<<l.getDatabyIndex(3);

    //int arr[]={10,20,30,40,50,60};
    //cout<<"Index: ";

    //cout<<"Index: "<<d<<endl;
    //cout<<"no. of occurunces => ";
    //l.display();

    /*l.BubbleSortData();
    cout<<endl;*/

    l.BubbleSortNode();
    cout<<endl;

    return 0;
}

