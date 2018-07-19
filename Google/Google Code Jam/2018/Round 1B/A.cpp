#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int need, idx;
}data;

bool cmp(const data& a, const data& b){
	return a.need < b.need;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++){
		int N, L, total = 0;
		cin >> N >> L;
		int C[N+5];
		memset(C, 0, sizeof(C));
		for(int i = 0; i < L; i++){
			cin >> C[i];
			total += C[i];
		}
		data D[N+5];
		vector<int> upper;
		int eps = N&1;
		for(int i = 1; i <= N; i++)
			if(((i-1)*100)%N < (N/2 + eps) && (i*100)%N >= (N/2 + eps))
				upper.push_back(i);
		int size = upper.size();
		for(int i = 0; i < N; i++){
			int loc = upper_bound(upper.begin(), upper.end(), C[i]) - upper.begin();
			if(loc == size)
				D[i].need = N;
			else
				D[i].need = upper[loc]-C[i];
			D[i].idx = i;
		}
		sort(D, D+N, cmp);
		for(int i = 0; i < N && N > total; i++){
			int add = min(N-total, D[i].need);
			C[D[i].idx] += add;
			total += add;
		}
		int ans = 0;
		for(int i = 0; i < N; i++){
			ans += (C[i]*100)/N;
			ans += (C[i]*100)%N >= (N/2 + eps) ? 1 : 0;
		}
		cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}