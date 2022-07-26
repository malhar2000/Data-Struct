#include "Node.hpp"
using namespace std;
#define COUNT 10
class Tree{
    public:
        Node* root;
        Tree(){root = NULL;}
        void CreateTree();
        void Preorder(Node *p);
        void Postorder(Node *p);
        void Inorder(Node *p);
        void Levelorder(Node *p);
        int Height(Node *root);
        void Display(Node *p, int space);
};

void Tree::CreateTree(){
    queue<Node*> nodes;
    Node *p, *temp;
    int x;

    cout << "Enter the value of the root node: ";
    cin >> x;

    root = new Node(x);
    nodes.push(root);

    while(!nodes.empty()) {
        p = nodes.front();
        nodes.pop();
        cout << "Enter the value of the left node of node value " << p->data << ": ";
        cin >> x;
        if(x != -1){
            temp = new Node(x);
            p->left = temp;
            nodes.push(temp);
        }
        cout << "Enter the value of the right node of node value " << p->data << ": ";
        cin >> x;
        if(x != -1){
            temp = new Node(x);
            p->right = temp;
            nodes.push(temp);
        }
         
    }

}

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data << " ";
        Preorder(p->left);
        Preorder(p->right);
    }
     
}

void Tree::Postorder(Node *p){
    if(p){
        
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }
    
}
void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
     
}
void Tree::Levelorder(Node *p){
    queue<Node*> nodes;
    cout << p->data << " ";
    nodes.push(p);

    while(!nodes.empty()){
        Node *temp = nodes.front();
        nodes.pop();
        if(temp->left){
            cout << temp->left->data << " ";
            nodes.push(temp->left);
        }
        if(temp->right){
            cout << temp->right->data << " ";
            nodes.push(temp->right);
        }
    }
}

int Tree::Height(Node *p){
    int x=0, y=0;
    if(p == 0)
        return 0;
    
    x=Height(p->left);
    y=Height(p->right);
    if(x>y){
        return x+1;
    }else{
        return y+1;
    }


}


//https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void Tree::Display(Node *root, int space){
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    Display(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
 
    // Process left child
    Display(root->left, space);
}

int main(){
    
    Tree t;

    t.CreateTree();
    t.Preorder(t.root);
    cout << endl;
    t.Postorder(t.root);
    cout << endl;
    t.Inorder(t.root);
    cout << endl;
    cout<< t.Height(t.root) << endl;
    t.Levelorder(t.root);
}