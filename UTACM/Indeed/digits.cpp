#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int T;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int arr[N];
		for(int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+N, greater<int>());
		int ans = 0, mask = 0;
		for(int i = 0; i < N && mask != ((1<<10)-1); i++){
			int cur = arr[i];
			bool possible = true;
			while(cur){
				int index = cur%10;
				//printf("%d %d\n", index, 1<<index);
				if(mask & 1<<index){
					possible = false;
					break;
				}
				cur /= 10;
			}
			if(possible){
				//printf("%d\n", arr[i]);
				ans += arr[i];
				while(arr[i]){
					mask |= 1<<arr[i]%10;
					arr[i] /= 10;
				}
				//printf("%d\n\n", mask);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}