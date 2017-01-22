//Title: Summation of primes
//Solution: Sieve of Eratostenes works best here
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

#define LIMIT (2000000)
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
int main(){
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	sieve_eratostenes();
	long long summed[primes.size()+5];
	summed[0] = primes[0];
	int size = primes.size();
	for(int i = 1; i < size; i++)
		summed[i] = summed[i-1] + primes[i];
	int T;
	long long N;
	readInt(T);
	while(T--){
		readLL(N);
		int lo = 0, hi = size-1;
		while(lo < hi){
			int mid = (lo+hi)/2;
			if(primes[mid] < N)
				lo = mid+1;
			else
				hi = mid;
		}
		printf("%lld\n", primes[lo] > N ? summed[lo-1] : summed[lo]);
	}
	return 0;
}