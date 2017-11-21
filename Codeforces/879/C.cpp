#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool has[2048][2048];
	memset(has, 0, sizeof(has));
	char etype[2048][2048];
	int enumi[2048][2048];
	int dist[2048];
	memset(dist, 1, sizeof(dist));
	bool vis[2048];
	memset(vis, 0, sizeof(vis));
	int parent[2048];
	memset(parent, -1, sizeof(parent));
	int ans = -1, next;
	char c;
	for(int i = 0; i < n; i++){
		cin >> c >> next;
		int u = ans, v;
		if(ans == -1 && c == '&'){
			ans = next;
			u = ans;
			dist[0] = 0;
			has[0][u] = true;
			etype[0][u] = c;
			enumi[0][u] = next;
			parent[u] = 0;
			dist[u] = 1;
		}else if(ans == -1){
			ans = 0;
			u = ans;
			dist[u] = 0;
		}
		//cout << u << " " << ans << endl;
		switch(c){
			case '|': v = ans|next; break;
			case '&': v = ans&next; break;
			case '^': v = ans^next; break;
		}
		if(!has[u][v]){
			has[u][v] = true;
			etype[u][v] = c;
			enumi[u][v] = next;
		}
		ans = v;
	}
	//dijkstra, simple
	for(int i = 0; i < 2048; i++){
		int index = -1, length = 1000000;
		for(int i = 0; i < 2048; i++)
			if(!vis[i] && dist[i] < length){
				index = i;
				length = dist[i];
			}
		vis[index] = true;
		for(int i = 0; i < 2048; i++)
			if(has[index][i] && dist[i] > dist[index]+1){
				dist[i] = dist[index]+1;
				parent[i] = index;
			}
	}
	//print answer
	printf("%d\n", dist[ans]);
	stack<char> path;
	stack<int> pathnum;
	while(parent[ans] != -1){
		path.push(etype[parent[ans]][ans]);
		pathnum.push(enumi[parent[ans]][ans]);
		ans = parent[ans];
	}
	while(!path.empty()){
		printf("%c %d\n", path.top(), pathnum.top());
		path.pop();
		pathnum.pop();
	}
	return 0;
}