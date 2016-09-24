#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
vector<int> to[1010];
int T, N, P, C, people[1010], u, v;
bool visited[1010], complete;
bool cmp(int a, int b){
	return (a > b);
}
int DFS(int v){
	if(visited[v])
		return 0;
	visited[v] = true;
	int sum = 0;
	for(int i = 0; i < to[v].size(); i++){
		sum += DFS(to[v][i]);
	}
	return sum + 1;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &P, &C);
		for(int i = 0; i < C; i++){
			scanf("%d%d", &u, &v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		for(int i = 0; i < P; i++)
			people[i] = DFS(i);
		sort(people, people+P, cmp);
		int sum = 0;
		for(int i = 0; i < P; i++){
			if(sum >= N){
				printf("%d\n", i);
				complete = true;
				break;
			}
			sum += people[i];
		}
		if(!complete){
			if(sum < N)
				printf("IMPOSSIBLE\n");
			else
				printf("%d\n", P);
		}
		complete = false;
		memset(visited, 0, sizeof(visited));
		memset(people, 0, sizeof(people));
		for(int i = 0; i < P; i++)
			to[i].clear();
	}
	return 0;
}