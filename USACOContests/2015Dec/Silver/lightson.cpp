//Problem: Switching on the Lights (Silver)
//Type: BFS
//Solution: Just go down the path, the fact that you can light rooms far away from you makes this really hardcore
#include <fstream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
ifstream fin("lightson.in");
ofstream fout("lightson.out");
int N, M, illu;
typedef struct{int x, y;}edge;
int main(){
	//Instantiation
	fin >> N >> M;
	int room[N+2][N+2], connected[N+2][N+2], mapped[N+2][N+2];
	memset(room, 0, sizeof(room));
	memset(connected, 0, sizeof(connected));
	memset(mapped, 0, sizeof(mapped));
	vector<edge> list[N+1][N+1];
	queue<edge> q;
	for(int i = 0; i < M; i++){
		int x, y;
		fin >> x >> y;
		edge temp;
		fin >> temp.x >> temp.y;
		list[x][y].push_back(temp);
	}
	//BFS
	//Start Point
	edge temp;
	room[1][1] = 1;
	temp.x = 1;
	temp.y = 1;
	illu++;
	q.push(temp);
	//Queue
	while(!q.empty()){
		//Get next queue
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if(!room[x][y] || mapped[x][y]) continue;
		mapped[x][y] = 1;
		//Make this room connectable to others
		connected[x][y] = 1;
		//Lit the list and queue any connected
		for(int i = 0; i < list[x][y].size(); i++){
			int tx = list[x][y][i].x, ty = list[x][y][i].y;
			if(!room[tx][ty]){
				room[tx][ty] = 1;
				illu++;
				if(connected[tx-1][ty] || connected[tx+1][ty] || connected[tx][ty+1] || connected[tx][ty-1]){
					temp.x = tx;
					temp.y = ty;
					q.push(temp);
				}
			}
		}
		//BFS all around
		temp.x = x + 1; temp.y = y;
		q.push(temp);
		temp.x = x - 1;
		q.push(temp);
		temp.x = x; temp.y = y + 1;
		q.push(temp);
		temp.y = y - 1;
		q.push(temp);
	}
	//Print results
	fout << illu << endl;
	return 0;
}