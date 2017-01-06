//Title: Simple Minded Hashing
//Type: DP
//Complexity: O(26^3*351) or O((letters in alphabet)^3 * (sum of all hashed alphabets)), (26+1)*26/2 = 351
//Solution: Keep track of last character, similar to 10910, thus:
//State: dp[i][j][k] = possible combinations with i letters and sum j which ends with letter k, answer is added to total[i][j] eventually, base case dp[1][i][i] = 1, 1 <= i <= 26
//Transition: dp[i][j][k] = sum(dp[i-1][j-k][l]), where 1 <= i <= 26 (must ascend so no more than 26 lettered strings)
		//	(i+1)*i/2 (minimum sequence sum, like abc = 6) <= j <= 351-(26-i)*(26-i+1)/2 (maximum sequence sum, like xyz = 75)
		//	i <= k <= 26 (sequence limits k, for example, L = 4 goes from d -> z, thus 4 -> 26)
		//	k-1 >= l >= 1 (letters lower than k, basically)
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
	int dp[30][355][30], total[30][355];
	memset(dp, 0, sizeof(dp));
	memset(total, 0, sizeof(total));
	for(int i = 1; i <= 26; i++)
		dp[1][i][i] = total[1][i] = 1;
	for(int i = 2; i <= 26; i++)
		for(int j = (i+1)*i/2; j <= 351 - (26-i)*(26-i+1)/2; j++)
			for(int k = i; k <= 26 && j-k >= 1; k++){ //Better optimization include corresponding k with j, but I'm lazy to come up with the equation
				for(int l = k-1; l >= 1; l--){
					//printf("%d %d %d += %d %d %d = %d\n", i, j, k, i-1, j-k, l, dp[i-1][j-k][l]);
					dp[i][j][k] += dp[i-1][j-k][l];
				}
				total[i][j] += dp[i][j][k];
			}
	int L, S, index = 1;
	while(readInt(L) && readInt(S) && (L+S)){
		if(L > 26 || S > 351){
			printf("Case %d: 0\n", index++);
			continue;
		}
		printf("Case %d: %d\n", index++, total[L][S]);
	}
	return 0;
}