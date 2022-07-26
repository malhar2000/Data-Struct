#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insert(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

void insertAt(Node *&head, int data, int pos)
{
    Node *n = new Node(data);
    if (pos == 0)
    {
        n->next = head;
        head = n;
        return;
    }
    Node *temp = head;
    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    n->next = temp->next;

    temp->next = n;
}

Node *rreverse(Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *n = rreverse(head->next);

    head->next->next = head;
    head->next = NULL;
    return n;
}

void ireverse(Node *&head)
{
    Node *cur = head;
    Node *temp;
    Node *prev = NULL;

    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
}

// input 1->2->3->4->5->6->7->8->NULL
// output 3->2->1->6->5->4->8->7->NULL
Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    // reversing k-nodes
    int cnt = 1;
    Node *cur = head;
    Node *temp;
    Node *prev = NULL;

    while (cur != NULL and cnt <= k)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        cnt++;
    }

    // i.e 1->2->3->4->5->6->NULL
    /**
     * After reversing the first k=3 nodes we get 3->2->1 where 3 is prev and 1 is head
     * so we connect the head->next i.e 1 to the 2nd call reverse which will be 3->2->1->6->5->4->null
     * and we return the prev which is the head......
     */
    if (temp != NULL)
    {
        head->next = kReverse(temp, k);
    }

    return prev;
}

Node *mergeTwoSortedLLRecursive(Node *head1, Node *head2)
{
    Node *newLL;

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data < head2->data)
    {
        newLL = head1;
        newLL->next = mergeTwoSortedLLRecursive(head1->next, head2);
    }
    else
    {
        newLL = head2;
        newLL->next = mergeTwoSortedLLRecursive(head1, head2->next);
    }

    return newLL;
}

Node *mergeTwoSortedLLIterative(Node *head1, Node *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *temp;
    if (head1->data < head2->data)
    {
        temp = new Node(head1->data);
        head1 = head1->next;
    }
    else
    {
        temp = new Node(head2->data);
        head2 = head2->next;
    }
    Node *head = temp;

    while (head1 != NULL and head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            // we do temp->next and create a new node becoz
            // the previous temp's next was not assigned yet
            // same as creating new node and assigning to temp's next
            // but less line or code
            // i.e. Node * temp1 = new Node(head1->data)
            // temp->next = temp1;
            temp->next = new Node(head1->data);

            head1 = head1->next;
        }
        else
        {
            temp->next = new Node(head2->data);

            head2 = head2->next;
        }

        // we move to the new node that we created above
        temp = temp->next;
    }

    if (head1 == NULL && head2 != NULL)
    {
        temp->next = head2;
    }
    if (head1 != NULL && head2 == NULL)
    {
        temp->next = head1;
    }
    return head;
}

Node *midPoint(Node *head)
{
    // runner techine

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *mergeSort(Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    // get the middle of LL
    Node *midpoint = midPoint(head);

    Node *firstHalf = head;
    Node *lastHalf = midpoint->next;
    midpoint->next = NULL;

    firstHalf = mergeSort(firstHalf);
    lastHalf = mergeSort(lastHalf);

    return mergeTwoSortedLLIterative(firstHalf, lastHalf);
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << " " << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);
    // insertAt(head, 100, 2);
    head = rreverse(head);
    print(head);
    ireverse(head);
    print(head);
    head = kReverse(head, 3);
    print(head);
    insert(head1, 10);
    insert(head1, 7);
    insert(head1, 5);
    insert(head1, 1);

    insert(head2, 5);
    insert(head2, 3);
    insert(head2, 2);

    Node *temp = mergeTwoSortedLLIterative(head1, head2);
    cout << "********************************" << endl;
    print(temp);

    insert(head2, 64);
    insert(head2, 33);
    insert(head2, 22);
    head2 = mergeSort(head2);
    print(head2);

    head1 = mergeSort(head1);
    print(head1);
}