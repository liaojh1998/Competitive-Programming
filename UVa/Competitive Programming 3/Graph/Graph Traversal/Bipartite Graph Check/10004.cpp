//Title: Bicoloring
//Type: Bipartite Graph Check
//Time Complexity: O(V + E)
//Solution: Make your own template
//Utilities template
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//Graph Utilities
template<int V> struct UtilG{
	vector<int> G[V];
	int color[V];
	//Add path
	void add(int u, int v){
		G[u].push_back(v);
	}

	//Bipartite Graph Check
	//Time Complexity: O(V + E)
	//returns true if bipartite, returns false if not
	//Start check from source s
	//Color fill in 0 and 1
	//Bipartite cycles have no odd cycles
	bool BGCheck(int s){
		queue<int> q; q.push(s);
		fill_n(color, V, -1); color[s] = 0; //Change if not fill 0, 1
		bool isBipartite = true;
		while(!q.empty() && isBipartite){
			int u = q.front(); q.pop(); int len = G[u].size();
			for(int i = 0; i < len && isBipartite; i++){
				int v = G[u][i];
				if(color[v] == -1){
					color[v] = 1 - color[u];
					q.push(v);
				}else if(color[u] == color[v]){
					isBipartite = false;
				}
			}
		}
		return isBipartite;
	}

	//Graph Edges Property Check (DFS)
	//Property: 0 - Directed, 1 - Bidirected, 2 - Cycle (directed to explored node), 3 - Extra (directed to visited node)
	int dfs_state[V], parent[V];
	vector<pair<int, int> > property[V];
	void add_property(int u, int v, int p){
		int len = property[u].size();
		for(int i = 0; i < len; i++)
			if(property[u][i].first == v){
				property[u][i].second = p;
				return;
			}
		property[u].push_back(pair<int, int>(v, p));
	}
	void GEPdfs(int u){
		dfs_state[u] = 0; //0 means explored node
		int len = G[u].size();
		for(int i = 0; i < len; i++){
			int v = G[u][i];
			if(dfs_state[v] == -1){
				parent[v] = u;
				property[u].push_back(pair<int, int>(v, 0));
				GEPdfs(v);
			}else if(dfs_state[v] == 0){
				if(parent[u] == v){
					add_property(u, v, 1);
					add_property(v, u, 1);
				}else{
					add_property(u, v, 2); //The edge that causes a cycle
				}
			}else if(dfs_state[v] == 1){ //1 means visited node
				add_property(u, v, 3); //May be cycle, may also be bidirectional, but definitely is an edge that visits an already visited node
			}
			dfs_state[u] = 1;
		}
	}
	//Graph Edges Property Execution
	void GEPCheck(){
		fill_n(dfs_state, V, -1);
		fill_n(parent, V, -1);
		for(int i = 0; i < V; i++)
			if(dfs_state[i] == -1)
				GEPdfs(i);
	}

	//Finding Articulation Points and Bridges
	//(Undirected Graph, Unweighted Graph)
	//Time Complexity: O(V + E)
	int dfs_least[V], dfsNumberCounter, rootChildren, dfsRoot;
	bool ap[V];
	vector<int> articulation_points;
	vector<pair<int, int> > articulation_bridges;
	void APBdfs(int u){
		dfs_least[u] = dfs_state[u] = dfsNumberCounter++;
		int len = G[u].size();
		for(int i = 0; i < len; i++){
			int v = G[u][i];
			if(dfs_state[v] == -1){
				parent[v] = u;
				if(u == dfsRoot) rootChildren++;
				APBdfs(v);
				if(dfs_least[v] >= dfs_state[u])
					ap[u] = true;
				if(dfs_least[v] > dfs_state[u])
					articulation_bridges.push_back(pair<int, int>(u, v));
				dfs_least[u] = min(dfs_least[u], dfs_least[v]);
			}else if(v != parent[u])
				dfs_least[u] = min(dfs_least[u], dfs_least[v]);
		}
	}
	//Articulation Points and Bridges Execution
	void APBSearch(){
		dfsNumberCounter = 0;
		fill_n(dfs_least, V, 0);
		fill_n(dfs_state, V, -1);
		fill_n(parent, V, -1);
		fill_n(ap, V, 0);
		for(int i = 0; i < V; i++)
			if(dfs_state[i] == -1){
				dfsRoot = i;
				rootChildren = 0;
				APBdfs(i);
				ap[i] = (rootChildren > 1);
			}
		for(int i = 0; i < V; i++)
			if(ap[i])
				articulation_points.push_back(i);
	}
};
int main(){
	//Enter code here
	int n, p;
	while(~scanf("%d%d", &n, &p) && n){
		UtilG<200> graph;
		int u, v;
		for(int i = 0; i < p; i++){
			scanf("%d%d", &u, &v);
			graph.add(u, v);
		}
		printf("%s\n", graph.BGCheck(0) ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
	return 0;
}