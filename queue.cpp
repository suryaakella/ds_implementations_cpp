#include <iostream>
#include <vector>

using namespace std;

//practically it is not used because it does not utilize space 
//in practice we use a different version of queue called circular queue

class Queue{
	int size;
	int capacity=0;
	int front = -1;
	int rear = -1;
	vector <int> q;
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
		if(capacity == size - 1) throw "overflow"; 
	 q[++rear]=value;
	 capacity++; 
	}catch(const char *e){
	cout<<"Queue is overflow"; 
	}	}
	
int Queue ::pop(){
	try{if(front == rear) throw "nothing to del";
	int x = q[front]; front++; return x;}catch(
		const char *e){cout<<"empty queue";}
			}
int Queue ::front_(){return q[front];}
int Queue ::rear_(){return q[rear];}
bool Queue ::isempty(){if(front == rear){return true;} else return false;}

int main(){
	Queue *ptr = new Queue(10);
	ptr->push(1);
	ptr->push(2);
	ptr->push(3);
	ptr->push(4);
	cout<<ptr->front_();
	cout<<endl;
	cout<<ptr->rear_();		
	cout<<endl<<ptr->isempty();
	cout<<endl<<ptr->pop();
	cout<<endl<<ptr->pop();	
	cout<<endl;
	cout<<ptr->front_();
	cout<<endl;
	cout<<ptr->rear_();		

	return 0;
	}
