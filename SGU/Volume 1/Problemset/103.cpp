//Title: Traffic Lights
//Type: Shortest Path
//Solution: Dijkstra's + Adjacency List + Changing lights Simulation(LITERALLY LOL)
#include <cstdio>
#include <vector>
using namespace std;
const int INF = 3000001; //300 * 100 * 100 + 1
struct node{
	int r, t[2], color, time, visited;
	vector<int> path;
}nodes[301];
struct edge{int to, l;};
int N, M, start, end;
vector<edge> edges[301];
//Check for the color at current time and change it
int colorcheck(int f, int t){
	int current = nodes[f].time, ftime = nodes[f].r - current, ttime = nodes[t].r - current;
	//Check current color, B = 0, P = 1
	int fcolor = nodes[f].color, tcolor = nodes[t].color;
	if(ftime <= 0){
		fcolor = !fcolor;
		ftime = ftime%(nodes[f].t[0]+nodes[f].t[1]) + nodes[f].t[fcolor];
		if(ftime <= 0){
			fcolor = !fcolor;
			ftime += nodes[f].t[fcolor];
		}
	}
	if(ttime <= 0){
		tcolor = !tcolor;
		ttime = ttime%(nodes[t].t[0]+nodes[t].t[1]) + nodes[t].t[tcolor];
		if(ttime <= 0){
			tcolor = !tcolor;
			ttime += nodes[t].t[tcolor];
		}
	}
	//Color is same
	if(fcolor == tcolor)
		return 0;
	//Color is not the same
	int addtime = 0, count = 3, minus; //Case impossible: light will never be the same after 3 tries
	while(count--){
		if(ftime < ttime)
			minus = ftime;
		else
			minus = ttime;
		addtime += minus;
		ftime -= minus;
		ttime -= minus;
		if(!ftime){
			fcolor = !fcolor;
			ftime += nodes[f].t[fcolor];
		}
		if(!ttime){
			tcolor = !tcolor;
			ttime += nodes[t].t[tcolor];
		}
		//Color is now the same
		if(fcolor == tcolor)
			return addtime;
	}
	//Case impossible
	return INF;
}
int main(){
	//Instantiation
	scanf("%d%d%d%d", &start, &end, &N, &M);
	for(int i = 1; i <= N; i++){
		if(i == start)
			nodes[i].time = 0;
		else
			nodes[i].time = INF;
		char sign;
		int s;
		scanf(" %c%d%d%d", &sign, &nodes[i].r, &nodes[i].t[0], &nodes[i].t[1]);
		if(sign == 'B') s = 0;
		else s = 1;
		nodes[i].color = s;
	}
	for(int i = 0; i < M; i++){
		edge temp;
		int a, b;
		scanf("%d%d%d", &a, &b, &temp.l);
		temp.to = b;
		edges[a].push_back(temp);
		temp.to = a;
		edges[b].push_back(temp);
	}
	//Dijkstra's Algorithm
	for(int nodevisited = 0; nodevisited < N; nodevisited++){
		//Search for node with smallest distance to start
		int max = INF, next = 0;
		for(int i = 1; i <= N; i++){
			if(nodes[i].time < max && !nodes[i].visited){
				next = i;
				max = nodes[i].time;
			}
		}
		//Case impossible: disconnected graph
		if(!next)
			break;
		//Map node as visited
		nodes[next].visited = 1;
		nodes[next].path.push_back(next);
		//Update neighbor of current node
		for(int i = 0; i < edges[next].size(); i++){
			int to = edges[next][i].to;
			int colorchange = colorcheck(next, to);
			if(nodes[next].time + colorchange + edges[next][i].l < nodes[to].time){
				nodes[to].time = nodes[next].time + colorchange + edges[next][i].l;
				nodes[to].path = nodes[next].path;
			}
		}
	}
	//Print results
	if(nodes[end].time != INF){
		printf("%d\n", nodes[end].time);
		for(int i = 0; i < nodes[end].path.size(); i++){
			if(i == nodes[end].path.size() - 1)
				printf("%d", nodes[end].path[i]);
			else
				printf("%d ", nodes[end].path[i]);
		}
	}else{
		printf("0");
	}
	printf("\n");
	return 0;
}