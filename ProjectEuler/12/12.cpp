//Title: Highly divisible triangular number
//Solution: Prime factorization after sieve, using properties of coprime which contain a distinct set of prime factors to generate count.
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

#define LIMIT (1000)
vector<long long> primes;
void sieve_eratostenes(){
	//Add 2 and 3 to base case
	primes.push_back(2);
	primes.push_back(3);
	//Sieve of Eratostenes
	//O(N*sqrt(N)), feasible for 10000000
	for(long long i = 5; i <= LIMIT; i+=2){
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
int prime_factorization(long long i){
	int count = 1, size = primes.size();
	while(i != 1){
		for(int j = 0; j < size && i != 1; j++){
			int exp = 1;
			while(!(i%primes[j])){
				i /= primes[j];
				exp++;
			}
			count *= exp;
		}
		if(i != 1)
			return count*2; // When i becomes prime bigger than 1000
	}
	return count;
}
int main(){
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	sieve_eratostenes();
	int T, N;
	readInt(T);
	while(T--){
		readInt(N);
		int odd = 1, even = 1;
		long long ans = 0;
		while(odd*even <= N){
			ans++;
			if((ans+1)%2)
				odd = prime_factorization(ans+1);
			else
				even = prime_factorization((ans+1)/2);
		}
		printf("%lld\n", ans*(ans+1)/2);
	}
	return 0;
}