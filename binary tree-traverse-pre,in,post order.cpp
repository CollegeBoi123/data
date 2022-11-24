#include<iostream>
#include <stack>

using namespace std;

class Node{
    public:
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void Preorder(Node* root)
{
	if (root == NULL)
		return;

	stack<Node*> nodeStack;
	nodeStack.push(root);

	while (nodeStack.empty() == false) {
		Node* node = nodeStack.top();
		cout<<node->data<<" ";
		nodeStack.pop();

		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
}

void Inorder(Node* root)
{
	stack<Node *> nodeStack;
    Node *curr = root;
  
    while (curr != NULL || nodeStack.empty() == false)
    {
        while (curr !=  NULL)
        {
            nodeStack.push(curr);
            curr = curr->left;
        }
        curr = nodeStack.top();
        nodeStack.pop();
        cout << curr->data << " ";
		curr = curr->right;
    }
}

void Postorder(Node* root){
	if (root == NULL) {
        return;
    } 
    stack<Node*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty())
    {
        Node* curr = nodeStack.top();
        nodeStack.pop();
 
        cout<<curr->data<<" ";
 
        if (curr->left) {
            nodeStack.push(curr->left);
        }
 
        if (curr->right) {
            nodeStack.push(curr->right);
        }
    }
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	//Tree is: 	
	// 				 1			
	// 				/ \		
	// 			   2	3		
	// 			  / \  		
	// 			 4	 5 
	cout<<"---------------------------------------------------------";
	cout<<"\nPreOrder Traversal is: ";
	Preorder(root);
	cout<<"\nInOrder Traversal is: ";
	Inorder(root);
	cout<<"\nPostOrder Traversal is: ";
	Postorder(root);
	cout<<"\n---------------------------------------------------------";
	return 0;
}
