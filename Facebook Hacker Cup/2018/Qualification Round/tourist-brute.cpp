#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

bool finalcmp(const pair<int, int>& a, const pair<int, int>& b){
	return a.second < b.second;
}

int main(){
	freopen("tourist.txt", "r", stdin);
	freopen("tourist-ans.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int index = 1; index <= T; index++){
		long long N, K, V;
		cin >> N >> K >> V;
		pair<int, int> arr[N+5];
		string ans[N+5];
		for(int i = 0; i < N; i++){
			arr[i].first = 0;
			arr[i].second = i;
			cin >> ans[i];
		}
		for(int i = 0; i < V; i++){
			sort(arr, arr+N, cmp);
			for(int j = 0; j < K; j++)
				arr[j].first++;
		}
		cout << "Case #" << index << ": ";
		sort(arr, arr+K, finalcmp);
		for(int i = 0; i < K; i++)
			cout << ans[arr[i].second] << (i == K-1 ? "\n" : " ");
	}

	return 0;
}
