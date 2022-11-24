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

void details(Node* root, int level)
{   
	if (root == NULL)
		return;
	int max=0;
	int lstep=0;
	bool lflag=true;
	cout<<"---------------------------------------------------------";
	cout<<"\nNodes at level "<<level<<" are: ";
	stack<Node*> nodeStack;
	nodeStack.push(root);
	while (nodeStack.empty() == false) {
		Node* node = nodeStack.top();
		if (((node->right)==NULL && (node->left)==NULL)){
			if (max<=lstep){
			max=lstep;
		}
		lstep--;
		};
        nodeStack.pop();
		if ((node->left) && (node->right)){
			lstep++;
			if (lstep==level && lflag){
			cout<<node->left->data<<" ";
			cout<<node->right->data<<" ";
			lflag=false;
			}
			nodeStack.push(node->right);
			nodeStack.push(node->left);
		}
		else if(node->right){
			if (lstep==level && lflag){
			lflag=false;
			cout<<node->right->data<<" ";
			}
			lstep++;
			nodeStack.push(node->right);
		}
		else if(node->left){
			if (lstep==level && lflag){
			lflag=false;
			cout<<node->left->data<<" ";
			}
			lstep++;
			nodeStack.push(node->left);
		}
	}

	bool rflag=true;
	nodeStack.push(root);
	int rstep=0;
	while (nodeStack.empty() == false) {
		Node* node = nodeStack.top();
		if (((node->right)==NULL && (node->left)==NULL)){
			if (max<=rstep){
			max=rstep;
		}
		rstep--;
		};
        nodeStack.pop();
		if ((node->left) && (node->right)){
			rstep++;
			if (rstep==level && rflag){
			cout<<node->left->data<<" ";
			cout<<node->right->data<<" ";
			rflag=false;
			}
			nodeStack.push(node->left);
			nodeStack.push(node->right);
		}
		else if(node->left){
			if (rstep==level && rflag){
			rflag=false;
			cout<<node->left->data<<" ";
			}
			rstep++;
			nodeStack.push(node->left);
		}
		else if(node->right){
			if (rstep==level && rflag){
			rflag=false;
			cout<<node->right->data<<" ";
			}
			rstep++;
			nodeStack.push(node->right);
		}
	}
	cout<<"\n\nHeight of tree is: "<<max<<"\n";

	nodeStack.push(root);
	cout<<"\nLeaf Nodes are: ";
	int count=0;
	while (nodeStack.empty() == false) {
		Node* node = nodeStack.top();
		if (((node->right)==NULL && (node->left)==NULL)){
			cout<<node->data<<" ";
			count++;
		};
        nodeStack.pop();
		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
	cout<<"\nNumber of Leaf Nodes are: "<<count;
	cout<<"\n---------------------------------------------------------";
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->right = newNode(11);
	root->left->left->left = newNode(6);
	root->left->left->left->right = newNode(10);
	root->left->left->left->left = newNode(8);
	root->right = newNode(3);
	root->right->left = newNode(7);
	root->right->left->right=newNode(9);
	root->right->left->right->left=newNode(14);
	root->right->left->right->right=newNode(13);
	root->right->left->right->right->right=newNode(15);
	//Tree is: 	
	// 				 1			
	// 				/ \		
	// 			   2   3		
	// 			  / \  /		
	// 			 4	 5 7		
	// 		    / \	    \		
	// 		   6   11	 9		
	// 		  / \	    / \		
	// 		 8	 10	   14  13	
	// 						 \	
	// 						  15
    details(root,4);
	return 0;
}
