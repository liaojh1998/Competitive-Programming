//Title: Border
//Type: Brute Force
//Solution: Not sure if this is supposed to be really hard, but it is confusing
#include <cstdio>
#include <algorithm>
using namespace std;
int N, temp, cnt = 1;
struct pr{int A, B;} p[16000];
bool cmp(pr a, pr b){
	return a.A < b.A || (a.A == b.A && a.B < b.B);
}
int main(){
	//Instantiation
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &p[i].A, &p[i].B);
	sort(p, p + N, cmp);
	//Count
	for(int i = 1; i < N; i++)
		if(p[i].A == p[temp].A || p[i].B >= p[temp].B){
			cnt++;
			temp = i;
		}
	printf("%d\n", N-cnt);
	return 0;
}