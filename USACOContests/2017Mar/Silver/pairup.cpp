//Title: Paired Up
//Type: Greedy
//Complexity: O(NlogN)
//Solution: Usually all 10^5 questions need an O(NlogN) solution, and USACO has a O(N) solution.
		//	I simply sorted the cows based on time and paired the most time required with the least time required and searched for the minimum required.
#include <bits/stdc++.h>
using namespace std;

void solve(){
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	//Is this really that greedy?
	int N;
	scanf("%d", &N);
	pair<long long, long long> cowlist[N+5];
	for(int i = 0; i < N; i++)
		scanf("%lld%lld", &cowlist[i].second, &cowlist[i].first);
	sort(cowlist, cowlist+N);
	long long ans = 0;
	int i = 0, j = N-1;
	while(i <= j){
		if(ans < cowlist[i].first+cowlist[j].first)
			ans = cowlist[i].first+cowlist[j].first;
		int mincow = cowlist[i].second < cowlist[j].second ? cowlist[i].second : cowlist[j].second;
		cowlist[i].second -= mincow;
		if(i != j)
			cowlist[j].second -= mincow;
		if(!cowlist[i].second)
			i++;
		if(!cowlist[j].second)
			j--;
	}
	printf("%lld\n", ans);
}
int main(){
	solve();
	return 0;
}