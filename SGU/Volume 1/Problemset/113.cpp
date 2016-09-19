//Title: Nearly prime numbers
//Type: Math
//Solution: Primality test algorithm + Sieve of Atkin algorithm (to generate primes lolz, tbh Eratostenes works just fine)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define LIMIT (100000) //sqrt(1000000000)
using namespace std;
vector<int> primes;
void sieve(){
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
//Primality Test
bool isPrime(int N){
	if(N <= 1) return false;
	else if(N <= 3) return true;
	else if(!(N%2) || !(N%3)) return false;
	for(int i = 5; i*i <= N; i+= 6){
		if(!(N%i) || !(N%(i+2)))
			return false;
	}
	return true;
}
int main(){
	//Instantiation
	int N;
	scanf("%d", &N);
	sieve();
	//Nearly prime check
	for(int i = 0; i < N; i++){
		int n, found = 0;
		scanf("%d", &n);
		for(int j = 0; n > primes[j] && j < primes.size(); j++){
			if(!(n%primes[j]) && isPrime(n/primes[j])){
				printf("Yes\n");
				found = 1;
				break;
			}
		}
		if(!found)
			printf("No\n");
	}
	return 0;
}