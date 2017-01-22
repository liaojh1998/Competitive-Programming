//Title: 10001st prime
//Solution: Sieve of Eratostenes, or Sieve of Atkins
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

#define LIMIT (200000)
vector<int> primes;
void sieve_atkins(){
	//Add primes 2, 3
	primes.push_back(2);
	primes.push_back(3);
	//The Sieve of Atkin
	int list[LIMIT + 1];
	memset(list, 0, sizeof(list));
	for(int x = 1; x <= (int)sqrt(LIMIT); x++)
		for(int y = 1; y <= (int)sqrt(LIMIT); y++){
			int n = 4*x*x+y*y;
			if(n <= LIMIT && (n%12 == 1 || n%12 == 5))
				list[n] = ~list[n];
			n = 3*x*x+y*y;
			if(n <= LIMIT && n%12 == 7)
				list[n] = ~list[n];
			n = 3*x*x-y*y;
			if(x > y && n <= LIMIT && n%12 == 11)
				list[n] = ~list[n];
		}
	for(int i = 5; i <= sqrt(LIMIT); i++)
		if(list[i]){
			primes.push_back(i);
			int j = 1;
			int k = j++*i*i;
			while(k <= LIMIT){
				list[k] = 0;
				k = j++*i*i;
			}
		}
	for(int i = sqrt(LIMIT); i <= LIMIT; i++)
		if(list[i])
			primes.push_back(i);
}
void sieve_eratostenes(){
	//Add 2 and 3 to base case
	primes.push_back(2);
	primes.push_back(3);
	//Sieve of Eratostenes
	//O(N*sqrt(N)), feasible for 10000000
	for(int i = 5; i <= LIMIT; i++){
		bool prime = true;
		int size = primes.size();
		for(int j = 0; j < size && primes[j]*primes[j] <= i; j++)
			if(!(i%primes[j])){
				prime = false;
				break;
			}
		if(prime)
			primes.push_back(i);
	}
}
int main(){
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	//sieve_eratostenes();
	sieve_atkins();
	int T, N;
	readInt(T);
	while(T--){
		readInt(N);
		printf("%d\n", primes[N-1]);
	}
	return 0;
}