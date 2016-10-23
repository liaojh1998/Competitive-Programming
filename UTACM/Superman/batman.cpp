#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int T, N, K;
string names[100000];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &K);
		map<string, int> has;
		for(int i = 0; i < N; i++){
			cin >> names[i];
			has[names[i]] = 1;
		}
		if(has.size() < K){
			printf("-1\n");
			continue;
		}
		int length = N;
		for(int i = 0; i < N; i++){
			map<string, int> temphas;
			int j;
			for(j = i; j < N && temphas.size() < K; j++){
				temphas[names[j]] = 1;
			}
			if(temphas.size() >= K)
				length = min(length, j - i);
		}
		printf("%d\n", length);
	}
	return 0;
}