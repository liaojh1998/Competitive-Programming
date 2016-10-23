#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	getchar();
	while(T--){
		int arr[60], size = 0;
		memset(arr, 0, sizeof(arr));
		char c = getchar();
		while(~c && c != 10){
			if(c == ' '){
				c = getchar();
				continue;
			}
			if(c == '-' || c == '=')
				size++;
			else
				arr[size] = arr[size] * 10 + c - '0';
			c = getchar();
		}
		size++;
		int start = arr[0];
		for(int i = 1; i < size-1; i++)
			start -= arr[i];
		if(start == arr[size-1]){
			printf("correct\n");
			continue;
		}
		start = arr[0] - arr[1];
		for(int i = 2; i < size-1; i++){
			if(start < arr[size-1])
				start += arr[i];
			else
				start -= arr[i];
		}
		if(start == arr[size-1])
			printf("fixable\n");
		else
			printf("unfixable\n");
	}
	return 0;
}