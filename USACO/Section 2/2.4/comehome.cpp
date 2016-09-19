/*
ID: liaojh11
PROG: comehome
LANG: C++
*/
//Title: comehome
//Type: Shortest Path
//Solution: All nonnegative weighted edges, all connected, start from source 'Z'. --> Dijkstra's algorithm.
		//  Since 'z' was 122 in char, originally had 123-sized arrays but somehow signalled MLE? Changed to 52-sized and used function to find char.
#include <stdio.h>
#define INF 52001 //No more than 52 char * 1000 distance
FILE *fin, *fout;
char nodearray[52];
int P, cost[52][52], dist[52], nodecount = 0;
bool nodemark[52], visited[52];
int nodenum(char a){
	for(int i = 0; i < 52; i++){
		if(a == nodearray[i])
			return i;
	}
}
int main(){
	//Instantiation
	for(int c = 65; c < 91; c++){
		nodearray[c - 65] = c;
	}
	for(int c = 97; c < 123; c++){
		nodearray[c - 71] = c;
	}
	fin = fopen("comehome.in", "r");
	fout = fopen("comehome.out", "w");
	fscanf(fin, "%d\n", &P);
	//Edge costs, shortest path, visited adjacency matrix instantiation
	for(int i = 0; i < 52; i++){
		nodemark[i] = visited[i] = false;
		dist[i] = INF;
		for(int j = 0; j < 52; j++){
			cost[i][j] = INF;
		}
	}
	//Input
	for(int i = 0; i < P; i++){
		char a, b;
		int d;
		fscanf(fin, "%c %c %d\n", &a, &b, &d);
		if(a == b) continue;
		nodemark[nodenum(a)] = nodemark[nodenum(b)] = 1;
		if(cost[nodenum(a)][nodenum(b)] > d){
			cost[nodenum(a)][nodenum(b)] = cost[nodenum(b)][nodenum(a)] = d;
		}
	}
	for(int i = 0; i < 52; i++){
		if(nodemark[i]) nodecount++;
	}
	//Dijkstra's Algorithm (though Floyd-Warshall can work, different algorithms are good practice)
	int count = 0;
	dist[nodenum('Z')] = 0; //Start from barn
	while(count < nodecount){
		int node, d = INF;
		//Find unvisited pasture closest to barn
		for(int i = 0; i < 52; i++){
			if(!visited[i] && dist[i] != INF && dist[i] < d){
				d = dist[i];
				node = i;
			}
		}
		visited[node] = true;
		count++;
		//Update neighbor pasture path size
		for(int i = 0; i < 52; i++){
			if(d + cost[node][i] < dist[i]) //Shorter path to pasture?
				dist[i] = d + cost[node][i];
		}
	}
	//Print results
	int min = INF;
	char pasture;
	for(int i = 0; i < 25; i++){
		if(dist[i] < min){
			min = dist[i];
			pasture = nodearray[i];
		}
	}
	fprintf(fout, "%c %d\n", pasture, min);
	return 0;
}