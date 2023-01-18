#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    
    //backtrack condiiton
    if(data == -1){
        return NULL;
    }

    //build left tree
    cout<<"Enter data for left of Node"<<data<<endl;
    root->left = buildTree(root->left);                 //recursive part

    //build right tree
    cout<<"Enter data for right of Node"<<data<<endl;
    root->right = buildTree(root->right);
}

//BFS using queue
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        //Print new line after every level
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        //Pushing the child nodes if available
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Level order traversal: "<<endl;
    levelOrderTraversal(root);
    return 0;
}