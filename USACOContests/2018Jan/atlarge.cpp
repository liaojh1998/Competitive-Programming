#include <bits/stdc++.h>
using namespace std;

class FastIO{
private:
	int readInt(int &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("atlarge.in", "r", stdin);
			freopen("atlarge.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

int dfs(int cur, vector<int> *G, int *parent, int *dist){
	if(G[cur].size() == 1)
		return (dist[cur] = 0);
	int size = G[cur].size(), v, mindist = 999999;
	for(int i = 0; i < size; i++){
		v = G[cur][i];
		if(parent[cur] != v){
			parent[v] = cur;
			mindist = (mindist, dfs(v, G, parent, dist));
		}
	}
	return (dist[cur] = mindist+1);
}

int dfs(int cur, vector<int> *G, int *parent, int *dist, int depth){
	if(depth == dist[cur] || depth-1 == dist[cur])
		return 1;
	int count = 0, size = G[cur].size(), v;
	for(int i = 0; i < size; i++){
		v = G[cur][i];
		if(parent[cur] != v)
			count += dfs(v, G, parent, dist, depth+1);
	}
	return count;
}

void FastIO::solve(){
	int N, K, u, v;
	readInt(N);
	readInt(K);
	vector<int> G[N+5];
	for(int i = 0; i < N-1; i++){
		readInt(u);
		readInt(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int parent[N+5], dist[N+5];
	memset(parent, -1, sizeof(parent));
	dfs(K, G, parent, dist);
	printf("%d\n", dfs(K, G, parent, dist, 0));
}