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

#define INF (100005)
int dp[100005][2][2], parent[100005];
vector<int> edges[100005];

int f(const int& u, bool has, bool phas, bool gphas){
	int ans = 0, size = edges[u].size(), v;
	//Base case: Leaves must have a grandparent or parent with a coin, and leaves must have a coin
	//Proof: if a leaf doesn't have a coin on it, then it requires at least 3 steps to move two coins on it, 1 step from the parent and 2 steps from the grandparent
	//Lemma: a leaf has no other source of getting coins other than it's parent or grandparent
	if(size == 1 && parent[u] != -1)
		if(has && (gphas || phas))
			return 1;
		else
			return INF;
	//Case: current state has already been checked
	if(dp[u][has][phas]) return dp[u][has][phas];
	//Case: current state has not been checked
	if(has){
		//Has coin scenario:
		//Since there's a coin on the current node, then it is required that either the node's child, grandchild, grandparent, or parent have a coin
		for(int i = 0; i < size; i++){
			v = edges[u][i];
			if(v != parent[u]){
				parent[v] = u;
				//It is guaranteed through cases prevented by 'not have coin' scenario that current state must have either a grandchild or a child with a coin,
				//which means worry not about whether or not parent or grandparent has a coin
				ans += min(f(v, true, has, phas), f(v, false, has, phas));
			}
		}
		ans += 1;
	}else{
		//Does not have coin scenario:
		//Since there is no coin on the current node, then it is required that either the node's parent and one of it's children have a coin, or two of it's children have a coin
		//This basically guarantee that the parent must have a grandchild
		if((phas && size < (1 + (parent[u] != -1))) || (!phas && size < (2 + (parent[u] != -1))))
			//Test for impossible first: cannot have a child and parent with 2 coins or cannot have two children with 2 coins
			ans = INF;
		else{
			int h, nh, count = 0, diff, first = INF, second = INF;
			for(int i = 0; i < size; i++){
				v = edges[u][i];
				if(v != parent[u]){
					parent[v] = u;
					nh = f(v, false, has, phas);
					h = f(v, true, has, phas);
					if(h <= nh){
						count++;
						ans += h;
					}else{
						ans += nh;
						diff = h - nh;
						if(diff < first){
							second = first;
							first = diff;
						}else if(diff < second)
							second = diff;
					}
				}
			}
			if(phas){
				//If have a parent with a coin, then node must have at least 1 child with a coin
				if(count == 0)
					ans += first;
			}else{
				//If have a parent without a coin, then node must have at least 2 children with a coin
				if(count == 0)
					ans += first+second;
				else if(count == 1)
					ans += first;
			}
		}
	}
	return (dp[u][has][phas] = (ans < INF ? ans : INF));
}

void FastIO::solve(){
	int T, N, u, v, ans;
	readInt(T);
	while(T--){
		readInt(N);
		for(int i = 0; i < N-1; i++){
			readInt(u);
			readInt(v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		parent[1] = -1;
		if(N > 1)
			ans = min(f(1, false, false, false), f(1, true, false, false));
		else //Of course, there is no way of putting two coins on a node when there is only 1 node
			ans = INF;
		printf("%d\n", ans == INF ? -1 : ans);
		for(int i = 1; i <= N; i++)
			edges[i].clear();
		memset(dp, 0, sizeof(dp));
		memset(parent, 0, sizeof(parent));
	}
}