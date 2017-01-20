/*
ID: liaojh11
PROG: nuggets
LANG: C++
*/
//Title: Beef McNuggets
//Type: DP
//Complexity: O(N*(M^2-2M))
//Solution: I don't know the proof, but according to USACO, the largest number a coprime cannot make is N*M - N - M, which is the product minus the sum.
		//	This is related to the gcd of coprimes ending at 1, in which the difference between all the later sums of coprimes will have a minimum difference of 1.
		//	Therefore, if numbers have gcd of more than 1, then the answer is out of bounds.
		//	The maximum is therefore 256*256-2*256 different states.
		//	This solution will be geared towards the above solution, which is inefficient but enough.
		//	The efficient solution include using a rotating boolean storage of possible sums, which ends when all 256 states are possible.
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

int gcd(int a, int b){
	while(b){
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
int main(){
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	bool dp[65025], impossible = false;
	memset(dp, 0, sizeof(dp));
	int N, gcdnum = 0;
	readInt(N);
	if(N == 1)
		impossible = true;
	int arr[N+5];
	for(int i = 0; i < N; i++){
		readInt(arr[i]);
		if(arr[i] == 1)
			impossible = true;
		gcdnum = gcd(gcdnum, arr[i]);
	}
	if(gcdnum > 1)
		impossible = true;
	if(impossible){
		printf("0\n");
		return 0;
	}
	dp[0] = true;
	for(int i = 0; i < N; i++)
		for(int j = arr[i]; j < 65025; j++)
			if(!dp[j] && dp[j-arr[i]])
				dp[j] = dp[j-arr[i]];
	int maxi = 0;
	for(int i = 1; i < 65025; i++)
		if(!dp[i])
			maxi = i;
	printf("%d\n", maxi);
	return 0;
}