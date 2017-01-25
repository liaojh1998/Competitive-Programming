/*
ID: liaojh11
PROG: buylow
LANG: C++
*/
//Title: Buy Low, Buy Lower
//Type: DP
//Complexity: O(N^2)
//Solution: LDS is not the difficult problem, the problem is in permutations, which requires high precision integers
		//	which enforces an O(N^2) to keep an 1D array instead of the simpler O(Nlogk) which requires a 2D array.
		//	For the sake of no repetitions, simply create a next array for identical integers, where the first identical point to the next identical index and if
		//	there exist such an integer less than both and is at an index later than both, or next[j] > j && next[j] < i, continue and do not add the permuted amount.
		//	This is correct because the previous integer > arr[i] will have an amount <= later integer > arr[i], hence the latter is the one to take.
//State: dp[i] = maximum LDS as number i as the end
//Transition: dp[i] = (arr[j] > arr[i]) ? max(dp[j]+1, dp[i]), 0 <= j < i;
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

#define BASE 1000000000
struct bignum{
	long long arr[8];
	int size;
	bignum(){
		arr[0] = 0;
		size = 0;
	}
	void operator=(long long i){
		arr[0] = i;
		size++;
	}
	void operator=(bignum &b){
		memcpy(arr, b.arr, sizeof(b.arr));
		size = b.size;
	}
	void operator+=(bignum &b){
		int tsize = size > b.size ? size : b.size;
		long long carry = 0, cur = 0;
		for(int i = 0; i < tsize; i++){
			if(i >= size) arr[i] = 0;
			if(i >= b.size) b.arr[i] = 0;
			cur = arr[i] + b.arr[i] + carry;
			carry = cur/BASE;
			arr[i] = cur%BASE;
		}
		size = tsize;
		if(carry)
			arr[size++] = carry;
	}
	void print(){
		for(int i = size-1; i >= 0; i--){
			long long k = BASE/10;
			if(i != size-1 && arr[i] < k)
				while(arr[i] < k){
					printf("0");
					k /= 10;
				}
			if(arr[i])
				printf("%lld", arr[i]);
		}
	}
};
int main(){
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);
	int N;
	readInt(N);
	bignum amount[N+5];
	int arr[N+5], dp[N+5], next[N+5], maxlds = 0;
	memset(arr, 0, sizeof(dp));
	memset(dp, 0, sizeof(dp));
	memset(next, 0, sizeof(next));
	for(int i = 0; i < N; i++)
		readInt(arr[i]);
	for(int i = 0; i < N-1; i++)
		for(int j = i+1; j < N && !next[i]; j++)
			if(arr[i] == arr[j])
				next[i] = j;
	amount[0] = 1;
	maxlds = dp[0] = 1;
	for(int i = 1; i < N; i++){
		dp[i] = 1;
		amount[i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[i]){
				if(next[j] && next[j] < i) continue;
				if(dp[j]+1 > dp[i]){
					dp[i] = dp[j]+1;
					amount[i] = amount[j];
				}else if(dp[j]+1 == dp[i])
					amount[i] += amount[j];
			}
		}
		if(dp[i] > maxlds)
			maxlds = dp[i];
	}
	bignum sum;
	for(int i = 0; i < N; i++)
		if(dp[i] == maxlds){
			if(i < next[i]) continue;
			sum += amount[i];
		}
	printf("%d ", maxlds);
	sum.print();
	printf("\n");
	return 0;
}