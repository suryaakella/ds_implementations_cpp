#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <vector>
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
	
	void iterativepreorder(Node* temp){
		stack <Node*> s;
		Node* temp2 = temp;
		while(!s.empty() || temp2){
			if(temp2){
				cout<<temp2->data<<" ";
				s.push(temp2);
				temp2 = temp2->left;
				}
			else{	temp2 = s.top();
					s.pop();
					temp2 = temp2->right;
				}
			}
		}
	void iterativeinorder(Node* temp){
		stack <Node*> s;
		Node* temp2 = temp;
		while(!s.empty() || temp2){
			if(temp2){
				s.push(temp2);
				temp2 = temp2->left;
				}
			else{			
					temp2 = s.top();
					s.pop();
					cout<<temp2->data<<" ";
					temp2 = temp2->right;
				}
			}
		}

	void iterativepostorder(Node* temp){
		stack <Node*> s;
		stack <int> s2;
		Node* temp2 = temp;
		while(!s.empty() || temp2){
			if(temp2){
				cout<<temp2->data<<" ";
				s.push(temp2);
				s2.push(temp2->data);
				temp2 = temp2->right;
				}
			else{	temp2 = s.top();
					s.pop();
					temp2 = temp2->left;
				}
			}
			cout<<endl;
		while(!s2.empty()){cout<<s2.top()<<" "; s2.pop();}
		}

	int totaldepth(Node* temp){
		if(!temp) return 0;
		
		return (1+std::max(totaldepth(temp->left),totaldepth(temp->right))); 
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
	
	vector<vector<int>> levelorder(Node* temp){
		queue <Node*> q;
		int count;
		vector<vector<int>> result;
		int total_depth = totaldepth(temp);
		vector<int> *vec;
		int level_count = 0;
		vec = new vector <int> [total_depth+1];
		q.push(temp);
		while(!q.empty()){
			count = q.size();
			level_count++;
			while(count>0){
				temp = q.front();
				cout<<temp->data<<" ";
				vec[level_count].push_back(temp->data);
				q.pop();
				if(temp->left) {q.push(temp->left); }
				if(temp->right) {q.push(temp->right);}
				count--;
				}
				cout<<endl;
				}
		//for(int i = 1 ; i <=total_depth; i++){ for(auto it:vec[i]) cout<<it<<" "; cout<<endl;}		
		for(int i = 1 ; i<=total_depth; i++){ result.push_back(vec[i]); }
		//cout<<result[0][0]<<"-----";
		return result;
	}
	
	void leftview(Node* temp){
		vector<vector<int>> result = levelorder(temp);
		int total_depth = totaldepth(temp);
		for(int i = 0; i < total_depth; i++){cout<<result[i][0]<<" ";}
		cout<<endl;
		}

	void rightview(Node* temp){
		vector<vector<int>> result = levelorder(temp);
		int total_depth = totaldepth(temp);
		for(int i = 0; i < total_depth; i++){cout<<result[i].back()<<" ";}
		cout<<endl;
		}
		
	unordered_map <int, vector<int>> u;
	int min_negative_for_vertical_order=0, max_positive_for_vertical_order=0;
	void preorderforverticalorder(Node* temp, int len){
		if(temp){
			u[len].push_back(temp->data); 
			if(min_negative_for_vertical_order > len) min_negative_for_vertical_order = len;
			if(max_positive_for_vertical_order < len) max_positive_for_vertical_order = len;			
			preorderforverticalorder(temp->left, len-1);
			preorderforverticalorder(temp->right, len+1);
			}
		}
				
	void verticalorder(Node* temp){
		u.clear();
		preorderforverticalorder(temp, 0);
	//	cout<<min_negative_for_vertical_order<<"-----"<<max_positive_for_vertical_order<<endl;
		for(int i = min_negative_for_vertical_order; i<= max_positive_for_vertical_order; i++){
			for(auto it:u[i]) cout<<it<<" "; 
			cout<<endl;
			}
		u.clear();
		}
		
	void topview(Node* temp){
		u.clear();
		preorderforverticalorder(temp, 0);
	//	cout<<min_negative_for_vertical_order<<"-----"<<max_positive_for_vertical_order<<endl;
		for(int i = min_negative_for_vertical_order; i<= max_positive_for_vertical_order; i++){
			cout<<u[i][0]<<" "; 
			}
		u.clear();
		}
		
	void bottomview(Node* temp){
		u.clear();
		preorderforverticalorder(temp, 0);
	//	cout<<min_negative_for_vertical_order<<"-----"<<max_positive_for_vertical_order<<endl;
		for(int i = min_negative_for_vertical_order; i<= max_positive_for_vertical_order; i++){
			cout<<u[i].back()<<" "; 
			}
		u.clear();	
		}
			
	void preorderfordiagonalorder(Node* temp, int len){
		if(temp){
		 	u[len].push_back(temp->data); 
		 	if(min_negative_for_vertical_order > len) min_negative_for_vertical_order = len;
			if(max_positive_for_vertical_order < len) max_positive_for_vertical_order = len;	
			preorderfordiagonalorder(temp->left, len+1);
			preorderfordiagonalorder(temp->right, len);
			}
		}
			
	void diagonaltraversal(Node* temp){
		u.clear();
		preorderfordiagonalorder(temp, 0);
		for(int i = 0; i<= max_positive_for_vertical_order; i++){
			for(auto it:u[i]) cout<<it<<" "; 
			cout<<endl;
			}
		u.clear();
		}
	void leftviewwithoutleaf(Node* temp){
		while(temp->left){cout<<temp->data<<" "; temp = temp->left;}
		}
	void printleafnodes(Node* temp){if(temp->left == NULL && temp->right == NULL) cout<<temp->data<<" ";
		else{
			printleafnodes(temp->left);
			printleafnodes(temp->right);
			}
		}
	void rightviewwithoutleaf(Node* temp){
		stack <int> s;
		while(temp->right){s.push(temp->data); temp = temp->right;}
		while(!s.empty()){if(s.size() == 1) break; else cout<<s.top()<<" "; s.pop();}
		}
		
	void boundarytraversal(Node* temp){
		leftviewwithoutleaf(temp);
		printleafnodes(temp);
		rightviewwithoutleaf(temp);
		}
	void bsttomirrortree(Node* temp){
		if(temp){
			bsttomirrortree(temp->left);
			bsttomirrortree(temp->right);
			swap(temp->left, temp->right);
			}
		}
		
	void spiralorder(Node* temp){
		stack <Node*> s1,s2; 
		s1.push(temp);
		while(!s1.empty() || !s2.empty()){
			while(!s1.empty()){
				temp = s1.top();
				cout<<temp->data<<" ";
				s1.pop();
				if(temp->left) s2.push(temp->left);
				if(temp->right) s2.push(temp->right);			
				}
				
			while(!s2.empty()){
				temp = s2.top();
				cout<<temp->data<<" ";
				s2.pop();
				if(temp->right) s1.push(temp->right);							
				if(temp->left) s1.push(temp->left);				
				}
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
			root = NULL; //chill scene
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
//	p->preorder(p->root);
	cout<<endl;
//	p->del(p->root, 3);
	cout<<endl;
//	p->postorder(p->root);
	cout<<endl;
//	p->iterativepostorder(p->root);
	cout<<endl;
	//p->levelorder(p->root);
	cout<<endl;
//	cout<<p->totaldepth(p->root);
	cout<<endl;
//	p->levelorder(p->root);
	cout<<endl;
//	p->leftview(p->root);
	cout<<endl;
//	p->rightview(p->root);
//	p->verticalorder(p->root);
//	cout<<endl;
//	p->topview(p->root);
//	cout<<endl;
//	p->bottomview(p->root);
//	p->diagonaltraversal(p->root);
//	cout<<endl;
//	p->boundarytraversal(p->root);
//	cout<<endl;
//	p->bsttomirrortree(p->root);
//	cout<<endl;
//	p->preorder(p->root);
//	cout<<endl;
//	p->spiralorder(p->root);
//	cout<<endl;
	return 0;
	}
