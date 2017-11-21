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

pair<int, int> dfs(int u, bool visBank, vector<int>* edges, bool* hasBank, bool* vis){
	vis[u] = true;
	pair<int, int> ans = make_pair((visBank ? u : -1), -1);
	int size = edges[u].size(), v;
	for(int i = 0; i < size; i++){
		v = edges[u][i];
		if(!vis[v]){
			//printf("at %d going %d %s\n", u, v, (hasBank[v] ? "hasBank" : "!hasBank"));
			pair<int, int> temp = dfs(v, (visBank || hasBank[v]), edges, hasBank, vis);
			//printf("here got: %d %d\n", temp.first, temp.second);
			if(temp.first > ans.first){
				ans.second = ans.first;
				ans.first = temp.first;
			}else if(temp.first > ans.second)
				ans.second = temp.first;
			if(temp.second > ans.second)
				ans.second = temp.second;
			//printf("ans has: %d %d\n", ans.first, ans.second);
		}
	}
	//printf("vis: %d, has %s %d %d\n", u, (visBank ? "visBank" : "!visBank"), ans.first, ans.second);
	return ans;
}

void FastIO::solve(){
	int T, N, M, u, v, type, C;
	readInt(T);
	while(T--){
		readInt(N);
		readInt(M);
		vector<int> edges[N+1];
		bool hasBank[N+1], vis[N+1];
		memset(hasBank, 0, sizeof(hasBank));
		for(int i = 0; i < N-1; i++){
			readInt(u);
			readInt(v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		while(M--){
			readInt(type);
			readInt(C);
			if(type == 1)
				hasBank[C] = true;
			else{
				memset(vis, 0, sizeof(vis));
				pair<int, int> ans = dfs(C, hasBank[C], edges, hasBank, vis);
				printf("%d\n", ans.second);
			}
		}
	}
}