//Title: Largest prime factor
//Solution: Sieve all primes, find it.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool mark[1000000];
vector<long long> primes;
int T, len;
long long i, j, N;
int main() {
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    //Sieve of eratostenes
    for(i = 2; i < 1000000; i++)
        if(!mark[i]){
            primes.push_back(i);
            for(j = i; i*j < 1000000; j++)
                mark[i*j] = true;
        }
    len = primes.size();
    scanf("%d", &T);
    while(T--){
        scanf("%lld", &N);
        long long answer = 0;
        for(int i = 0; i < len && primes[i]*primes[i] <= N; i++){
            while(!(N%primes[i])){
                N /= primes[i];
                answer = primes[i];
            }
        }
        printf("%lld\n", N == 1 ? answer : N);
    }
    return 0;
}