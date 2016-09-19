//Title: Bridges painting
//Type: Simulation/Structure
//Solution: This is like an Eulerian tour, except the graph can have more than 2 odd edges and can be disconnected.
		/*	However, we still have to start structuring from odd edges before going to even ones because even edges will always have different colored edges
			but only by starting from odd edges will odd edges have different colored edges. */
#include <cstdio>
int deg[101], graph[101][101], color[101][101], N, V;
void struc(int v, int c){
	c = 3 - c;	//Change the color
	for(int i = 0; i < deg[v]; i++)
		if(!color[v][graph[v][i]]){
			color[v][graph[v][i]] = color[graph[v][i]][v] = c;
			struc(graph[v][i], c);
			c = 3 - c; //Change color for next loop
		}
}
int main(){
	//Instantiation
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		while(scanf("%d", &V) && V)
			graph[i][deg[i]++] = V;
	}
	//Structure based on odds before evens
	for(int i = 1; i <= N; i++)
		if(deg[i] & 1) struc(i, 1);
	for(int i = 1; i <= N; i++) struc(i, 1);
	//Check if all bridges are painted
	for(int i = 1; i <= N; i++){
		if(deg[i] > 1){
			int check = 0;
			for(int j = 0; j < deg[i]; j++)
				check |= color[i][graph[i][j]];
			if(check != 3){
				printf("No solution\n");
				return 0;
			}//Only graphs with 1 and 2 will end up having 3
		}
	}
	//Print solution
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < deg[i]; j++)
			printf("%d ", color[i][graph[i][j]]);
		printf("0\n");
	}
	return 0;
}

//This is inccorect, check: http://blog.csdn.net/winoros/article/details/25006447
//That has the correct answer