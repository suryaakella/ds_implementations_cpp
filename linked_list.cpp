#include <iostream>
#include <list>
using namespace std;

class Node{
	public:
	int data;
	Node* next = NULL;
	};

class LL{
	public:
	Node* head = NULL;
	int load_factor = 0;
	Node* temp = head;
	void insert(int value){if(load_factor == 0){Node* p = new Node(); p->data = value; this->head = p; temp = head; load_factor++;} else {Node *p = new Node(); 
		p->data = value;
		while(temp->next!=NULL){temp = temp->next;}
		temp->next = p;
		temp = head;
		load_factor++;
		}
		}
	void del(int value){while(temp->next->data != value){temp = temp->next;} temp->next = temp->next->next; 		
		temp = head;
		load_factor--;}
	void display(){while(temp!=NULL){cout<<temp->data<<" "; temp = temp->next;} cout<<endl; temp = head;}
	
	};

int main(){
	LL* ptr = new LL();
	ptr->insert(1);
	ptr->insert(2);
	ptr->insert(3);
	ptr->display();
	ptr->del(3);
	ptr->display();	
	return 0;
	}
