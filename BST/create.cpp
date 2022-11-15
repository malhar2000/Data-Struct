#include "Node.hpp"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree() : root(NULL) {}
    void Inorder(Node *p);
    void insertBST(int key);
    Node *searchBST(int key);
    Node *Delete(Node *p, int key);
    int height(Node *);
    Node *InorderPredccosor(Node *);
    Node *InorderSuccesor(Node *);
};

void Tree::insertBST(int key)
{
    Node *p, *temp = root;
    Node *pHolder;

    if (root == NULL)
    {

        p = new Node(key);
        root = p;
        return;
    }

    while (temp != NULL)
    {

        pHolder = temp;
        if (temp->data > key)
        {
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
        else
        {
            return;
        }
    }
    p = new Node(key);
    if (key < pHolder->data)
    {
        pHolder->left = p;
    }
    else
    {
        pHolder->right = p;
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

Node *Tree::searchBST(int key)
{
    Node *temp = root;

    while (temp != NULL)
    {

        if (temp->data == key)
        {
            return temp;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
        else if (temp->data > key)
        {
            temp = temp->left;
        }
    }
    return NULL;
}
int Tree::height(Node *node){
    int l,r;
    if(node == NULL){
        return 0;
    }
    l=height(node->left);
    r=height(node->right);
    return l>r?l+1:r+1;

}
Node * Tree::InorderPredccosor(Node *p){
    while(p && p->right != NULL){
        p = p->right;
    }
    return p;
}

Node * Tree::InorderSuccesor(Node *p){
    while(p && p->left != NULL){
        p = p->left;
    }
    return p;
}
Node *Tree::Delete(Node *p, int key)
{
    if(p == NULL){
        return NULL;
    }
    if(p->left == NULL && p->right == NULL){
        if(p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(key < p->data){
        p =  Delete(p->left, key);
    }else if(key > p->data){
        p = Delete(p->right, key);
    }else{
        if(height(p->left) > height(p->right)){
            Node *temp = InorderPredccosor(p->left);
            p->data = temp->data;
            p->left = Delete(p->left, temp->data);
        }else{
            Node *temp = InorderSuccesor(p->right);
            p->data = temp->data;
            p->right = Delete(p->right, temp->data);
        }
    }

    return p;


}


int main()
{
    Tree t;
    t.insertBST(23);
    t.insertBST(4);
    t.insertBST(42);
    t.insertBST(14);
    t.insertBST(9);
    t.insertBST(100);

    t.Delete(t.root, 42);
    // cout << endl;
    // Node *p = t.searchBST(9);
    // cout << p->data << ": " << endl;
    t.Inorder(t.root);
}