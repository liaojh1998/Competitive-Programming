/*
ID: liaojh11
PROG: milk4
LANG: C++
*/
//Title: Milk Measuring
//Type: DP
//Complexity: O(Q*P)
//Solution: Began with the DP, failed due to a non-optimal solution in DP part, decided to do IDS, found it inefficient. Using official USACO DP solution.
//State: dp[i] = minimum pails required at i quarts, using a temporary dp to keep track of non-optimal solutions in case of later optimal,
//Transition: dp[i] = min(tempdp[i], dp[i]), tempdp[i] = min(tempdp[prev] + 1 if diff pail as previous, + 0 if same pail as previous, dp[prev] + 1 if previous is optimal and different pail)
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

#define INF (20005)
bool judge(int Q1, int Q2, int* last, int* amount){
	while(Q1 && Q2){
		if(last[Q1] != last[Q2])
			return (last[Q1] < last[Q2]);
		Q1 -= last[Q1]*amount[Q1];
		Q2 -= last[Q2]*amount[Q2];
	}
	return !Q1;
}
void solvedp(int Q, int P, int* arr, int* dp, int* amount, int* last){
	fill_n(dp, Q+5, INF);
	dp[0] = 0;
	for(int i = 0; i < P; i++){
		int tempdp[Q+5], tempamount[Q+5], templast[Q+5];
		memcpy(tempdp, dp, sizeof(int)*(Q+5));
		memcpy(tempamount, amount, sizeof(int)*(Q+5));
		memcpy(templast, last, sizeof(int)*(Q+5));
		for(int j = arr[i]; j <= Q; j++){
			int prev = j - arr[i];
			if(tempdp[prev] < INF){
				if(templast[prev] == arr[i]){
					templast[j] = arr[i];
					tempamount[j] = tempamount[prev]+1;
					tempdp[j] = tempdp[prev];
				}
				if(templast[prev] != arr[i]){
					templast[j] = arr[i];
					tempamount[j] = 1;
					tempdp[j] = tempdp[prev]+1;
				}
				if(dp[prev] < INF && (dp[prev]+1 < tempdp[j] || (dp[prev]+1 == tempdp[j] && judge(prev, j-arr[i]*tempamount[j], last, amount)))){
					templast[j] = arr[i];
					tempamount[j] = 1;
					tempdp[j] = dp[prev]+1;
				}
			}
			if(tempdp[j] <= dp[j]){
				dp[j] = tempdp[j];
				last[j] = templast[j];
				amount[j] = tempamount[j];
			}
		}
	}
}
void recur(int* ans, int Q, int size, int* amount, int* last){
	for(int i = 0; i < size; i++){
		ans[i] = last[Q];
		Q -= amount[Q]*last[Q];
	}
}
void solve(){
	freopen("milk4.in", "r", stdin);
	freopen("milk4.out", "w", stdout);
	int Q, P;
	readInt(Q);
	readInt(P);
	int arr[P+5], dp[Q+5], amount[Q+5], last[Q+5];
	for(int i = 0; i < P; i++)
		readInt(arr[i]);
	sort(arr, arr+P, greater<int>()); //Sorted in descending order for bottom-up dp
	solvedp(Q, P, arr, dp, amount, last);
	int ans[Q+5], size = dp[Q];
	recur(ans, Q, dp[Q], amount, last);
	printf("%d", size);
	for(int i = 0; i < size; i++)
		printf(" %d", ans[i]);
	printf("\n");
}
int main(){
	solve();
	return 0;
}