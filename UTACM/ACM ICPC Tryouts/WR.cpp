//Title: Wings and Redbull
//Type: Knapsack
#include <cstdio>
#include <cstring>
using namespace std;
int T, N, B, M, t[100105], H[105];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &B, &M);
		for(int i = 0; i < M; i++)
			scanf("%d", &H[i]);
		memset(t, 1, sizeof(t));
		t[0] = 0;
		//Knapsack O(100100*M)
		for(int i = 0; i <= 100100; i++)
			for(int j = 0; j < M; j++){
				if(i + H[j] <= 100100 && t[i + H[j]] > t[i] + 1)
					t[i + H[j]] = t[i] + 1;
			}
		//Redbull O(100100)
		for(int i = 100100; i >= 0; i--)
			if(i - B > 0 && t[i - B] > t[i])
					t[i - B] = t[i];
		printf("%d\n", t[N]);
	}
	return 0;
}