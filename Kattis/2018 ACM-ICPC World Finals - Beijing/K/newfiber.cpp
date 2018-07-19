#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, u, v;
	cin >> N >> M;
	vector<int> G[N+5];
	while(M--){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	queue<int> remain;
	queue<pair<int, int>> linked;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> unlinked;
	for(int i = 0; i < N; i++){
		if(G[i].size() == 1)
			remain.push(i);
		else
			unlinked.push(pair<int, int>(G[i].size(), i));
	}
	int ans = N;
	vector<pair<int, int>> edges;
	//Stage 1
	while(!unlinked.empty() && !remain.empty()){
		pair<int, int> tmp = unlinked.top();
		unlinked.pop();
		while(!remain.empty() && tmp.first > 1){
			int p = remain.front();
			remain.pop();
			tmp.first--;
			ans--;
			edges.push_back(pair<int, int>(p, tmp.second));
		}
		if(tmp.first == 1)
			remain.push(tmp.second);
		else
			unlinked.push(tmp);
	}
	//Stage 2
	if(!unlinked.empty()){
		pair<int, int> tmp = unlinked.top();
		unlinked.pop();
		linked.push(tmp);
	}
	while(!unlinked.empty()){
		pair<int, int> tmp = unlinked.top();
		unlinked.pop();
		edges.push_back(pair<int, int>(linked.front().second, tmp.second));
		linked.front().first--;
		tmp.first--;
		if(!linked.front().first){
			linked.pop();
			ans--;
		}
		linked.push(tmp);
	}
	//Stage 3: Chain case
	if(!remain.empty()){
		int p = remain.front(); remain.pop();
		int q = remain.front(); remain.pop();
		edges.push_back(pair<int, int>(p, q));
		ans -= 2;
	}
	//Print
	cout << ans << endl;
	cout << N << " " << N-1 << endl;
	for(int i = 0; i < N-1; i++)
		cout << edges[i].first << " " << edges[i].second << endl;
	return 0;
}