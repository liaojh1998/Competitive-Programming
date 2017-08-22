#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool xored[100005];
long long n, m, mat[100005];
//map<pair<long long, long long>, long long> xored;
//vector<long long> indices;
void xorfunc(long long index, long long next){
	//printf("%lld:%lld ", index, next);
	//long long cur = mat[index];
	xored[index] ^= true;
	for(long long i = (long long)1<<(long long)log2(next); i > 0; i>>=1){
		if(i & next){
			/*if(xored.count(pair<long long, long long>((index+i%n)%n, next^i)) == 0){
				xored[pair<long long, long long>((index+i%n)%n, next^i)] = xorfunc((index+i%n)%n, next^i);
				cur ^= xored[pair<long long, long long>((index+i%n)%n, next^i)];
				//cur ^= xorfunc((index+i%n)%n, next^i);
				next ^= i;
				//printf("%lld-%lld-%lld ", (index+i%n)%n, next, xored[(index+i%n)%n][depth]);
			}else{
				cur ^= xored[pair<long long, long long>((index+i%n)%n, next^i)];
				next ^= i;
			}*/
			xorfunc((index+i%n)%n, next^i);
			next ^= i;
		}
	}
	//return cur;
}
int main(){
	freopen("seqinput.txt", "r", stdin);
	freopen("seqoutput.txt", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(long long i = 0; i < n; i++)
		scanf("%lld", &mat[i]);
	//Recurrence for n to optimize m
	long long recur, forseq, shift = 0;
	vector<long long> recurred;
	for(long long i = 1;; i++){
		recur = (2 + ((long long)1<<(long long)i))/2;
		forseq = (recur-1)%n + 1;
		if(recur > n){
			shift = n - forseq + 2;
			//printf("%lld %lld %lld\n", i, recur, forseq, shift);
			if(find(recurred.begin(), recurred.end(), shift) != recurred.end()){
				forseq = shift;
				break;
			}
		}
		if(find(recurred.begin(), recurred.end(), forseq) != recurred.end()) break;
		recurred.push_back(forseq);
	}
	long long rep = recur - forseq, multi = 0;
	if(rep && m > (m - forseq)%rep + forseq){
		multi = (m-forseq)/rep;
		m = (m - forseq)%rep + forseq;
	}
	//printf("%lld %lld %lld %lld %lld %lld\n", recur, rep, forseq, shift, multi, m);
	//Recurrence for binary m search
	xorfunc((multi*(shift-1)%n+n)%n, m-1);
	for(long long i = 0; i < n; i++)
		if(xored[i])
			printf("%lld ", i);
	printf("\n");
	/*
	for(long long i = 0; i < n; i++){
		if(i == n-1)
			printf(":%lld\n", xorfunc((i-multi*(shift-1)%n+n)%n, m-1));
		else
			printf(":%lld\n", xorfunc((i-multi*(shift-1)%n+n)%n, m-1));
	}
	*/
	return 0;
}