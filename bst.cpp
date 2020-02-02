#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
	};
	
class bst{
	public:
	int load_factor = 0;
	Node* root = NULL;
	Node* temp = root;
	
	void insert(int value){if(load_factor == 0){ Node* p = new Node(); p->data = value; load_factor++; this->root = p; temp = root;} else
		{Node* p = new Node(); p->data = value; load_factor++;
			while(temp->left && temp->right){
			if(value <= temp->data){temp = temp->left;} 
			else if(value >= temp->data)
			{temp = temp->right;}		
			}
			if(value <= temp->data){temp->left = p;} else temp->right = p; 
			}
			temp = root;
			}
	//NLR
	void preorder(Node* temp){
		if(temp){
			cout<<temp->data<<" "; 
			preorder(temp->left); 
			preorder(temp->right);}
	}
	//LNR
	void inorder(Node* temp){
		if(temp){
			inorder(temp->left); 
			cout<<temp->data<<" "; 	
			inorder(temp->right);}
	}	
	//LRN
	void postorder(Node* temp){
		if(temp){ 
			postorder(temp->left); 
			postorder(temp->right);
			cout<<temp->data<<" ";
			}
	}	
	Node* min(Node* temp){while(temp->left){temp = temp->left;} return temp;} //minimum at temp->left
	Node* max(Node* temp){while(temp->right){temp = temp->right;} return temp;} //maximum at temp->right
	
	Node* del(Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = del(root->left,data);
	else if (data > root->data) root->right = del(root->right,data);
	else {
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else { 
			Node *temp = min(root->right);
			root->data = temp->data;
			root->right = del(root->right,temp->data);
		}
	}
	return root;
}
	};

int main(){
	bst* p = new bst();
	p->insert(7);
	p->insert(5);
	p->insert(9);
	p->insert(3);
	p->insert(6);
	p->insert(8);
	p->insert(10);
	p->insert(2);	
	p->insert(4);
	p->preorder(p->root);
	cout<<endl;
	p->del(p->root, 3);
	cout<<endl;
	p->preorder(p->root);
	cout<<endl;
	return 0;
	}
