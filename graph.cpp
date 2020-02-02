#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//undirected graph without weights
class Graph{
	int number_of_elements;
	list <int> *g; //graph as a adjacency list
	queue <int> q;
	stack <int> stk;
	int k =0;
	vector <int> visited;
	public:
	Graph(int max_size){this->number_of_elements = max_size; g = new list <int>[max_size]; visited = vector <int> (max_size, 0);} // graph initilaization have been done
	void reinitialize(){
		k=0; visited = vector <int> (number_of_elements, 0); 
		}
	void insert(int v1, int v2){
		g[v1].push_back(v2); g[v2].push_back(v1);
		}
	void display(){
		for(int i = 0; i < number_of_elements; i++){ for(auto it:g[i]){cout<<it<<" ";} cout<<endl;}
		}	
	void del(int v1, int v2){
		g[v1].remove(v2); g[v2].remove(v1);
		}	
	void bfs(int s){if(k == 0){q.push(s); k++;} while(!q.empty()){{cout<<s<<" "; visited[s] = 1; 
		for(auto x:g[s]){if(visited[x] == 0){q.push(x);}}
		q.pop();
		bfs(q.front());
		} } 
		reinitialize();
		}
		
	void dfs(int s){
			if(k == 0){stk.push(s); k++;} while(!stk.empty()){ 
			if(visited[s] == 0){ for(auto x:g[s]){if(visited[x] == 0){stk.push(x);}} visited[s]=1;
				int w = stk.top(); cout<<stk.top()<<" "; stk.pop(); dfs(w);}
			}		
		reinitialize();
		 }
	
	};

int main(){
	int max_size;
	cout<<"enter the number of nodes in a graph";
	cin>>max_size;
	Graph * ptr = new Graph(max_size+1);
	ptr->insert(1,2);
	ptr->insert(1,3);
	ptr->insert(1,4);
	ptr->insert(4,5);
	ptr->insert(5,6);
	ptr->insert(6,7);
	ptr->insert(2,8);
	ptr->display();
	cout<<"-------------"<<endl;
	ptr->dfs(1);	
	cout<<endl;	
	
	
	return 0;
	}

