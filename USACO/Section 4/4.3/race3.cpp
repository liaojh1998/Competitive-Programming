/*
ID: liaojh11
PROG: race3
LANG: C++
*/
//Title: Street Race
//Type: DFS
//Complexity: O(V*E)
//Solution: Enumerate all nodes for a dfs and see if removing it gets to the result, then dfs from node to see there's such a cycle that meets it again
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(!(~c)) return -1;
	if(c == '-') neg = true, c = getchar();
	if(c != '.'){
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
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
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	if(!(~c)) return -1;
	//32 if stop at space, 10 if stop at next line
	while(c != 10 && c != 32 && ~c){
		str[len++] = c;
		c = getchar();
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
void readIntArr(int *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readInt(n[i]))){
			n[i] = 0;
			return;
		}
}
void readLLArr(long long *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readLL(n[i]))){
			n[i] = 0;
			return;
		}
}
void readDoubleArr(double *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readDouble(n[i]))){
			n[i] = 0;
			return;
		}
}

vector<int> G[55];
bool vis[55][55], svis[55][55];
int size, questioned, upoints[55], spoints[55], upointsize, spointsize;
bool dfs(int node){
	if(node == size-1)
		return false;
	if(node == questioned)
		return true;
	int s = G[node].size();
	bool possible = true;
	for(int i = 0; i < s; i++)
		if(!vis[node][i]){
			vis[node][i] = true;
			possible &= dfs(G[node][i]);
		}
	return possible;
}
bool sdfs(int node){
	bool unsplit = true;
	int s = G[node].size();
	for(int i = 0; i < s; i++){
		if(G[node][i] != node && vis[node][i])
			return false;
		if(!svis[node][i]){
			svis[node][i] = true;
			unsplit &= sdfs(G[node][i]);
		}
	}
	return unsplit;
}
void solve(){
	int cur;
	while(readInt(cur) && ~cur){
		if(cur == -2){
			size++;
			continue;
		}
		G[size].push_back(cur);
	}
	for(int i = 1; i < size-1; i++){
		questioned = i;
		memset(vis, 0, sizeof(vis));
		memset(svis, 0, sizeof(svis));
		bool possible = dfs(0);
		if(possible){
			upoints[upointsize++] = i;
			bool split = sdfs(i);
			if(split)
				spoints[spointsize++] = i;
		}
	}
	printf("%d%s", upointsize, upointsize ? " " : "\n");
	for(int i = 0; i < upointsize; i++)
		printf("%d%s", upoints[i], i == upointsize-1 ? "\n" : " ");
	printf("%d%s", spointsize, spointsize ? " " : "\n");
	for(int i = 0; i < spointsize; i++)
		printf("%d%s", spoints[i], i == spointsize-1 ? "\n" : " ");
}
int main(){
	freopen("race3.in", "r", stdin);
	freopen("race3.out", "w", stdout);
	solve();
	return 0;
}