/*
ID: liaojh11
PROG: fence6
LANG: C++
*/
//Title: Fence Loops
//Type: Shortest Path
//Complexity: O(N^3)
//Solution: Modify question into a shortest path problem
		//	After Floyd-Warshall's algorithm for 1 shortest path from i to j
		//	search for node k that was not in the shortest path from i to j
		//	and try to make a perimeter from the shortest path i to j to original paths of i to k and k to j
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

struct segment{
	int Ls, prevsize, nextsize, prev[10], next[10];
	bool prevhas[105], nexthas[105];
}seg[105];
int main(){
	freopen("fence6.in", "r", stdin);
	freopen("fence6.out", "w", stdout);
	int N, s;
	readInt(N);
	for(int i = 0; i < N; i++){
		readInt(s);
		memset(seg[s].prevhas, 0, sizeof(seg[s].prevhas));
		memset(seg[s].nexthas, 0, sizeof(seg[s].nexthas));
		readInt(seg[s].Ls);
		readInt(seg[s].prevsize);
		readInt(seg[s].nextsize);
		for(int j = 0; j < seg[s].prevsize; j++){
			readInt(seg[s].prev[j]);
			seg[s].prevhas[seg[s].prev[j]] = true;
		}
		for(int j = 0; j < seg[s].nextsize; j++){
			readInt(seg[s].next[j]);
			seg[s].nexthas[seg[s].next[j]] = true;
		}
	}
	int dp[105][105], sp[105][105], end1[105], end2[105], ans = 25500;
	bool vis[105];
	memset(vis, 0, sizeof(vis));
	memset(dp, 1, sizeof(dp));
	memset(end1, -1, sizeof(end1));
	memset(end2, -1, sizeof(end2));
	int nodecount = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < seg[i].prevsize; j++){
			if(seg[seg[i].prev[j]].prevhas[i] && ~end1[seg[i].prev[j]])
				end1[i] = end1[seg[i].prev[j]];
			else if(seg[seg[i].prev[j]].nexthas[i] && ~end2[seg[i].prev[j]])
				end1[i] = end2[seg[i].prev[j]];
		}
		for(int j = 0; j < seg[i].nextsize; j++){
			if(seg[seg[i].next[j]].nexthas[i] && ~end2[seg[i].next[j]])
				end2[i] = end2[seg[i].next[j]];
			else if(seg[seg[i].next[j]].prevhas[i] && ~end1[seg[i].next[j]])
				end2[i] = end1[seg[i].next[j]];
		}
		if(!(~end1[i]))
			end1[i] = nodecount++;
		if(!(~end2[i]))
			end2[i] = nodecount++;
		dp[end1[i]][end2[i]] = dp[end2[i]][end1[i]] = seg[i].Ls;
	}
	/*for(int i = 0; i < nodecount; i++)
		for(int j = 0; j < nodecount; j++)
			printf("%d%s", dp[i][j], j == nodecount-1 ? "\n" : " ");
	for(int i = 1; i <= N; i++)
		printf("%d ", end1[i]);
	printf("\n");
	for(int i = 1; i <= N; i++)
		printf("%d ", end2[i]);
	printf("\n");
	*/
	memcpy(sp, dp, sizeof(dp));
	for(int i = 0; i < nodecount; i++)
		sp[i][i] = 0;
	for(int k = 0; k < nodecount; k++){
		for(int i = 0; i < k; i++){
			for(int j = i+1; j < k; j++){
				if(ans > sp[i][j] + dp[i][k] + dp[k][j])
					ans = sp[i][j] + dp[i][k] + dp[k][j];
			}
		}
		for(int i = 0; i < nodecount; i++){
			for(int j = 0; j < nodecount; j++){
				if(sp[i][j] > sp[i][k] + sp[k][j])
					sp[i][j] = sp[i][k] + sp[k][j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}