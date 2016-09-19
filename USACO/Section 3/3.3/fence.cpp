/*
ID: liaojh11
PROG: fence
LANG: C++
*/
//Title: fence
//Type: Eulerian Tour
//Solution: Hierholzer Algorithm + Adjacency List.
#include <fstream>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
int adjlist[501][501] = {0}, edgecount[501] = {0}, path[1025] = {0}, count = 0;
//Hierholzer Algorithm (modified with an adjacency list in a matrix)
void circuit(int node){
	if(!edgecount[node])
		path[count++] = node;
	else{
		while(edgecount[node]){
			int next;
			for(int i = 1; i < 501; i++){
				if(adjlist[node][i]){
					next = i;
					break;
				}
			}
			adjlist[node][next]--;
			adjlist[next][node]--;
			edgecount[next]--;
			edgecount[node]--;
			circuit(next);
		}
		path[count++] = node;
	}
}
int main(){
	//Instantiation
	int F, start = 500;
	fin >> F;
	for(int i = 0; i < F; i++){
		int a, b;
		fin >> a >> b;
		if(a < start)
			start = a;
		if(b < start)
			start = b;
		adjlist[a][b]++;
		adjlist[b][a]++;
		edgecount[a]++;
		edgecount[b]++;
	}
	//Start point
	for(int i = start; i < 501; i++){
		if(edgecount[i]%2){
			start = i;
			break;
		}
	}
	//Hierholzer Algorithm
	circuit(start);
	//Print results
	for(int i = count - 1; i >= 0; i--){
		fout << path[i] << endl;
	}
	return 0;
}