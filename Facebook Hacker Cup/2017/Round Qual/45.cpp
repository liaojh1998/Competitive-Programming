//Title: Fighting the Zombie
//Type: DP
//Complexity: O(Y^3*X^2)
//Solution: Let Dn = number of dice, D = faces of die, S = sum, P = probability function of hitting sum S with Dn dice with D faces
		//	Recursive function for P is P(D, S, Dn) = sum(P(D, S - i, Dn-1)/D, 1 <= i <= D);
//State: dp[i][j][k] = P(D, S, Dn), total[i][j][k] = sum(dp[i][l][k], j <= l <= Dn*D), base case dp[i][0][0] = 1
//Transition: dp[i][j][k] = sum(dp[i][j-l][k-1], 1 <= j-l <= i*k), 1 <= i <= D, i*D >= j >= 1, 1 <= k <= D;
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
	//Required for this problem
	if(c == '-') return '-';
	if(c == '+') return '+';
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

double dp[25][20005][25];
double total[25][20005][25];
int main(){
	freopen("45input.txt", "r", stdin);
	freopen("45output.txt", "w", stdout);
	for(int dicenum = 1; dicenum <= 20; dicenum++){ //Dice number
		dp[dicenum][0][0] = 1;
		for(int j = 1; j <= 20; j++) //Number of dice
			for(int i = dicenum*j; i >= 1; i--){ //Sum
				for(int k = 1; k <= dicenum; k++)
					if(i-k > 0 || (j-1 == 0 && i-k == 0))
						dp[dicenum][i][j] += dp[dicenum][i-k][j-1]/(double)dicenum;
				total[dicenum][i][j] = dp[dicenum][i][j] + total[dicenum][i+1][j];
			}
	}
	int T, S, N, D, Dn, Z, tempS;
	readInt(T);
	for(int index = 1; index <= T; index++){
		readInt(S);
		readInt(N);
		double maxprob = 0;
		for(int i = 0; i < N; i++){
			readInt(Dn);
			char c = readInt(D);
			switch(c){
				case '+':
					readInt(Z);
					tempS = S - Z; break;
				case '-':
					readInt(Z);
					tempS = S + Z; break;
				default: tempS = S; break;
			}
			if(tempS <= 0) tempS = 1;
			//printf("%.6lf\n", total[D][tempS][Dn]);
			if(total[D][tempS][Dn] > maxprob)
				maxprob = total[D][tempS][Dn];
		}
		printf("Case #%d: %.6lf\n", index, maxprob);
	}
	return 0;
}