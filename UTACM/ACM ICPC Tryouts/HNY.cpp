//Title: Happy New Year
//Type: DP of the BFS state in both direct and reverse directions
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int T, A, F, map[105][105], cur[105][105], temp[105][105], f, t, N;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &A, &F);
		for(int i = 0; i < A; i++){
			cur[i][i] = 1;
			map[i][i] = 1;
		}
		for(int i = 0; i < F; i++){
			scanf("%d%d", &f, &t);
			map[f][t] = 1;
		}
		//Initial check see if it's possible to go anywhere
		int bit = 1;
		for(int i = 0; i < A; i++)
			for(int j = 0; j < A; j++)
				bit &= cur[i][j];
		if(bit){
			printf("0\n");
			memset(map, 0, sizeof(map));
			continue;
		}
		while(N++ <= A){
			//Direct
			memset(temp, 0, sizeof(temp));
			for(int i = 0; i < A; i++)
				for(int j = 0; j < A; j++)
					for(int k = 0; k < A; k++)
						temp[i][k] |= map[i][j]&cur[j][k];
			memcpy(cur, temp, sizeof(temp));
			//Opposite
			memset(temp, 0, sizeof(temp));
			for(int i = 0; i < A; i++)
				for(int j = 0; j < A; j++)
					for(int k = 0; k < A; k++)
						temp[i][k] |= cur[i][j]&map[k][j];
			memcpy(cur, temp, sizeof(temp));
			//Check if complete
			bit = 1;
			for(int i = 0; i < A; i++)
				for(int j = 0; j < A; j++)
					bit &= cur[i][j];
			if(bit){
				printf("%d\n", N);
				break;
			}
		}
		if(!bit)
			printf("IMPOSSIBLE\n");
		memset(map, 0, sizeof(map));
		memset(cur, 0, sizeof(cur));
		N = 0;
	}
	return 0;
}