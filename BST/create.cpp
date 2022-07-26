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

int main()
{
    Tree t;
    t.insertBST(23);
    t.insertBST(4);
    t.insertBST(42);
    t.insertBST(14);
    t.insertBST(9);
    t.insertBST(100);

    t.Inorder(t.root);

    cout << endl;
    Node *p = t.searchBST(9);
    cout << p->data << ": " << endl;
}