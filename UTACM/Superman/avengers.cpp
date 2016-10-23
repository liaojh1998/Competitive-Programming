//Single-sourced shortest-path algorithm template
#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

template<int V> struct SSSP{
	int result[V], prev[V];
	bool checked[V];
	vector<pair<int, int> > G[V];
	//For adding edges
	void add(int from, int to, int dist){
		G[from].push_back(pair<int, int>(to, dist));
	}
	//Comparison objects
	class cmp{
		public:
		bool operator()(const pair<int, int> &a, const pair<int, int> &b){
			//Change this if not shortest-path
			return a.second > b.second;
		}
	};
	bool check(const int &a, const int &b){
		//Change this opposite to the above if not shortest-path
		return a < b;
	}
	//Dijkstra execution
	//V, E <= 300,000, best on weighted graph, overkill on small graph
	//(no negative cycle (cannot detect), undirected/directed graph)
	//Time complexity: O((|E| + |V|)log|V|)
	void dijkstra(int s){
		fill_n(checked, V, 0);
		//Unless you want previous, this is not needed
		//fill_n(prev, V, -1);
		priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
		q.push(pair<int, int>(s, 0));
		result[s] = 0;
		checked[s] = true;
		while(!q.empty()){
			pair<int, int> p = q.top(); q.pop();
			if(check(result[p.first], p.second)) continue;
			int len = G[p.first].size();
			for(int i = 0; i < len; i++)
				if(!checked[G[p.first][i].first] || check(p.second + G[p.first][i].second, result[G[p.first][i].first])){
					//prev[G[p.first][i].first] = p.first;
					checked[G[p.first][i].first] = true;
					result[G[p.first][i].first] = p.second + G[p.first][i].second;
					q.push(pair<int, int>(G[p.first][i].first, result[G[p.first][i].first]));
				}
		}
	}
	//Bellman-Ford Execution
	//V*E <= 10,000,000, okay on weighted graph with negative weights
	//Terminates at N (limit to save time)
	//(no negative cycles (can detect), undirected/directed graph)
	//Time complexity: O(|V||E|)
	void bellmanford(int s, int N){
		fill_n(checked, V, 0);
		//Unless you want previous, this is not needed
		//fill_n(prev, V, -1);
		result[s] = 0;
		checked[s] = true;
		for(int i = 0; i < N-1; i++){
			for(int j = 0; j < N; j++){
				int len = G[j].size();
				for(int k = 0; k < len; k++)
					if(checked[j] && (!checked[G[j][k].first] || check(result[j] + G[j][k].second, result[G[j][k].first]))){
						checked[G[j][k].first] = true;
						result[G[j][k].first] = result[j] + G[j][k].second;
						//prev[G[j][k].first] = j;
					}
			}
		}
		//This is used to check if there is negative-weight cycles
		/*
		for(int i = 0; i < V; i++){
			int len = G[i].size();
			for(int j = 0; j < len; j++)
				if(result[i] + G[i][j].second < result[G[i][j].first]){
					printf("Graph has a negative-weight cycle\n");
					return;
				}
		}
		*/
	}
	//SPFA Execution
	//(no negative cycles (cannot detect), undirected/directed graph)
	//Time complexity: O((|E| + |V|)log|V|) on dense graphs, average case time complexity O(|E|)
	void spfa(int s){
		fill_n(checked, V, 0);
		bool queued[V];
		fill_n(queued, V, 0);
		//Unless you want previous, this is not needed
		//fill_n(prev, V, -1);
		priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
		result[s] = 0;
		q.push(pair<int, int>(s, 0));
		checked[s] = true;
		while(!q.empty()){
			pair<int, int> p = q.top(); q.pop();
			queued[p.first] = false;
			int len = G[p.first].size();
			for(int i = 0; i < len; i++){
				if(!checked[G[p.first][i].first] || check(result[p.first] + G[p.first][i].second, result[G[p.first][i].first])){
					//prev[G[p.first][i].first] = p.first;
					checked[G[p.first][i].first] = true;
					result[G[p.first][i].first] = result[p.first] + G[p.first][i].second;
					if(!queued[G[p.first][i].first]){
						queued[G[p.first][i].first] = true;
						q.push(pair<int, int>(G[p.first][i].first, result[p.first]));
					}
				}
			}
		}
	}
	//Topological Sort Execution
	//(directed acyclic graph only)
	//Time complexity: O(|V| + |E|)
	//DFS for execution
	void dfs(int v){
		int len = G[v].size();
		for(int i = 0; i < len; i++)
			if(!checked[G[v][i].first] || check(result[v] + G[v][i].second, result[G[v][i].first])){
				result[G[v][i].first] = result[v] + G[v][i].second;
				checked[G[v][i].first] = true;
				dfs(G[v][i].first);
			}
	}
	//Execution
	void tsort(int s){
		fill_n(checked, V, 0);
		checked[s] = true;
		dfs(s);
	}
	//Sample print results, -1 means no chance of getting to the node
	void print(int max_number_of_nodes){
		for(int i = 0; i < max_number_of_nodes; i++){
			printf("%d: %d\n", i, !checked[i] ? -1 : result[i]);
		}
	}
};
int T;
int main(){
	//Enter code here
	scanf("%d", &T);
	while(T--){
		SSSP<30001> G;
		int E, F, H, u, v;
		string s;
		scanf("%d%d%d", &E, &F, &H);
		for(int i = 0; i < E; i++){
			scanf("%d%d%s", &u, &v, &s);
			if(s == "DOWN"){
				if(v > u){
					int temp = v;
					v = u;
					u = temp;
				}
			}else{
				if(u > v){
					int temp = v;
					v = u;
					u = temp;
				}
			}
			G.add(u, v, 1);
		}
	}
	return 0;
}