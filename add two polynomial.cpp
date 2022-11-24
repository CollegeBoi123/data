// Program to add two polynomials
#include<iostream>
using namespace std;

class Node{
    public:
    int coeff;
    int pow;
    Node *next;
};

// appends a new node at the end
void append(Node **head_ref, int new_coeff, int new_pow)
{

    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->coeff = new_coeff;
    new_node->pow= new_pow;
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

void polyadd(Node* poly1,Node* poly2,Node* poly)
{
    Node *node=poly;
    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
 
        else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
 
        else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
 
        poly->next
            = (class Node*)malloc(sizeof(Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1 || poly2) {
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next
            = (class Node*)malloc(sizeof(Node));
        poly = poly->next;
        poly->next = NULL;
    }
    cout<<"\nFinal Polynomial after addition is: ";
    while (node->next)
    {
        cout << " " << node->coeff<<"x^"<<node->pow;
        node = node->next;
    } 
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->coeff<<"x^"<<node->pow;
        node = node->next;
    }
}

int main(){
    Node *polynomial1=NULL;
    append(&polynomial1,5,3);
    append(&polynomial1,4,2);
    append(&polynomial1,2,0);

    Node *polynomial2=NULL;
    append(&polynomial2,1,3);
    append(&polynomial2,2,1);
    append(&polynomial2,3,0);

    cout<<"First Polynomial is: ";
    printList(polynomial1);
    cout<<"\nSecond Polynomial is: ";
    printList(polynomial2);

    Node *final_poly=NULL;
    final_poly = (class Node*)malloc(sizeof(Node));
    polyadd(polynomial1,polynomial2,final_poly);
}