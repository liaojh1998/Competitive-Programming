//Type: SPFA
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int T, f, N, D, U, C, L, time[10005];
struct edge{int to, time;} temp;
vector<edge> edges[10005];
queue<int> q;
bool has[10005];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d%d", &N, &D, &U, &C, &L);
		for(int i = 0; i < C; i++){
			scanf("%d%d%d", &f, &temp.to, &temp.time);
			edges[f].push_back(temp);
		}
		for(int i = 0; i < L; i++){
			scanf("%d%d%d", &f, &temp.to, &temp.time);
			edges[f].push_back(temp);
		}
		//SPFA
		memset(time, 1, sizeof(time));
		time[1] = 0;
		q.push(1);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			has[node] = false;
			if(node-1 > 0 && time[node-1] > time[node] + U){
				time[node-1] = time[node] + U;
				if(!has[node-1]){
					q.push(node-1);
					has[node-1] = true;
				}
			}
			if(node+1 <= N && time[node+1] > time[node] + D){
				time[node+1] = time[node] + D;
				if(!has[node+1]){
					q.push(node+1);
					has[node+1] = true;
				}
			}
			for(int i = 0; i < edges[node].size(); i++)
				if(time[edges[node][i].to] > time[node] + edges[node][i].time){
					time[edges[node][i].to] = time[node] + edges[node][i].time;
					if(!has[edges[node][i].to]){
						q.push(edges[node][i].to);
						has[edges[node][i].to] = true;
					}
				}
		}
		printf("%d\n", time[N]);
		for(int i = 1; i <= N; i++)
			edges[i].clear();
	}
	return 0;
}