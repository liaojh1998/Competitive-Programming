//Title: Domino
//Type: Eulerian Tour
//Solution: Fleury's Algorithm + Edge List
#include <iostream>
#include <vector>
using namespace std;
typedef struct{int index, to; char sign;} Edge;
vector<Edge> edges[7];
int path[100] = {0}, pcount = 0, count, N;
char sign[100];
//Fleury's DFS
void DFS(bool map[], int node){
	count++;
	for(int i = 0; i < edges[node].size(); i++){
		if(!map[edges[node][i].index]){
			map[edges[node][i].index] = true;
			DFS(map, edges[node][i].to);
		}
	}
}
int main(){
	//Instantiation
	int N, node = 7;
	cin >> N;
	for(int i = 1; i <= N; i++){
		int a, b;
		Edge temp;
		cin >> a >> b;
		temp.index = i;
		temp.to = b;
		temp.sign = '+';
		edges[a].push_back(temp);
		temp.to = a;
		temp.sign = '-';
		edges[b].push_back(temp);
		if(node > a)
			node = a;
		if(node > b)
			node = b;
	}
	//Case impossible: more than 2 odd degrees
	int possible = 0;
	for(int i = 0; i < 7; i++){
		if(edges[i].size()%2)
			possible++;
	}
	if(possible > 2){
		cout << "No solution" << endl;
		return 0;
	}
	//Start point
	for(int i = 0; i < 7; i++){
		if(edges[i].size()%2){
			node = i;
			break;
		}
	}
	//Fleury's Algorithm
	while(edges[node].size()){
		//Find most possible edge
		int index, max = 0;
		for(int i = 0; i < edges[node].size(); i++){
			count = 0;
			bool map[100] = {false};
			map[edges[node][i].index] = true;
			//DFS possible edge
			DFS(map, edges[node][i].to);
			if(count > max){
				max = count;
				index = i;
			}
		}
		//Save possible edge
		Edge temp;
		temp = edges[node][index];
		path[pcount] = temp.index;
		sign[pcount] = temp.sign;
		pcount++;
		//Erase edge
		edges[node].erase(edges[node].begin() + index);
		for(int i = 0; i < edges[temp.to].size(); i++){
			if(edges[temp.to][i].index == temp.index){
				edges[temp.to].erase(edges[temp.to].begin() + i);
				break;
			}
		}
		//Set next node
		node = temp.to;
	}
	//Case impossible: disconnected graph
	for(int i = 0; i < 7; i++){
		if(edges[i].size() > 0){
			cout << "No solution" << endl;
			return 0;
		}
	}
	//Print results
	for(int i = 0; i < N; i++){
		cout << path[i] << " " << sign[i] << endl;
	}
	return 0;
}