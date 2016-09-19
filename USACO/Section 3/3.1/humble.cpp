/*
ID: liaojh11
PROG: humble
LANG: C++
*/
//Title: humble
//Type: Ad Hoc
//Solution: Brute Force generate all humble numbers.
		/*  For loop the primes and look for the one that is smallest after multiplying before humble numbers but bigger than the last humble number.
			To speed up search process, create an array to store the humble index each prime should start on.
			*/ 
#include <stdio.h>
#include <limits.h>
#define INF (LONG_MAX);
FILE *fin, *fout;
int K, N;
long humbles[100001] = {0};
int main(){
	fin = fopen("humble.in", "r");
	fout = fopen("humble.out", "w");
	//Instantiation
	fscanf(fin, "%d %d", &K, &N);
	int primes[K];
	for(int i = 0; i < K; i++){
		fscanf(fin, "%d", &primes[i]);
	}
	//Generate
	int pindex[K] = {0};
	humbles[0] = 1;
	for(int i = 1; i <= N; i++){
		long min = INF;
		int primecount = 0;
		for(int j = 0; j < K; j++){
			while(primes[j] * humbles[pindex[j]] <= humbles[i-1]){
				pindex[j]++;
			}
			if(min > primes[j] * humbles[pindex[j]]){
				min = primes[j] * humbles[pindex[j]];
				primecount = j;
			}
		}
		humbles[i] = min;
		pindex[primecount]++;
	}
	fprintf(fout, "%d\n", humbles[N]);
	return 0;
}