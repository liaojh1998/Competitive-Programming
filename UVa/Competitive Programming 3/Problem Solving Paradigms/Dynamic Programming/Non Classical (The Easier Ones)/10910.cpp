//Title: Marks Distribution
//Type: DP
//Complexity: O(N*T*P)
//Solution: Presenting example dp[3][3][0], where N = 3, T = 3, P = 0, or 3 subjects with total test score of 3 requiring minimum of 0 to pass:
		//	from dp[2][0][0] --> 0 0 | 3
		//	from dp[2][1][0] --> 0 1 | 2
		//						 1 0 | 2
		//	from dp[2][2][0] --> 0 2 | 1
		//						 1 1 | 1
		//						 2 0 | 1
		//	from dp[2][3][0] --> 0 3 | 0
		//						 1 2 | 0
		//						 2 1 | 0
		//						 3 0 | 0
		//	Giving dp[3][3][0] = 10
		//	Basically combinatorics from previous subjects, thus state:
//State: dp[i][j][k] = total different solutions in passing i subjects with j total score and minimum of k to pass, base case dp[0][0] = all 0 subjects have 1 solution to pass it
//Transition: dp[i][j][k] = sum(dp[i-1][l][k], (i-1)*k <= l <= j-k);
		//	(i-1)*k because there are only solutions when j/(i-1) >= k, for example, total score of 3 over 3 subjects with a minimum of 2 to pass for each subject will have no solutions
		//	j-k limits final column of scores, as shown in example above, to states where other subjects will have at least a minimum of k to pass
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
	int dp[75][75][75];
	memset(dp, 0, sizeof(dp));
	fill_n(dp[0][0], 75, 1);
	for(int i = 1; i <= 70; i++)
		for(int j = 0; j <= 70; j++)
			for(int k = 0; k <= 70; k++)
				for(int l = (i-1)*k; l <= j-k; l++)
					dp[i][j][k]+= dp[i-1][l][k];
	int C, N, T, P;
	readInt(C);
	while(C--){
		readInt(N);
		readInt(T);
		readInt(P);
		printf("%d\n", dp[N][T][P]); //tbh, only long long will fit all solution but problem only required int
	}
	return 0;
}