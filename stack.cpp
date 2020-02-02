 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 class Stack{
	 int size;
	 int top = -1;
	 vector <int> S;
	 public:
	 Stack(int max_size){
		 this->size = max_size;
		 S = vector<int> (max_size, -1);
		  }
	 void push(int value); // pushes a new element on to the stack
	 int pop(); // removes the top most element from the stack
	 bool isempty(); // returns true or false if the stack is empty or not
	 int tp(); // returns the top most element	 
	 };

void Stack ::push(int value){
	
	try{
		if(top == size ){ throw "overflow";}
		S[++top] = value;
		}catch(const char *e){ cout<<"stack is full"<<endl;}
	}
	
int Stack ::pop(){
	try{if(top == -1){ throw "empty";}
		int x = S[top];
		top--;
			cout<<endl;	
		return x;		
		}catch(const char *e){cout<<"stack is empty"<<endl;}
	}
	
bool Stack ::isempty(){
	if(top == -1){return true;}
	else return false;
	}

int Stack ::tp(){
	return S[top];}
 
 int main(){
	 Stack *ptr = new Stack(10);
	 ptr->push(16);
	 ptr->push(52);
	 ptr->push(14);
	 ptr->push(31);
	 cout<<ptr->tp();	
	 ptr->pop();
	 cout<<ptr->tp();
	 ptr->pop();
	 ptr->pop();
	 ptr->pop();	 	 	 	
	 return 0;
	 }
