//Title: Where's Bessie?
//Type: Brute Force
//Complexity: O(N^6)
//Solution: Brute force every possible rectangle, and use flood fill to check if the rectangle is a PCL. Use a limit vector to keep track if a rectangle is smaller than any PCL.
#include <bits/stdc++.h>
using namespace std;

struct limit{
	int imin, imax, jmin, jmax;
	limit(int a, int b, int c, int d){
		imin = a;
		jmin = b;
		imax = c;
		jmax = d;
	}
};
int ic[4] = {-1, 0, 1, 0};
int jc[4] = {0, 1, 0, -1};
void solve(){
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);
	//As if brute force isn't enough for this competition
	int N;
	scanf("%d", &N);
	getchar();
	char mat[N+5][N+5];
	memset(mat, 0, sizeof(mat));
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			mat[i][j] = getchar();
		getchar();
	}
	bool checked[N+5][N+5];
	int colorcount[26];
	vector<limit*> limits;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = N; k >= i; k--){
				for(int l = N; l >= j; l--){
					bool limited = false;
					int size = limits.size();
					for(int lcheck = 0; lcheck < size && !limited; lcheck++)
						if(i >= limits[lcheck]->imin && j >= limits[lcheck]->jmin && k <= limits[lcheck]->imax && l <= limits[lcheck]->jmax)
							limited = true;
					if(!limited){
						memset(checked, 0, sizeof(checked));
						memset(colorcount, 0, sizeof(colorcount));
						vector<int> colors;
						for(int i1 = i; i1 <= k && colors.size() <= 2; i1++)
							for(int j1 = j; j1 <= l && colors.size() <= 2; j1++){
								if(!checked[i1][j1]){
									queue<pair<int, int> > q;
									q.push(pair<int, int>(i1, j1));
									checked[i1][j1] = true;
									if(!colorcount[mat[i1][j1]-'A']){
										colors.push_back(mat[i1][j1]-'A');
										colorcount[mat[i1][j1]-'A']++;
									}else
										colorcount[mat[i1][j1]-'A']++;
									while(!q.empty()){
										pair<int, int> cur = q.front(); q.pop();
										int curi = cur.first;
										int curj = cur.second;
										for(int c = 0; c < 4; c++)
											if(curi + ic[c] >= i && curj + jc[c] >= j && curi + ic[c] <= k && curj + jc[c] <= l && mat[curi+ic[c]][curj+jc[c]] == mat[curi][curj] && !checked[curi+ic[c]][curj+jc[c]]){
												checked[curi+ic[c]][curj+jc[c]] = true;
												q.push(pair<int, int>(curi+ic[c], curj+jc[c]));
											}
									}
								}
							}
						if(colors.size() == 2 && ((colorcount[colors[0]] == 1 && colorcount[colors[1]] > 1) || (colorcount[colors[1]] == 1 && colorcount[colors[0]] > 1)))
							limits.push_back(new limit(i, j, k, l));
					}
				}
			}
		}
	}
	printf("%d\n", limits.size());
}
int main(){
	solve();
	return 0;
}