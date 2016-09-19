/*
ID: liaojh11
PROG: cowtour
LANG: C++
*/
//Title: cowtour
//Type: Shortest Path
//Solution: No start point, all path comparison, edge adjacency matrix --> Floyd-Warshall algorithm.
		/*  1. Floyd-Warshall all possible path distances.
			2. Find the longest path distance from every vertex.
			3. Find unconnected vertices and test for minimum of maximum distances after connecting 2 vertices.
			4. If not above, then longest path is not the one that is disconnected, but the one within longest path distances from every vertex.
			*/
#include <stdio.h>
#include <math.h>
#include <limits.h>
#define INF (LONG_MAX)
FILE *fin, *fout;
int N, vx[151], vy[151];
double dist[151][151], vmax[151];
double pythagorean(int y1, int y2, int x1, int x2){
	int y = y1 - y2;
	int x = x1 - x2;
	return sqrt((double)y*y + (double)x*x);
}
int main(){
	//Instantiation
	fin = fopen("cowtour.in", "r");
	fout = fopen("cowtour.out", "w");
	fscanf(fin, "%i", &N);
	for(int i = 1; i <= N; i++){
		fscanf(fin, "%i%i", &vx[i], &vy[i]);
	}
	//Distance adjacency matrix instantiation
	for(int i = 1; i <= N; i++){
		int a = getc(fin); //Get rid of the carriage return char;
		for(int j = 1; j <= N; j++){
			a = getc(fin) - 48;
			if(i == j){
				dist[i][j] = 0;
				continue;
			}
			if(a) dist[i][j] = pythagorean(vy[i], vy[j], vx[i], vx[j]);
			else dist[i][j] = INF;
		}
	}
	//Floyd-Warshall all possible path distances
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	//Find the maximum possible distance from any vertex to any other vertex
	double longest = 0; //If the maximum possible distance is even longer than any path after connecting with unconnected vertex, print that instead
	for(int i = 1; i <= N; i++){
		double max = 0;
		for(int j = 1; j <= N; j++){
			if(dist[i][j] > max && dist[i][j] != INF)
				max = dist[i][j];
		}
		vmax[i] = max;
		if(longest < max)
			longest = max;
	}
	//Find the minimum distance of the maximum distance from any 2 unconnected vertex connecting each other
	double min = INF;
	bool visited[N+1][N+1] = {false};
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(visited[i][j]) continue;
			visited[i][j] = visited[j][i] = true;
			if(dist[i][j] == INF){
				double temp = pythagorean(vy[i], vy[j], vx[i], vx[j]);
				if(vmax[i] + vmax[j] + temp < min)
					min = vmax[i] + vmax[j] + temp;
			}
		}
	}
	fprintf(fout, "%.6f\n", min < longest ? longest : min);
	return 0;
}