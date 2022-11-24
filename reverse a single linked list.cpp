
#include <iostream>
using namespace std;

// node
class Node
{
public:
    int data;
    Node *next;
};

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

// void addint(Node *node1, Node *node2, Node *new_node){
//     Node *node=new_node;
//     Node *carry_node=new Node();
//     carry_node->data=0;
//     while(node1 && node2){
//         int temp=node1->data+node2->data+carry_node->data;
//         new_node->data=temp%10;
//         temp=temp/10;
//         if(temp>0){
//             carry_node->data=temp;
//             new_node->next=carry_node;
//         }
//         else{
//             new_node->next
//             = (class Node*)malloc(sizeof(Node));
//         new_node = new_node->next;
//         new_node->next = NULL;
//         }
//         node1=node1->next;
//         node2=node2->next;
//     }

//     cout<<"\nNumber after adding is: ";
//     while (node->next)
//     {
//         cout << " " << node->data;
//         node = node->next;
//     }
// }

// to add two new numbers
Node* addTwoNumList(Node* l1, Node* l2) {
    stack<int> s1,s2;
    while(l1!=NULL){
        s1.push(l1->data);
        l1=l1->next;
    }
    while(l2!=NULL){
        s2.push(l2->data);
        l2=l2->next;
    }
    int carry=0;
    Node* result=NULL;
    while(s1.empty()==false || s2.empty()==false){
        int a=0,b=0;
        if(s1.empty()==false){
            a=s1.top();s1.pop();
        }
        if(s2.empty()==false){
            b=s2.top();s2.pop();
        }
        int total=a+b+carry;
        Node* temp=new Node();
        temp->data=total%10;
        carry=total/10;
        if(result==NULL){
            result=temp;
        }else{
            temp->next=result;
            result=temp;
        }
    }
    if(carry!=0){
        Node* temp=new Node();
        temp->data=carry;
        temp->next=result;
        result=temp;
    }
    return result;
}
 
int main(){
    Node *node1=NULL;
    append(&node1,2);
    append(&node1,2);
    append(&node1,2);

    Node *node2=NULL;
    append(&node2,9);
    append(&node2,9);
    append(&node2,9);

    cout<<"First Number is: ";
    printList(node1);
    cout<<"\nSecond Number is: ";
    printList(node2);

    Node *new_node=new Node();
    addint(node1,node2,new_node);
}