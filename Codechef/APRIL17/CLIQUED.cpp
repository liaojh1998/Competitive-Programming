#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
	//inline if read speed is needed, huge compilation time required though
	//safe no fread implementation
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
	int readLL(long long &n){
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
	int readDouble(double &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
	}
		double div = 1;
		for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
		n /= div;
		if(neg) n = -n;
		return 1;
	}
	int readStr(char *str){
		register char c = getchar();
		register int len = 0;
		if(!(~c)) return -1;
		while(c < 33 && ~c) c = getchar(); //32 if space should be included
		//32 if stop at space, 10 if stop at next line
		while(c != 10 && c != 32 && ~c){
			str[len] = c;
			c = getchar();
			len++;
		}
		str[len] = '\0';
		//Just in case if needs to return arriving at end of line
		//if(c == 10) return 10;
		return 1;
	}
	int readStr(char *str, int len){
		//Reading string of size len
		for(int i = 0; i < len; i++){
			str[i] = getchar();
			if(!(~str[i])){
				str[i] = '\0';
				return -1;
			}
			//Remove this if str can't go to next line
			/*if(str[i] == 10){
				str[i] = '\0';
				return 10;
			}*/
		}
		str[len] = '\0';
		return 1;
	}

public:
	//Constructor, true if using file input/output, defaulted false
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

/* Subtasks comments:

#1:
To pass the 45 points test cases, realize that this is simply a shortest path problem.
Input all M + K*(K-1) edges and Dijkstra with priority queue or SPFA, the algorithm will run in O((N + M + K*(K-1))*log(N)) time.

#2:
To pass the rest 55 points test cases, observe the crucial properties of a clique: all paths from 1 to K are super strongly connected.
Starting from S and find the shortest paths using Dijkstra or SPFA, running O((N + M)*log(N))
Since we're guaranteed that entire graph is connected, S must have a shortest path to clique such that S can connect to rest of the clique and rest of the graph!
To avoid using K*(K-1) edges, we observe that the shortest path from S to every node must have a distance of:
Let shortPath denote the shortest path from S to any node in the clique:
shortestPath(S, n in 1 to K) <= shortPath + M;
S may either be in the clique, giving a shortPath of 0, or out of the clique, giving a shortPath > 0.
This gives a linear O(K) algorithm to calculate the shortest path from S to all nodes in the clique, avoiding K*(K-1).
Now that S has connected to the rest of the clique, it may or may not have connected to the rest of the graph.
However, we know that all shortest path between S and clique has been solved, and since the graph is strongly connected to the entire clique and S, we can find the shortest path of everywhere else with Dijkstra or SPFA from every node in the clique.
Since there can only exist 1 shortest path from S to N where N is outside of K, and can only have some leftover M edges that has not been relaxed in the first shortest path algorithm, the runtime of the second algorithm is O((K + M)*log(N - K)).

Thus, the runtime complexity of the entire algorithm can be roughly reduced to: O(K + (N + M)*log(N)), where each N - K and K will be checked once with log(N), yielding N - K + K = N.

*/

void FastIO::solve(){
	int T, N, K, M, S, u, v;
	long long X, w;
	readInt(T);
	while(T--){
		readInt(N);
		readInt(K);
		readLL(X);
		readInt(M);
		readInt(S);
		//Variables
		bool queued[N+5];
		long long dist[N+5];
		vector<pair<long long, int> > G[N+5];
		deque<int> q;
		fill_n(dist, N+1, 1e14);
		memset(queued, 0, sizeof(queued));
		//Read Edges
		for(int i = 0; i < M; i++){
			readInt(u);
			readInt(v);
			readLL(w);
			if(u > K || v > K || w < X){
				G[u].push_back(pair<long long, int>(w, v));
				G[v].push_back(pair<long long, int>(w, u));
			}
		}
		//Step 1: Relax all edges related to S, since we're guaranteed that the graph strongly connected, S must have an edge to any nodes of the clique K, including that S may be a part of K itself
		dist[S] = 0;
		q.push_front(S);
		//SPFA
		while(!q.empty()){
			u = q.front(); q.pop_front();
			queued[u] = false;
			size_t len = G[u].size();
			for(int i = 0; i < len; i++){
				w = G[u][i].first;
				v = G[u][i].second;
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					if(!queued[v]){
						queued[v] = true;
						if(!q.empty() && dist[v] < dist[q.front()])
							q.push_front(v);
						else
							q.push_back(v);
					}
				}
			}
		}
		//Step 2: S to all clique must have a distance either less or equal to X + shortest distance S can reach K
		long long shortDist = 1e14;
		for(int i = 1; i <= K; i++)
			if(dist[i] < shortDist)
				shortDist = dist[i];
		for(int i = 1; i <= K; i++)
			if(dist[i] > shortDist + X)
				dist[i] = shortDist + X;
		//Step 3: Enqueue clique to find the rest of the shortest paths
		for(int i = 1; i <= K; i++)
			q.push_back(i);
		sort(q.begin(), q.end());
		//SPFA
		while(!q.empty()){
			u = q.front(); q.pop_front();
			queued[u] = false;
			size_t len = G[u].size();
			for(int i = 0; i < len; i++){
				w = G[u][i].first;
				v = G[u][i].second;
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					if(!queued[v]){
						queued[v] = true;
						if(!q.empty() && dist[v] < dist[q.front()])
							q.push_front(v);
						else
							q.push_back(v);
					}
				}
			}
		}
		//Print
		for(int i = 1; i <= N; i++)
			printf("%lld%s", dist[i], (i == N) ? "\n" : " ");
	}
}