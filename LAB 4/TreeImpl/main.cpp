#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int _data){
        data = _data;
        left=right=NULL;
    }
};

class Tree{
    private:
    Node * root;
    Node * getNodeByData(int data){
        Node * current = root;
        while(current != NULL){
            if(data == current->data){
                //cout<<"Data found successfully !!"<<endl;
                return current;
            }
            else if(data > current->data){
                //cout<<"Data > Current";
                current = current->right;
            }
            else if(data < current->data){
                //cout<<"Data < Current";
                current = current->left;
            }
        }
        //cout<<"Data NOT found !!"<<endl;
        return NULL;
    }

    Node * getParent(Node * node){
        if(node == root){
            /*cout<<"data is the root & the root is NOT a parent!!"<<endl;
            return NULL;*/
            throw "data is the root, so it's NOT a parent!"; // 2 return NULLs, fa throw an exception
        }
        Node * parent = root;
        while(parent != NULL){
            // CASE: data = root ----> root is NOT a parent
            if(node == parent->left || node == parent->right){ // comparing addresses (ptr w/ a ptr)
                 //cout<<"parent node is here!!"<<endl;
                 return parent;
            }
            else if(node->data > parent->data){ // comparing data NOT addressess
                //cout<<"parent > "<<endl;
                parent = parent->right;
            }
            else if(node->data <= parent->data){
                //cout<<"parent <= "<<endl;
                parent = parent->left;
            }
            /*else{
                throws "data is unavailable";
            }*/
        }
        //cout<<"Data NOT found!!!!!!"<<endl;
        return NULL;
    }

    Node * getMaxRight(Node* maxNodeR){
        Node * currentMax = root;
        while(maxNodeR != NULL){
            currentMax = maxNodeR;
            maxNodeR = maxNodeR->right;
        }
        return currentMax;
    }

    Node * getMaxLeft(Node* maxNodeL){
        Node * currentMaxL = root;
        while(maxNodeL != NULL){
            currentMaxL = maxNodeL;
            maxNodeL = maxNodeL->left;
        }
        return currentMaxL;
    }

    void RemoveNode(int data){
        Node * removeNode = getNodeByData(data);
        if(removeNode == NULL){
            throw "Node is unavailable";
        }
        if(removeNode == root){
            if(root->left == NULL && root->right == NULL){
                root = NULL;
            }
            else if(root->left == NULL){
                root = root->right;
            }
            else if(root->right == NULL){
                root = root->left;
            }
            else{
                Node * newRoot = root->left;
                Node * getMaxRR = getMaxRight(newRoot);
                getMaxRR->right = root->right;
                root = newRoot;
            }
        }
        else{ // if it's NOT a root
            Node * parentt = getParent(removeNode);
            if(removeNode->left == NULL && removeNode->right == NULL){
                if(parentt->right == removeNode){
                    parentt->right = NULL;
                }
                else{
                    parentt->left = NULL;
                }
            }
            else if(removeNode->left == NULL){
                 if(parentt->right == removeNode){
                    parentt->right = removeNode->right;
                }
                else{
                    parentt->left = removeNode->right;
                }
            }
            else if(removeNode->right == NULL){
                if(parentt->right == removeNode){
                    parentt->right = removeNode->left;
                }
                else{
                    parentt->left = removeNode->left;
                }
            }
            else{
                Node * ParentNew = removeNode->left;
                Node * getMaxRRR = getMaxRight(ParentNew);
                getMaxRR->right = removeNode->right;
                root = ParentNew;

                if(parentt->right==node){
                    parentt->right = ParentNew;
                }
                else{
                    parentt->left = ParentNew;
                }
            }


        }
        delete removeNode;

    }

    public:
    Tree(){
        root = NULL;
    }
    void addNode(int data){
        Node * newNode = new Node(data);
        // CASE 1: empty tree //
        if(root == NULL){ //
            root = newNode;
            return;
        }
        Node * current = root;
        Node * parent = root;
        while(current != NULL){
            parent = current;
            // CASE 2: data > current->data //
            if(data > current->data){
                current=current->right;
                /*if(current == NULL){
                    parent->right = newNode;
                }*/
            }
            // CASE 2: data < current->data //
            else if(data < current->data){
                current=current->left;
                /*if(current == NULL){
                    parent->left = newNode;
                }*/
            }
        }
        if(data>parent->data){
            parent->right=newNode;
        }
        if(data<parent->data){
            parent->left=newNode;
        }
    }

    int findData(int data){ // public function to use helper (private) function getNodeByData
        Node * findDataNode = getNodeByData(data);
        if(findDataNode == NULL){
            return 0;
        }
        return findDataNode->data;
    }

    int getParentByData(int data){
        Node * ParentNode = getNodeByData(data);
        Node * ParentData = getParent(ParentNode);
        if(ParentNode != NULL){ // data is unavailable
            if(ParentData != NULL){
                //cout<<"Data unavailable";
                //return 0;
                cout<<"Parent found => ";
                return ParentData->data;
            }
        }
        return 0;
    }

    int getMaxRightByData(int data){
        Node * Nodeee = getNodeByData(data);
        if(Nodeee == NULL){
            cout<<"Node is unavailable"<<endl;
            return 0;
        }
        Node * MaxNodeR = getMaxRight(Nodeee);
        return MaxNodeR->data;
    }

    int getMaxLeftByData(int data){
        Node * NodeL = getNodeByData(data);
        if(NodeL == NULL){
            cout<<"Node is unavailable"<<endl;
            return 0;
        }
        Node * MaxNodeL = getMaxLeft(NodeL);
        return MaxNodeL->data;
    }
};

int main()
{
    Tree t;
    t.addNode(50);
    t.addNode(40);
    t.addNode(70);
    t.addNode(80);
    //t.addNode(60);
    t.addNode(30);
    t.addNode(35);

    /*int d = t.findData(50);
    int c = t.findData(10);
    d==0?cout<<"Data NOT found!!"<<endl:cout<<"Data found successfully!!"<<endl;*/

    /*Node * rightt = root->right;
    t.getParent(t.root->right->right);*/

    try{
        int p = t.getParentByData(35);
        cout<<p<<endl;
    }
    catch(const char* msg){
    //p==0?cout<<"Parent NOT found!!"<<endl:cout<<"Parent found successfully!!"<<endl;
        cout<<msg<<endl;
    }

    int r = t.getMaxRightByData(30);
    cout<<"Max Right => "<<r<<endl;

    int l = t.getMaxLeftByData(40);
    cout<<"Max Left => "<<l<<endl;
    return 0;
}
