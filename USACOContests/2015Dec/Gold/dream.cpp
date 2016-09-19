//Problem: Bessie's Dream (Gold)
//Type: Shortest Path
//Solution: Trying this for the fun of it using Dijkstra's + Priority Queue
#include <fstream>
#include <queue>
#define INF 1000000 //1000*1000
using namespace std;
ifstream fin("dream.in");
ofstream fout("dream.out");
int N, M, map[1002][1002], visited[1002][1002][2], dirx[4] = {-1,0,1,0}, diry[4] = {0,1,0,-1};
typedef struct{int y, x, smell, dist;} node;
bool operator<(node a, node b){
	return a.dist > b.dist; //true = b goes before a, false = a goes before b
}
priority_queue<node> q;
bool passable(int smell, int tile){
	//Tile 0 scenario
	if(!tile) return false;
	//Tile 3 scenario
	if(tile == 3) return (smell > 0);
	//Else
	return true;
}
int main(){
	//Instantiation
	fin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			fin >> map[i][j];
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			for(int k = 0; k < 2; k++){
				visited[i][j][k] = INF;
			}
		}
	}
	//Dijkstra's
	//Start node
	node start;
	start.y = 1; start.x = 1; start.smell = 0; start.dist = 0;
	q.push(start);
	//Algorithm
	while(!q.empty()){
		node temp;
		temp = q.top();
		q.pop();
		//Arrived shortest path
		if(temp.y == N && temp.x == M){
			fout << temp.dist << endl;
			return 0;
		}
		//Don't visit if has smaller path and if already been visited (we can just use != INF since this is a priority queue)
		if(visited[temp.y][temp.x][temp.smell] <= temp.dist)
			continue;
		visited[temp.y][temp.x][temp.smell] = temp.dist;
		//Update neighbors
		for(int i = 0; i < 4; i++){
			int x = temp.x + dirx[i];
			int y = temp.y + diry[i];
			int smell = temp.smell;
			int dist = temp.dist + 1;
			//Impassible scenario
			if(!passable(smell, map[y][x])) continue;
			//Tile 4 scenario
			if(map[y][x] == 4){
				while(map[y][x] == 4 && passable(smell, map[y+diry[i]][x+dirx[i]])){
					x += dirx[i];
					y += diry[i];
					dist++;
					smell = 0;
				}
			}
			//Tile 2 scenario
			if(map[y][x] == 2)
				smell = 1;
			//Has been visited?
			if(visited[y][x][smell] <= dist) continue;
			//Queue it
			node n;
			n.x = x; n.y = y; n.smell = smell; n.dist = dist;
			q.push(n);
		}
	}
	//No solution, disconnected graph
	fout << -1 << endl;
	return 0;
}