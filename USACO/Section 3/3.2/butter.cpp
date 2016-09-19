/*
ID: liaojh11
PROG: butter
LANG: C++
*/
//Title: butter
//Type: SPFA (Shortest Path Faster Algorithm)
//Solution: Same SP algorithm as Dijkstra's but improved by using an adjacency list instead of an adjacency matrix, and used boolean to queue paths that must be visited.
		/*	USACO solution used Dijkstra's + Heap, future reference to check that out. */
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");
typedef struct{int to; int dist;} Edge;
int cow[801], dist[801], map[801], N, P, C;
vector<Edge> edge[801];
void SPFA(int start){
	//Assume all distance is infinity
	memset(dist, 225*1450, sizeof(dist));
	//Assume all needs to be visited
	memset(map, 0, sizeof(map));
	//Assume distance to current location is 0
	dist[start] = 0;
	map[start] = 1;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		int loc = Q.front();
		Q.pop();
		map[loc] = 0;
		for(int i = 0; i < edge[loc].size(); i++){
			int to = edge[loc][i].to;
			int d = edge[loc][i].dist;
			if(dist[to] > dist[loc] + d){
				dist[to] = dist[loc] + d;
				//If next location has not been queued for visit
				if(!map[to]){
					//Queue it
					map[to] = 1;
					Q.push(to);
				}
			}
		}
	}
}
int main(){
	//Instantiation
	fin >> N >> P >> C;
	memset(cow, 0, sizeof(cow));
	for(int i = 0; i < N; i++){
		int t;
		fin >> t;
		cow[t]++;
	}
	for(int i = 0; i < C; i++){
		int a, b, d;
		fin >> a >> b >> d;
		Edge t;
		t.to = a;
		t.dist = d;
		edge[b].push_back(t);
		t.to = b;
		edge[a].push_back(t);
	}
	//SPFA
	int max = 225*1250;
	for(int i = 1; i <= P; i++){
		SPFA(i);
		int temp = 0;
		for(int j = 1; j <= P; j++){
			temp += cow[j] * dist[j];
		}
		if(temp < max)
			max = temp;
	}
	//Print solution
	fout << max << endl;
	return 0;
}