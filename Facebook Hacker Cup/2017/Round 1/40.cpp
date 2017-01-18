//Title: Beach Umbrellas
//Type: Combinatorics
//Complexity: 
//Solution: 
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

#define MOD (1000000007)
long long nPr(long long n, int r){
	long long x = 1;
	for(int i = 0; i < r; i++)
		x = (x*(n+(long long)i))%MOD;
	return x;
}
long long power(long long a, long long b){
	//(a^b)%MOD
	long long x = 1, y = a;
	while(b > 0){
		if(b%2)
			x = (x*y)%MOD;
		y = (y*y)%MOD;
		b /= 2;
	}
	return x%MOD;
}
long long Mfact[1000000005];
int main(){
	freopen("40input.txt", "r", stdin);
	freopen("40output.txt", "w", stdout);
	long long fact[2005], mulinv[2005];
	fact[0] = 1;
	for(int i = 1; i <= 2000; i++)
		fact[i] = (i*fact[i-1])%MOD;
	mulinv[0] = mulinv[1] = 1;
	for(int i = 2; i <= 2000; i++)
		mulinv[i] = power(fact[i], MOD-2);
	int T;
	readInt(T);
	for(int index = 1; index <= T; index++){
		int N;
		readInt(N);
		long long M, sum = 0, arr[N+5];
		readLL(M);
		for(int i = 0; i < N; i++){
			readLL(arr[i]);
			sum += arr[i]*2;
		}
		if(N == 1){
			printf("Case #%d: %lld\n", index, M%MOD);
			continue;
		}
		long long ans = 0;
		for(int i = 0; i < N; i++){
			long long nfact[2005], space = M-(sum-arr[i]), start = 1;
			memset(nfact, 0, sizeof(nfact));
			if(space < 0)
				start = -space + 1;
			nfact[start] = nPr(space+start, N);
			for(int j = start+1; j <= 2000; j++)
				nfact[j] = (((nfact[j-1]*(space+j-1+N))%MOD)*power(space+j-1, MOD-2))%MOD;
			for(int j = i+1; j < N; j++)
				if(sum-arr[i]-arr[j] < M)
					ans = (ans + ((((fact[N-2]*mulinv[N])%MOD)*nfact[arr[j]])%MOD)*2)%MOD;
		}
		printf("Case #%d: %lld\n", index, ans);
	}
	return 0;
}