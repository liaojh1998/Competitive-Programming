//Title: History Grading
//Type: DP
//Complexity: O(N^2)
//Solution: Classic LIS, O(N^2) problem will suffice here. Ugh, ranking does not mean chronological order, make sure to rank them in chronological order.
#include <cstdio>
#include <cstring>
int N, loc[30], stu[30], n, lis[30], max;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &n);
		loc[i] = n;
	}
	while(~scanf("%d", &n)){
		stu[n] = lis[1] = max = 1;
		for(int i = 2; i <= N; i++){
			scanf("%d", &n);
			stu[n] = i;
		}
		for(int i = 2; i <= N; i++){
			for(int j = 1; j < i; j++){
				if(loc[stu[i]] > loc[stu[j]] && lis[i] < lis[j] + 1)
					lis[i] = lis[j] + 1;
			}
			if(!lis[i])
				lis[i] = 1;
			if(max < lis[i])
				max = lis[i];
		}
		printf("%d\n", max);
		memset(lis, 0, sizeof(lis));
	}
	return 0;
}