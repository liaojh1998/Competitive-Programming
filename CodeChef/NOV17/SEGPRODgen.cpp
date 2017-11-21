#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "w", stdout);
	mt19937 rd;
	string s = "34578oy872y53";
	seed_seq seed1(s.begin(), s.end());
	rd.seed(seed1);
	printf("1\n");
	int N = 1000000, Q = 20000000;
	long long MOD = rd()%999999999+2;
	printf("%d %lld %d\n", N, MOD, Q);
	for(int i = 0; i < N; i++)
		printf("%lld%s", static_cast<long long>(rd())%(MOD-1)+1, (i == N-1 ? "\n" : " "));
	int size = Q/64+2;
	for(int i = 0; i < size; i++)
		printf("%lu%s", rd()%N, (i == size-1 ? "\n" : " "));
	return 0;
}