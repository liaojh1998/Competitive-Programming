//Title: Modern Art (Bronze)
//Type: Brute Force
//Complexity: O(N^3)
//Solution: Colors that cover other colors are eliminated from being possibly the first painted.
#include <bits/stdc++.h>
using namespace std;

void solve(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int N;
	scanf("%d", &N);
	getchar();
	int mat[N+5][N+5], imin[10], imax[10], jmin[10], jmax[10];
	bool used[10];
	memset(imin, -1, sizeof(imin));
	memset(imax, -1, sizeof(imax));
	memset(jmin, -1, sizeof(jmin));
	memset(jmax, -1, sizeof(jmax));
	memset(used, 0, sizeof(used));
	vector<int> colors;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat[i][j] = getchar()-'0';
			if(mat[i][j]){
				if(!used[mat[i][j]]){
					colors.push_back(mat[i][j]);
					used[mat[i][j]] = true;
				}
				if(imin[mat[i][j]] == -1 || imin[mat[i][j]] > i)
					imin[mat[i][j]] = i;
				if(imax[mat[i][j]] == -1 || imax[mat[i][j]] < i)
					imax[mat[i][j]] = i;
				if(jmin[mat[i][j]] == -1 || jmin[mat[i][j]] > j)
					jmin[mat[i][j]] = j;
				if(jmax[mat[i][j]] == -1 || jmax[mat[i][j]] < j)
					jmax[mat[i][j]] = j;
			}
		}
		getchar();
	}
	vector<int> covered[10];
	bool coverer[10];
	memset(coverer, 0, sizeof(coverer));
	int size = colors.size();
	for(int i = 0; i < size; i++){
		int color = colors[i];
		memset(used, 0, sizeof(used));
		for(int j = imin[color]; j <= imax[color]; j++)
			for(int k = jmin[color]; k <= jmax[color]; k++)
				if(mat[j][k] && mat[j][k] != color && !used[mat[j][k]]){
					used[mat[j][k]] = true;
					covered[color].push_back(mat[j][k]);
					coverer[mat[j][k]] = true;
				}
	}
	int ans = 0;
	for(int i = 0; i < size; i++)
		if(!coverer[colors[i]])
			ans++;
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}