#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int T;
int main(){
	scanf("%d", &T);
	while(T--){
		int R, C;
		scanf("%d%d", &R, &C);
		int mat[R][C], pos[R], first, second, v;
		scanf("%d%d", &first, &second);
		pos[0] = second - first;
		first = second;
		for(int i = 1; i < R; i++){
			scanf("%d", &second);
			pos[i] = second - first;
			first = second;
		}
		getchar();
		char c;
		int a = 0;
		vector<int> A;
		while(~scanf("%c", &c) && c != 10){
			if(c == ' '){
				A.push_back(a);
				a = 0;
			}
			else
				a = a*10 + c - '0';
		}
		A.push_back(a);
		vector<int> J;
		a = 0;
		while(~scanf("%c", &c) && c != 10){
			if(c == ' '){
				J.push_back(a);
				a = 0;
			}
			else
				a = a*10 + c - '0';
		}
		J.push_back(a);
		memset(mat, 0, sizeof(mat));
		int aloc = 0, jloc = 0;
		for(int i = 0; i < R; i++){
			while(pos[i]--){
				mat[i][J[jloc++]] = A[aloc++];
			}
		}
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(j == C -1)
					printf("%d\n", mat[i][j]);
				else
					printf("%d ", mat[i][j]);
			}
		}
	}
	return 0;
}