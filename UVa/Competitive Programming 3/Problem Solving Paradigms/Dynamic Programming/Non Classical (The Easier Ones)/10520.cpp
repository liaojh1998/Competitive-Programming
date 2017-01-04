//Title: Determine it
//Type: DP
//Complexity: O(n^3)
//Solution: Translate equation to recursive function and work it out from there
//State: dp[i][j] = a(i,j), base case dp[n][1] = a(n,1), which is given
//Transition: Follow the equation given
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

int n;
long long n1;
//Recursive function (dp bottom-up from j = 1 -> n with i = n -> 1)
/*long long a(int i, int j){
	long ans = 0;
	if(i == n && j == 1) return n1;
	if(i >= j){
		long long t1 = 0, t2 = 0;
		if(i != n)
			for(int k = i+1; k <= n; k++)
				t1 = max(t1, a(k, 1) + a(k, j));
		if(j != 0)
			for(int k = 1; k < j; k++)
				t2 = max(t2, a(i, k) + a(n, k));
		ans = t1 + t2;
	}else
		for(int k = i; k < j; k++)
			ans = max(ans, a(i, k) + a(k+1, j));
	printf("%d %d %lld\n", i, j, ans); //dp[i][j]
	return ans;
}*/
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~readInt(n)){
		readLL(n1);
		long long dp[n+1][n+1];
		memset(dp, 0, sizeof(dp));
		dp[n][1] = n1;
		for(int j = 1; j <= n; j++){
			for(int i = n; i >= 1; i--){
				if(i == n && j == 1) continue;
				if(i >= j){
					long long t1 = 0, t2 = 0;
					if(i != n)
						for(int k = i+1; k <= n; k++)
							if(dp[k][1] + dp[k][j] > t1)
								t1 = dp[k][1] + dp[k][j];
					if(j != 0) //Tbh j will never reach 0 so this is not needed
						for(int k = 1; k < j; k++)
							if(dp[i][k] + dp[n][k] > t2)
								t2 = dp[i][k] + dp[n][k];
					dp[i][j] = t1 + t2;
				}else
					for(int k = i; k < j; k++)
						if(dp[i][k] + dp[k+1][j] > dp[i][j])
							dp[i][j] = dp[i][k] + dp[k+1][j];
			}
		}
		//Call a(1, n) to see correct answer
		printf("%lld\n", dp[1][n]);
	}
	return 0;
}