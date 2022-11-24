#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    // Parameterised Constructor
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};



Node* buildtree()
{
    cout<<"Enter element "<<endl;
    int d;
    cin>>d;
    // object root of class Node is made 
    if(d==-1)
    {
        return NULL;
    }
    Node* root = new Node(d);
    //The new operator is an operator which denotes a request for memory allocation on the Heap. If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable.
    cout<<"Left for "<<d<<endl;
    root->left = buildtree();
    cout<<"Right for "<<d<<endl;
    root->right = buildtree();
    return root;
}


void preorder(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



void inorder(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    int ch;
    Node*root=buildtree();

    while(ch != 4)
    {
        cout<<"1. Traversal of tree preorder"<<endl;
        cout<<"2. Traversal of inorder"<<endl;
        cout<<"3. Traversal of post order"<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"Enter your Choice "<<endl,cin>>ch;
        switch(ch)
        {
            case 1:
            {
                preorder(root);
                break;
            }
            case 2:
            {
                inorder(root);
                break;
            }
            case 3:
            {
                postorder(root);
                break;
            }
            case 4:
            {
                cout<<"END....... !!!!";
                break;
            }
            default:
                cout<<"Invalid Choice";
                break;
        }
        cout<<"\n"<<endl;
        system("pause");
        system("cls"); 
    } 
    return 0;
}





