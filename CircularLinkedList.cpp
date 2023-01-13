#include<iostream>
#include<vector>
using namespace std;
 
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next !=NULL){
            delete next;
            next = NULL;
        }
    }
};

// INSERT NODE
void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
        
    }
    else{
        //non-empty list
        //Assuming that the element after which we have to add the given data is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}



//TRAVERSAL
void print(Node* tail){
    if(tail == NULL){
        cout<<"Empty List!!";
    }
    else{
        Node* temp = tail;
        cout<<tail->data<<" ";
        while(tail->next != temp){
            tail = tail->next;
            cout<<tail->data<<" ";

        }
    }
    
}

//DELETION
void deleteNode(Node* &tail,int element){
    if(tail == NULL){
        cout<<"Empty List!!";
    }
    else{
        Node* ptr = tail;
        Node* ptr2 = ptr->next;
        while(ptr2->data != element){
            ptr = ptr2;
            ptr2 = ptr2->next;
        }
        ptr->next = ptr2->next;
        if(ptr == ptr2){
            tail = NULL;
        }
        if(tail == ptr2){
            tail = ptr;
        }
        ptr2->next = NULL;
        delete ptr2;       
    }
}

int main(){
    Node* tail = NULL;
    insertNode(tail, 0, 3);
    insertNode(tail, 3, 2);
    insertNode(tail, 2, 4);
    print(tail);
    cout<<endl;
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,2);
    cout<<endl;
    print(tail);
    cout<<endl;
    deleteNode(tail, 4);
    print(tail);
    return 0;
} 