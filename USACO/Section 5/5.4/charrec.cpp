/*
ID: liaojh11
PROG: charrec
LANG: C++
*/
//Title: Character Recognition
//Type: DP
//Complexity: O(540 + 540*N*20 + 540*N + N)
//Solution: First step read reach diagram. DP out the differences for each letter i diagram line j with line k of the given graph. Simulate the minimal difference DP of all diagrams of each line where we have 1 deleted, or nothing changed, or 1 duplicate line.
		//	Then simply DP the last step of search the smallest string of letters that has the smallest differences.
		//	Source of solution mainly from nocow. It is possible to do top-down DP instead of wasting space and time with this bottom-up DP.
//State: diff[i][j][k] = using letter i and the difference of its j line with respect to k line of whole graph. letterdiff[i][j] = minimum difference at line i using either 1 letter with 1 less line, 1 whole letter, or 1 letter with 1 duplicate line (19, 20, or 21 lines basically),
		//	dp[i] = minimum achievable difference at line i.
//Transition: diff[i][j][k] += (graph[k][l] != letter[i][j][l]), letterdiff[k][0] = min(sum(diff[i][j][0 -> k-1]) + sum(diff[i][j][k -> 20])), letterdiff[k][1] = min(sum(diff[i][j][0 -> 20])), letterdiff[k][2] = min(sum(diff[i][j][0 -> k]) + sum(diff[i][j][k -> 20]));
		//	dp[0] = 0, dp[i] = min(dp[i-19] + letterdiff[i][0], dp[i-20] + letterdiff[i][1], dp[i-21] + letterdiff[i][2]);
		//	backtrack from dp[N] till dp[0]
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

char getLetter(int i){
	if(!i)
		return ' ';
	if(i > 0 && i < 27)
		return i + 96;
	return '?';
}
int data[1205][25], diff[30][25][1205], letterdiff[1205][5], letter[1205][5];
void solve(){
	int fontlen, fonts[30][25][25];
	freopen("font.in", "r", stdin);
	readInt(fontlen);
	for(int i = 0; i < 27; i++)
		for(int j = 0; j < 20; j++){
			for(int k = 0; k < 20; k++)
				fonts[i][j][k] = getchar()-'0';
			getchar();
		}
	freopen("charrec.in", "r", stdin);
	freopen("charrec.out", "w", stdout);
	int N;
	readInt(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 20; j++)
			data[i][j] = getchar()-'0';
		getchar();
	}
	for(int i = 0; i < 27; i++)
		for(int j = 0; j < 20; j++)
			for(int k = 0; k < N; k++)
				for(int l = 0; l < 20; l++)
					if(data[k][l] != fonts[i][j][l])
						diff[i][j][k]++;
	memset(letter, 1, sizeof(letter));
	for(int j = 0; j < N-18; j++){
		letterdiff[j][0] = letterdiff[j][1] = letterdiff[j][2] = 425;
		for(int i = 0; i < 27; i++){
			//0 - 19
			if(j < N-18){
				int total = 0;
				for(int k = 1; k < 20; k++)
					total += diff[i][k][j+k-1];
				if(total < letterdiff[j][0]){
					letterdiff[j][0] = total;
					letter[j][0] = letterdiff[j][0] <= 120 ? i : 27;
				}
				for(int k = 1; k < 20; k++){
					total -= diff[i][k][j+k-1];
					total += diff[i][k-1][j+k-1];
					if(total < letterdiff[j][0]){
						letterdiff[j][0] = total;
						letter[j][0] = i;
					}
				}
			}
			//1 - 20
			if(j < N-19){
				int total = 0;
				for(int k = 0; k < 20; k++)
					total += diff[i][k][j+k];
				if(total < letterdiff[j][1]){
					letterdiff[j][1] = total;
					letter[j][1] = letterdiff[j][1] <= 120 ? i : 27;
				}
			}
			//2 - 20
			if(j < N-20){
				int total = diff[i][0][j];
				for(int k = 0; k < 20; k++)
					total += diff[i][k][j+k+1];
				if(total < letterdiff[j][2]){
					letterdiff[j][2] = total;
					letter[j][2] = i;
				}
				for(int k = 1; k < 20; k++){
					total -= diff[i][k-1][j+k];
					total += diff[i][k][j+k];
					if(total < letterdiff[j][2]){
						letterdiff[j][2] = total;
						letter[j][2] = letterdiff[j][2] <= 120 ? i : 27;
					}
				}
			}
		}
	}
	int dp[N+5], skipped[N+5];
	memset(dp, 2, sizeof(dp));
	dp[0] = 0;
	for(int i = 19; i <= N; i++){
		if(dp[i-19] + letterdiff[i-19][0] < dp[i]){
			dp[i] = dp[i-19] + letterdiff[i-19][0];
			skipped[i] = 19;
		}
		if(i >= 20 && dp[i-20] + letterdiff[i-20][1] < dp[i]){
			dp[i] = dp[i-20] + letterdiff[i-20][1];
			skipped[i] = 20;
		}
		if(i >= 21 && dp[i-21] + letterdiff[i-21][2] < dp[i]){
			dp[i] = dp[i-21] + letterdiff[i-21][2];
			skipped[i] = 21;
		}
	}
	char ans[(N/20)+5], i = 0;
	for(int start = N; start > 0; start -= skipped[start], i++)
		ans[i] = getLetter(letter[start-skipped[start]][skipped[start]-19]);
	for(i--; i >= 0; i--)
		printf("%c", ans[i]);
	printf("\n");
}
int main(){
	solve();
	return 0;
}