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
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

void FastIO::solve(){
	int N;
	readInt(N);
	int amount[N];
	for(int i = 0; i < N; i++)
		readInt(amount[i]);
	vector<pair<int, int> > edges[N];
	int M, u, v, w;
	readInt(M);
	for(int i = 0; i < M; i++){
		readInt(u);
		readInt(v);
		readInt(w);
		edges[u-1].push_back(pair<int, int>(v-1, w));
		edges[v-1].push_back(pair<int, int>(u-1, w));
	}
	//SPFA
	bool queued[N];
	memset(queued, 0, sizeof(queued));
	int maxamount[N], dist[N];
	memset(maxamount, 0, sizeof(maxamount));
	fill_n(dist, N, 1000000);
	maxamount[0] = amount[0];
	queued[0] = true;
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		u = q.front(); q.pop();
		queued[u] = false;
		int size = edges[u].size();
		for(int i = 0; i < size; i++){
			v = edges[u][i].first;
			w = edges[u][i].second;
			if(dist[v] > dist[u] + w || (dist[v] == dist[u] + w && maxamount[v] < maxamount[u] + amount[v])){
				dist[v] = dist[u] + w;
				maxamount[v] = maxamount[u] + amount[v];
				if(!queued[v]){
					q.push(v);
					queued[v] = true;
				}
			}
		}
	}
	if(dist[N-1] == 1000000)
		printf("impossible\n");
	else
		printf("%d %d\n", dist[N-1], maxamount[N-1]);
}