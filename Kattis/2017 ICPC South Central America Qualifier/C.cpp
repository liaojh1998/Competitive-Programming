#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		bool checked[N+5][5];
		memset(checked, 0, sizeof(checked));
		bool stop[N+5];
		memset(stop, 0, sizeof(stop));
		vector<pair<int, int>> edges[N+5];
		int u, v, bug;
		for(int i = 0; i < M; i++){
			cin >> u >> v;
			if(u > 0)
				edges[u].push_back(pair<int, int>(v, 0));
			else
				edges[-u].push_back(pair<int, int>(v, 1));
		}
		queue<pair<int, int>> q;
		q.push(pair<int, int>(1, 0));
		checked[1][0] = true;
		while(!q.empty()){
			pair<int, int> cur = q.front(); q.pop();
			u = cur.first;
			bug = cur.second;
			//printf("Case: %d %d\n", u, bug);
			int size = edges[u].size();
			bool forced = false;
			for(int i = 0; i < size; i++){
				v = edges[u][i].first;
				if(!bug && !edges[u][i].second && !checked[v][1]){
					checked[v][1] = true;
					q.push(pair<int, int>(v, 1));
				}else if(edges[u][i].second && !checked[v][bug]){
					checked[v][bug] = true;
					forced = true;
					q.push(pair<int, int>(v, bug));
				}else if(edges[u][i].second && checked[v][bug])
					forced = true;
			}
			if(!forced){
				//printf("%d %d ENDED\n", u, bug);
				stop[u] = true;
			}
		}
		int count = 0;
		for(int i = 1; i <= N; i++){
			if(stop[i]){
				count++;
				//printf("STOP: %d\n", i);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}