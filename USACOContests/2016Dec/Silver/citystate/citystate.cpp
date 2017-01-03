#include <cstdio>
#include <cstring>
int main(){
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
	//What is this ad hoc question
	int N;
	scanf("%d", &N);
	getchar();
	int letters[26][26][26][26];
	memset(letters, 0, sizeof(letters));
	long long sum = 0;
	for(int i = 0; i < N; i++){
		char city[20], state[20];
		scanf("%s", &city);
		city[strlen(city)] = '\0';
		scanf("%s", &state);
		state[strlen(state)] = '\0';
		int a, b, c, d;
		a = city[0]-'A';
		b = city[1]-'A';
		c = state[0]-'A';
		d = state[1]-'A';
		if(a == c && b == d)
			continue;
		//pairs are not distinct
		letters[a][b][c][d]++;
		sum += letters[c][d][a][b];
	}
	printf("%lld\n", sum);
	return 0;
}