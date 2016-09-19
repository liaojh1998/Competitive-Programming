//Title: Prime Sum
//Type: Math
//Solution: Sieve of Eratostenes
#include <cstdio>
#include <cstring>
int N, p1[8169], p2[8169], plen;
bool sieve[1000001];
int main(){
	scanf("%d", &N);
	//Sieve of Eratostenes
	memset(sieve, 1, sizeof(sieve));
	for(int i = 2; i <= N; i++)
		if(sieve[i]){
			for(int j = 2; j*i <= N; j++)
				sieve[j*i] = false;
			//Notice that only used 2, because 2 is the only prime number that adds another prime number will end up being an odd, possibly prime number.
			if(2 + i <= N && sieve[2 + i]){
				p1[plen] = 2;
				p2[plen++] = i;
			}
		}
	//Print answer
	printf("%d\n", plen);
	for(int i = 0; i < plen; i++)
		printf("%d %d\n", p1[i], p2[i]);
	return 0;
}