//Title: Bovine Genomics (Silver)
//Type: Brute Force
//Complexity: O(N*M^3)
//Solution: Taking advantage of the fact we only need 3 locations and there are 4^3 combinations, iterate out all possible locations and check for possibility.
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
	int ans = 0;
	bool spottycomb[4][4][4], plaincomb[4][4][4];
	for(int i = 0; i < M-2; i++){
		for(int j = i+1; j < M-1; j++){
			for(int k = j+1; k < M; k++){
				memset(spottycomb, 0, sizeof(spottycomb));
				memset(plaincomb, 0, sizeof(plaincomb));
				for(int l = 0; l < N; l++)
					spottycomb[conv(spotty[l][i])][conv(spotty[l][j])][conv(spotty[l][k])] = true;
				for(int l = 0; l < N; l++)
					plaincomb[conv(plain[l][i])][conv(plain[l][j])][conv(plain[l][k])] = true;
				bool impossible = false;
				for(int i1 = 0; i1 < 4 && !impossible; i1++)
					for(int j1 = 0; j1 < 4 && !impossible; j1++)
						for(int k1 = 0; k1 < 4 && !impossible; k1++)
							if(spottycomb[i1][j1][k1] && plaincomb[i1][j1][k1])
								impossible = true;
				if(!impossible)
					ans++;
			}
		}
	}
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}