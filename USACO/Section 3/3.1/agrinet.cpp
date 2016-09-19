/*
ID: liaojh11
PROG: agrinet
LANG: C++
*/
//Title: agrinet
//Type: MST
//Solution: Since presentation of edge is in adjacency list and 3 <= N <= 100, Prim's Algorithm works just fine, O(N^2).
#include <stdio.h>
#define INF 100000
FILE *fin, *fout;
int N, weight[101][101] = {0}, treecost = 0;
int main(){
	//Instantiation
	fin = fopen("agrinet.in", "r");
	fout = fopen("agrinet.out", "w");
	fscanf(fin, "%d", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			fscanf(fin, "%d", &weight[i][j]);
		}
	}
	//Prim's Algorithm
	bool intree[N+1] = {false};
	int distance[N+1];
	for(int i = 1; i <= N; i++)
		distance[i] = INF;
	//Adding first node
	intree[1] = true;
	for(int i = 1; i <= N; i++)
		if(distance[i] > weight[1][i])
			distance[i] = weight[1][i];
	//Search all nodes
	for(int treesize = 1; treesize < N; treesize++){
		int node, dist = INF;
		for(int i = 1; i <= N; i++){
			if(distance[i] < dist && !intree[i]){
				node = i;
				dist = distance[i];
			}
		}
		intree[node] = true;
		treecost += dist;
		for(int i = 1; i <= N; i++)
			if(distance[i] > weight[node][i] && !intree[i])
				distance[i] = weight[node][i];
	}
	//Print result
	fprintf(fout, "%d\n", treecost);
	return 0;
}