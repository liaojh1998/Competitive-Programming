//Title: Test the Rods
//Type: DP
//Complexity: O((T1+T2)*n*(site total))
//Solution: Kind of like the knapsack algorithm
//State: dp[i][j] represent minimum cost of having i tested at NCPC and j tested at BCEW, where j = total-i, base case dp[0][0] = 0 cost
//Transition: per site: dp[i+k][total-i + (site total-k)] = min(self, dp[i][total-i] + Cij1[k] + Cij2[site total-k])
//						where total = T1+T2, 0 <= (i+k) <= T1, 0 <= (total-i) + (site total-k) <= T2, 0 <= i <= total, 0 <= k <= site total
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
	int T1, T2;
	while(~readInt(T1) && ~readInt(T2) && (T1 + T2)){
		int n;
		readInt(n);
		int rec[T1+1][T2+1][2], dp[T1+1][T2+1], total = 0;
		memset(dp, 127, sizeof(dp));
		memset(rec, 0, sizeof(rec));
		dp[0][0] = 0;
		for(int i = 0; i < n; i++){
			int sizet;
			readInt(sizet);
			int Cij1[sizet+1], Cij2[sizet+1];
			Cij1[0] = Cij2[0] = 0;
			for(int j = 1; j <= sizet; j++)
				readInt(Cij1[j]);
			for(int j = 1; j <= sizet; j++)
				readInt(Cij2[j]);
			for(int j = 0; j <= sizet; j++)
				for(int k = 0; k <= total; k++)
					if((k+j) <= T1 && ((total-k) + (sizet-j)) <= T2 &&
						dp[k+j][total-k+sizet-j] > dp[k][total-k] + Cij1[j] + Cij2[sizet-j]){
						dp[k+j][total-k+sizet-j] = dp[k][total-k] + Cij1[j] + Cij2[sizet-j];
						rec[k+j][total-k+sizet-j][0] = k;
						rec[k+j][total-k+sizet-j][1] = total-k;
					}
			total += sizet;
		}
		printf("%d\n", dp[T1][T2]);
		int amount[n];
		for(int i = n-1; i >= 0; i--){
			amount[i] = T1-rec[T1][T2][0];
			int t1 = T1, t2 = T2;
			T1 = rec[t1][t2][0];
			T2 = rec[t1][t2][1];
		}
		for(int i = 0; i < n; i++)
			printf("%d%s", amount[i], i == n-1 ? "\n\n" : " ");
	}
	return 0;
}