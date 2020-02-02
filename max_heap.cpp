#include <iostream>
#include <vector> 
using namespace std;

class Max_heap{
	int size; 
	int load_factor=0;
	vector <int> v;
	public:
	Max_heap(int max_size){this->size = max_size; v.push_back(-100);}
	void normal_heap_or_almost_complete_bt(int value){v.push_back(value);}
	void construction(int value){
		load_factor++;
		v.push_back(value);
		if(load_factor !=1){ 
			int it = v.size()-1; 
			if(v[it] > v[int(it/2)]){
				int temp = v[it];
				 v[it] = v[int(it/2)];
				  v[int(it/2)] = temp;
				 }
					}
			  }
			   
	int peek(){return v[1];}
	
	void insert(int value){  //goes till root of heap
		v.push_back(value);
		int it = v.size() - 1;
		int temp;
		while(v[it] > v[int(it/2)]){
			if(it == 1){return;}
			 temp = v[it];
			 v[it] = v[int(it/2)];
			  v[int(it/2)] = temp;
			  it = int(it/2);
			 }		
		}		
		
	int del(){	
		int l,i,r,temp,actual_size = v.size()-1; int rt = v[1];
		temp = v[1]; v[1] = v[actual_size]; v[actual_size] = temp; 
		v.erase(v.end() - 1);
		actual_size--;
		i = 1; l = i*2; r = i*2 +1;
		while(i<= int(actual_size/2) && l <= int(actual_size/2) && r <= int(actual_size/2)){	
			if(v[l] > v[i] && v[l] > v[r]){temp = v[i]; v[i] = v[l]; v[l] = temp; i = l;}
			if(v[r] > v[i] && v[r] > v[l]){temp = v[i]; v[i] = v[r]; v[r] = temp; i = r;}	
			else{return rt;}
			l = i*2; r = i*2 +1;
			}
		return rt;
			}
						
	void display(){for(int x:v){cout<<x<<" ";} cout<<endl;}
	
	};


int main(){
	int t,n[6]={100,80,60,40,70,50};
	cin>>t;
//	int bt[6] = {1,2,3,4,5,6}; 
	Max_heap *ptr = new Max_heap(t+1);
	for(int i=0;i<t;i++){ ptr->construction(n[i]);}
	ptr->display();
	ptr->insert(156);	
	ptr->display();
	ptr->del();	
	ptr->display();
	
	
	return 0;
	
	}

