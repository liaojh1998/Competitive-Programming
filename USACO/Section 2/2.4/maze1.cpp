/*
ID: liaojh11
PROG: maze1
LANG: C++
*/
//Title: maze1
//Type: BFS
//Solution: USACO is such a troll, recommending shortest path on a BFS. BFS Flood Fill and search for the longest path.
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");
int W, H;
struct vertex{int y, x, dist;} v;
queue<vertex> q;
int main(){
	//Instantiation
	fin >> W >> H;
	int d[H+1][W+1], m = 0; //Distance array, m = maximum distance required
	bool visited[H+1][W+1];
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			d[i][j] = 9999; //Define infinity as 9999 since longest possible from 38 * 100 is 3800.
		}
	}
	//Map input
	char map[H*2+1][W*2+1], extra[1];
	fin.getline(extra, 1);
	for(int i = 0; i < 2*H+1; i++){
		fin.getline(map[i], 2*W+2);
	}
	//Search for exits
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if((i == 1 && map[0][j*2-1] != '-') || (i == H && map[i*2][j*2-1] != '-') || (j == 1 && map[i*2-1][0] != '|') || (j == W && map [i*2-1][j*2] != '|')){
				//BFS flood fill from exit
				for(int k = 1; k <= H; k++){
					for(int l = 1; l <= W; l++){
						visited[k][l] = 0;
					}
				}
				v.y = i; v.x = j; v.dist = 1;
				q.push(v);
				while(!q.empty()){
					int y = q.front().y;
					int x = q.front().x;
					int dist = q.front().dist;
					q.pop();

					if(visited[y][x]) continue;
					visited[y][x] = 1;

					if(dist < d[y][x])
						d[y][x] = dist;

					if(y > 1 && map[(y-1)*2][x*2-1] != '-'){
						v.x = x; v.y = y - 1; v.dist = dist + 1;
						q.push(v);
					}
					if(x < W && map[y*2-1][x*2] != '|'){
						v.x = x + 1; v.y = y; v.dist = dist + 1;
						q.push(v);
					}
					if(y < H && map[y*2][x*2-1] != '-'){
						v.x = x; v.y = y + 1; v.dist = dist + 1;
						q.push(v);
					}
					if(x > 1 && map[y*2-1][(x-1)*2] != '|'){
						v.x = x - 1; v.y = y; v.dist = dist + 1;
						q.push(v);
					}
				}
			}
		}
	}
	//Print results
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if(d[i][j] > m) m = d[i][j];
		}
	}
	fout << m << endl;
	return 0;
}