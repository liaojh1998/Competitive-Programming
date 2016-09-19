//Title: Telephone Directory
//Type: Brute Force
//Solution: Really unsure if this is supposed to be really easy or really hard?
#include <cstdio>
int K, N, total[10], sum;
int main(){
	//Instantiation
	scanf("%d %d", &K, &N);
	for(int i = 0; i < N; i++){
		char str[5];
		scanf("%s", &str);
		total[str[0]-'0']++;
	}
	for(int i = 0; i <= 9; i++){
		if(total[i]){
			sum++;
			sum+=(total[i]-1)/K;
		}
	}
	printf("%d\n", sum+2);
	return 0;
}