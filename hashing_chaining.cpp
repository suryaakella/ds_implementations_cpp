#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Hash{
	public:
	list <int> *L;
	int buckets;
	int load_factor = 0;
	Hash(int size){this->buckets = size; L = new list <int> [buckets];}
	int hash_function(int key){return key%10;}
	void insert(int key, int value){    int index = hash_function(key); 
    L[index].push_back(value);}
    void del(int key, int value){int index = hash_function(key); 
    L[index].remove(value);}
	void display(){for(int i =0 ;i < buckets ; i++){for(auto x:L[i]){ cout<<x<<" ";}cout<<endl;} } 
	
	};

int main(){
	Hash* ptr = new Hash(10);
	ptr->insert(12,9987);
	ptr->insert(15, 364);
	ptr->insert(22,187);
	ptr->insert(17, 22264);
	ptr->display();
	ptr->del(22,187);
	ptr->display();
	return 0;
	}
