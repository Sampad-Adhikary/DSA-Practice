#include<iostream>
#include<vector>
using namespace std;
 
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    //CONSTRUCTOR
    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//LENGTH OF THE LINKED LIST
int getLength(Node* head){
    Node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    return count;
}

//INSERT AT HEAD
void insertAtHead(Node* &head,int n){
    if(head == NULL){
        Node* newnode = new Node(n);
        head = newnode;
    }
    else{
        Node* newnode = new Node(n);
        newnode->next = head;
        head->prev = newnode;
        // newnode->prev = NULL;
        head = newnode;
    }
    
}

//INSERT AT TAIL
void insertAtTail(Node* &tail,int data){
    if(tail == NULL){
       Node* temp = new Node(data);
       tail = temp; 
    }
    else{
        Node* temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
    }
}

//INSERT AT ANY POSITION
void insertPos(Node* head,int pos,int data){
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    Node* temp = new Node(data);
    Node* ptr1 = head;
    pos = pos-1;
    int count = 1;
    while(count<pos){
        ptr1 = ptr1->next;
        count+=1;
    }
    Node* ptr2 = ptr1->next;
    ptr1->next = temp;
    temp->prev = ptr1;
    ptr2->prev = temp;
    temp->next = ptr2;

}

//DELETION OF NODE
void deleteNode(Node* &head,Node* &tail,int pos){
    int len = getLength(head);
    if(pos == 1){
        Node* ptr = head;
        ptr = ptr->next;
        ptr->prev = NULL;
        head = ptr;
    }
    else if(pos == len){
        Node* ptr = tail;
        ptr = ptr->prev;
        ptr->next = NULL;
        tail = ptr;
    }
    else{
        int count = 1;
        Node* ptr = head;
        while(count<pos){
            ptr = ptr->next;
            count++;
        }
        Node* ptr2 = ptr->prev;
        Node* ptr3 = ptr->next;
        ptr2->next = ptr3;
        ptr3->prev = ptr2;
    }
}

int main(){
    Node* node1 = new Node(18);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtHead(head,11);

    print(head);
    insertAtHead(head,36);

    insertAtTail(tail,34);
    cout<<"After Insertion at tail!!"<<endl;
    print(head);

    insertPos(head,4,45);
    print(head);

    deleteNode(head,tail,2);
    print(head);

    return 0;
}