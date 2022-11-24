// Reverse Singly Linked List
#include <iostream>
using namespace std;

// node
class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// node prev_node, insert a new
void insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

// appends a new node at the end
void append(Node **head_ref, int new_data)
{

    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;

    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

void reverseList(Node *node){
    Node *current=node;
    Node *prev=NULL, *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    node=prev;
    cout<<"\nThe Reversed List is: ";
    printList(node);   
}
int main()
{

    Node *head = NULL;

    append(&head, 6);

    push(&head, 7);

    push(&head, 1);

    append(&head, 4);

    insertAfter(head->next, 8);

    cout << "Created Linked list is: ";
    printList(head);
    reverseList(head);

    return 0;
}
