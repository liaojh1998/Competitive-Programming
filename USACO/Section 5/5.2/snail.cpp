/*
ID: liaojh11
PROG: snail
LANG: C++
*/
//Title: Snail Trails
//Type: DFS/Simulation
//Complexity: O(<2^200)
//Solution: Directly simulate the process knowing that DFS will go no further than 120^2 steps even when having 200 barriers.
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

int G[125][125];
int dfs(int row, int col, int vert, int N){
	int moves = 0;
	if(vert && G[row-1][col] && G[row+1][col])
		return 0;
	if(!vert && G[row][col-1] && G[row][col+1])
		return 0;
	if(vert){
		int i, down = 0, up = 0;
		//down
		if(row != N){
			for(i = 1; !G[i+row][col] && ~G[i+row][col]; i++)
				G[row+i][col] = -1;
			down += (i-1);
			if(G[i+row][col] > 0)
				down += dfs(row+i-1, col, 0, N);
			for(i--; i >= 1; i--)
				G[row+i][col] = 0;
		}
		//Up
		if(row != 1){
			for(i = 1; !G[row-i][col] && ~G[row-i][col]; i++)
				G[row-i][col] = -1;
			up += (i-1);
			if(G[row-i][col] > 0)
				up += dfs(row-(i-1), col, 0, N);
			for(i--; i >= 1; i--)
				G[row-i][col] = 0;
		}
		moves = max(down, up);
	}else{
		int i, right = 0, left = 0;
		//right
		if(col != N){
			for(i = 1; !G[row][col+i] && ~G[row][col+i]; i++)
				G[row][col+i] = -1;
			right += (i-1);
			if(G[row][col+i] > 0)
				right += dfs(row, col+i-1, 1, N);
			for(i--; i >= 1; i--)
				G[row][col+i] = 0;
		}
		//left
		if(col != 1){
			for(i = 1; !G[row][col-i] && ~G[row][col-i]; i++)
				G[row][col-i] = -1;
			left += (i-1);
			if(G[row][col-i] > 0)
				left += dfs(row, col-(i-1), 1, N);
			for(i--; i >= 1; i--)
				G[row][col-i] = 0;
		}
		moves = max(right, left);
	}
	return moves;
}
void solve(){
	freopen("snail.in", "r", stdin);
	freopen("snail.out", "w", stdout);
	int N, B, col, row;
	readInt(N);
	readInt(B);
	for(int i = 0; i <= N+1; i++){
		G[0][i] = 1;
		G[i][0] = 1;
		G[N+1][i] = 1;
		G[i][N+1] = 1;
	}
	for(int i = 0; i < B; i++){
		col = getchar()-'A' + 1;
		readInt(row);
		G[row][col] = 1;
	}
	G[1][1] = -1;
	int ans = max(dfs(1, 1, 1, N), dfs(1, 1, 0, N)) + 1;
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}