#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hashtable{
	int size;
	int capacity;
	vector <int> h;
	public:
	Hashtable(int max_size){this->size = max_size; h = vector <int> (size, -1);}
	void insert(int key, int value);
	int hash_function(int key);
	int del(int key);
	bool isempty();
	int lookup(int key){return h[hash_function(key)];}
	void display(){for(int x:h){cout<<x<<" ";} cout<<endl;}
	};
	
void Hashtable ::insert(int key, int value){try{if(capacity == size){throw "overflow";} int index = hash_function(key); h[index] = value;}catch(const char *e){cout<<"hash table is full";}}
int Hashtable ::hash_function(int key){return key%10;}
int Hashtable ::del(int key){int index = hash_function(key); try{if(h[index] == -1){throw "empty";} else return h[index];}catch(const char *e){cout<<"hash table is empty";}}
bool Hashtable ::isempty(){if(capacity==0){return true;} else return false;}

int main(){
	Hashtable *p = new Hashtable(10);
	p->insert(4, 3);
	p->insert(5, 4);
	p->insert(13, 412);
	p->insert(22, 18);
	p->insert(48, 30);	
	p->insert(127, 6);
	p->display();
	p->del(127);
	p->display();
	p->lookup(13);
	return 0;
	}
