//Title: Index of super-prime
//Type: Math/DP (Knapsack)
//Solution: Sieve of Eratostenes + Knapsack Algorithm
		/*	If you Wrong Answer at Test 8 make sure to look at the words "Non-increasing order"
			If you MLE at Test 18, don't use vectors for index of super-primes storage	*/
#include <cstdio>
#include <vector>
#include <cstring>
#define INF (10000)
using namespace std;
int sieve[INF+1], indexamount[INF+1], indexprimes[INF+1];
vector<int> superprimes, primes;
int main(){
	//Instantiation
	int N;
	scanf("%d", &N);
	//Sieve of Eratostenes
	primes.push_back(1);
	memset(sieve, 1, sizeof(sieve));
	for(int i = 2; i <= INF; i++)
		if(sieve[i]){
			primes.push_back(i);
			for(int j = 2; j*i <= INF; j++)
				sieve[j*i] = 0;
		}
	//Super-primes instantiation
	for(int i = 2; i < primes.size(); i++)
		if(sieve[i])
			superprimes.push_back(primes[i]);
	//Knapsack Algorithm
	for(int i = 1; i <= INF; i++){
		indexamount[i] = INF;
	}
	for(int i = 0; i < superprimes.size(); i++){
		for(int j = 1; j <= N; j++){
			if(j - superprimes[i] >= 0 && indexamount[j] > indexamount[j-superprimes[i]] + 1){ //indexamount[j] > or >= doesn't matter
				indexamount[j] = indexamount[j-superprimes[i]] + 1;
				indexprimes[j] = superprimes[i];
			}
		}
	}
	//Print answer
	if(indexamount[N] != INF){
		printf("%d\n", indexamount[N]);
		//Non-increasing order thank god
		printf("%d", indexprimes[N]);
		for(int i = N-indexprimes[N]; i; i-= indexprimes[i])
			printf(" %d", indexprimes[i]);
	}else
		printf("0\n");
	printf("\n");
	return 0;
}