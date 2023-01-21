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

//L N R
void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

//N L R 
void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//L R N
void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void buildFromLvlOrder(Node* &root){
    queue<Node*> q;
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //Taking left node
        cout<<"Enter left Node for: "<<temp->data<<endl;
        int ldata;
        cin>>ldata;
        if(ldata != -1){
            temp->left = new Node(ldata);
            q.push(temp->left);
        }

        //Taking right node
        cout<<"Enter right Node for: "<<temp->data<<endl;
        int rdata;
        cin>>rdata;
        if(rdata != -1){
            temp->right = new Node(rdata);
            q.push(temp->right);
        }
    }
}

int main(){
    Node* root = NULL;
    // root = buildTree(root);
    
    buildFromLvlOrder(root);


    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout<<"Level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal: "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal: "<<endl;
    postOrderTraversal(root);
    cout<<endl;
    cout<<"Preorder Traversal: "<<endl;
    preOrderTraversal(root);
    return 0;
}