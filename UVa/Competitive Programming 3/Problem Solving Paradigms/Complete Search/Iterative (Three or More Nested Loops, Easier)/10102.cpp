//Title: The path in the colored field
//Type: BFS
//Complexity: O(number of 1s present)
//Solution: BFS every 1 and the minimum number of steps required to reach any 3, take the max of that, confusing description
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
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
	if(!(~c)) return -1;
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
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

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N;
	int xdir[4] = {-1, 0, 1, 0};
	int ydir[4] = {0, 1, 0, -1};
	while(~readInt(N)){
		int mat[N+5][N+5];
		memset(mat, 0, sizeof(mat));
		queue<pair<int, int> > q;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				mat[i][j] = getchar()-'0';
				if(mat[i][j] == 1)
					q.push(pair<int, int>(i, j));
			}
			getchar();
		}
		int maxi = 0;
		while(!q.empty()){
			pair<int, int> t = q.front(); q.pop();
			int tmat[N+5][N+5];
			memset(tmat, 1, sizeof(tmat));
			tmat[t.first][t.second] = 0;
			queue<pair<int, int> > tq;
			tq.push(t);
			int temp = 0;
			while(!tq.empty()){
				pair<int, int> tc = tq.front(); tq.pop();
				for(int i = 0; i < 4; i++)
					if(tc.first+xdir[i] >= 1 && tc.first+xdir[i] <= N && tc.second+ydir[i] >= 1 && tc.second+ydir[i] <= N && tmat[tc.first+xdir[i]][tc.second+ydir[i]] > tmat[tc.first][tc.second] + 1){
						tmat[tc.first+xdir[i]][tc.second+ydir[i]] = tmat[tc.first][tc.second] + 1;
						if(mat[tc.first+xdir[i]][tc.second+ydir[i]] == 3){
							temp = tmat[tc.first+xdir[i]][tc.second+ydir[i]];
							break;
						}
						tq.push(pair<int, int>(tc.first+xdir[i], tc.second+ydir[i]));
					}
				if(temp)
					break;
			}
			if(maxi < temp)
				maxi = temp;
		}
		printf("%d\n", maxi);
	}
	return 0;
}