//Title: Bovine Genomics (Bronze)
//Type: Brute Force
//Complexity: O(N*M)
//Solution: If a letter has not been used in the spotty while used in the plain, it's a potential location.
#include <bits/stdc++.h>
using namespace std;

int conv(char c){
	switch(c){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	return -1;
}
void solve(){
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	int N, M;
	scanf("%d%d", &N, &M);
	getchar();
	char spotty[N+5][M+5], plain[N+5][M+5];
	for(int i = 0; i < N; i++)
		scanf("%s", &spotty[i]);
	for(int i = 0; i < N; i++)
		scanf("%s", &plain[i]);
	bool plainuse[M+5][4];
	memset(plainuse, 0, sizeof(plainuse));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			plainuse[j][conv(plain[i][j])] = true;
	bool impossible[M+5];
	memset(impossible, 0, sizeof(impossible));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(plainuse[j][conv(spotty[i][j])])
				impossible[j] = true;
	int ans = 0;
	for(int i = 0; i < M; i++)
		if(!impossible[i])
			ans++;
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}