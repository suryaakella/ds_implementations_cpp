#include <iostream>
#include <vector>

using namespace std;


//in practice we use a this version of queue called circular queue

class Queue{
	int size;
	int front = -1;
	int rear = -1;
	vector <int> q;
	void display(){for(int x:q){cout<<x<<" ";}} // if you want to see the contents of the queue then put this function in the public section
	int capacity=0;	
	public:
	Queue(int max_size){this->size = max_size; q = vector<int>(size, -1);}
	void push(int value);
	int pop();
	int front_();
	bool isempty();
	int rear_();
	
	};
	
void Queue ::push(int value){
	try{
		if(capacity == 0){front++;}
		if(capacity == size ) throw "overflow"; 
	 q[(++rear)%size]=value;
	 capacity++; 
	}catch(const char *e){
	cout<<"Queue is overflow"; 
	}	}
	
int Queue ::pop(){
	try{if(front == rear) throw "nothing to del";
	int x = q[front%size]; q[front]=-1;front++; capacity--; return x;}catch(
		const char *e){cout<<"empty queue";}
			}
int Queue ::front_(){return q[front%size];}
int Queue ::rear_(){return q[rear%size];}
bool Queue ::isempty(){if(front == rear){return true;} else return false;}

int main(){
	Queue *ptr = new Queue(10);
	//ptr->display();
	cout<<endl;
	ptr->push(1);
	ptr->push(2);
	ptr->push(3);
	ptr->push(4);
	ptr->push(5);
	ptr->push(6);
	ptr->push(7);
	ptr->push(8);
	ptr->push(9);
	ptr->push(10);	
	//ptr->display();
	cout<<endl;
	ptr->pop();	
	ptr->pop();
	ptr->pop();
	ptr->pop();
	ptr->pop();
	ptr->pop();
	//ptr->display();			
	cout<<endl;	
	ptr->push(11);
	ptr->push(12);
	ptr->push(13);
	ptr->push(14);
	//ptr->display();
	cout<<endl;
	cout<<ptr->front_()<<endl;
	cout<<ptr->rear_()<<endl;
	return 0;
	}
