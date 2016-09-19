/*
ID: liaojh11
PROG: maze1
LANG: C++
*/
//Title: maze1
//Type: Shortest Path (Correct one is BFS, this one MLE)
//Solution: Dijkstra's because this problem has uniform weight on edges, undirected edge paths, and all connected. Time complexity of O(V^2). However, memory limit exceeded.
#include <fstream>
using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");
int W, H, ex1 = 0, ex2 = 0;
int main(){
	fin >> W >> H;
	//Map input
	char map[2 * H + 1][2 * W + 1], extra[1];
	fin.getline(extra, 1);
	for(int i = 0; i < 2 * H + 1; i++){
		fin.getline(map[i], 2 * W + 2);
	}
	//Edge weights
	int weight[W * H + 1][W * H + 1] = {0};
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if((i == 1 && map[0][j * 2 - 1] != '-') || (i == H && map[i * 2][j * 2 - 1] != '-') || (j == 1 && map[i * 2 - 1][0] != '|') || (j == W && map [i * 2 - 1][2 * j] != '|')){
				ex1 = ex1 == 0 ? (i - 1) * W + j : ex1; //Search for the exit
				ex2 = ex1 == 0 ? ex2 : (i - 1) * W + j;
			}
			if(i < H){
				if(map[i * 2][j * 2 - 1] != '-'){
					weight[(i - 1) * W + j][i * W + j] = 1;
					weight[i * W + j][(i - 1) * W + j] = 1;
				}
			}
			if(j < W){
				if(map[i * 2 - 1][j * 2] != '|'){
					weight[(i - 1) * W + j][(i - 1) * W + j + 1] = 1;
					weight[(i - 1) * W + j + 1][(i - 1) * W + j] = 1;
				}
			}
		}
	}
	//Dijkstra's
	int distance[W * H + 1], min = 0, nodevisited = 0;
	//Let us define infinity as 9999, since it's bigger than max input of 3800.
	for(int i = 1; i <= W * H; i++){
		distance[i] = 9999;
	}
	bool visited[W * H + 1] = {0};

	//Let exit be the first vertex
	distance[ex1] = ex1 != 0 ? 1 : distance[ex1];
	distance[ex2] = ex2 != 0 ? 1 : distance[ex2];
	while(nodevisited < W * H){
		int next, dist = 9999;
		for(int i = 1; i <= W * H; i++){
			if(!visited[i] && distance[i] != 9999 && distance[i] < dist){
				next = i;
				dist = distance[i];
			}
		}
		visited[next] = 1;
		nodevisited++;
		for(int i = 1; i <= W * H; i++){
			if(weight[next][i] && (distance[next] + weight[next][i] < distance[i]))
				distance[i] = distance[next] + weight[next][i];
		}
	}

	//Print result
	for(int i = 1; i <= W * H; i++){
		if(distance[i] > min) min = distance[i];
	}
	fout << min << endl;
	return 0;
}