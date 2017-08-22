//Greedy af trees, time to be greedy af
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;
struct p{
	int from, to;
} pa;
queue<p> paths, re;
int n, node[100010], u, v, sum;
vector<int> edges[100010];
set<int> first[100010], second[100010];
void dfssecond(int to, int from){
	second[to].insert(node[to]);
	for(int i = 0; i < edges[to].size(); i++){
		if(edges[to][i] != from){
			set<int> temp;
			temp.insert(second[to].begin(), second[to].end());
			for(int j = 0; j < edges[to].size(); j++)
				if(i != j && edges[to][j] != from){
					temp.insert(first[edges[to][j]].begin(), first[edges[to][j]].end());
				}
			//printf("%d %d %d %d %d: ", edges[to][i], from, to, edges[to].size(), to);
			/*for(set<int>::iterator it = temp.begin(); it != temp.end(); it++)
				printf("%d ", *it);
			printf("\n");
			*/
			sum += temp.size()*first[edges[to][i]].size();
			second[edges[to][i]].insert(temp.begin(), temp.end());
			dfssecond(edges[to][i], to);
		}
	}
}
void dfsfirst(int to, int from){
	first[to].insert(node[to]);
	if(edges[to].size() == 1 && edges[to][0] == from){
		return;
	}
	for(int i = 0; i < edges[to].size(); i++)
		if(edges[to][i] != from){
			dfsfirst(edges[to][i], to);
			first[to].insert(first[edges[to][i]].begin(), first[edges[to][i]].end());
		}
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t c1 = clock();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &node[i]);
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		edges[v].push_back(u);
		edges[u].push_back(v);
	}
	//Start from the leaf
	for(int i = 1; i <= n && !pa.to; i++)
		if(edges[i].size() == 1){
			pa.to = i;
			paths.push(pa);
		}
	//First greedy dfs
	dfsfirst(pa.to, 0);
	/*
	while(!paths.empty()){
		pa = paths.front();
		paths.pop();
		if(edges[pa.to].size() == 1 && edges[pa.to][0] == pa.from){
			int temp = pa.from;
			pa.from = pa.to;
			pa.to = temp;
			re.push(pa);
			continue;
		}
		for(int i = 0; i < edges[pa.to].size(); i++){
			p next;
			next.to = edges[pa.to][i];
			next.from = pa.to;
			paths.push(next);
		}
	}*/
	clock_t c2 = clock();
	printf("%.3f\n", ((float)c2 - (float)c1)/CLOCKS_PER_SEC);
	/*
	for(int i = 1; i <= n; i++){
		printf("%d: ", i);
		for(set<int>::iterator it = first[i].begin(); it != first[i].end(); it++)
			printf("%d ", *it);
		printf("\n");
	}
	*/
	//Second greedy dfs
	dfssecond(pa.to, 0);
	printf("%d\n", sum);
	return 0;
}