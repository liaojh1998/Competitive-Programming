#include <bits/stdc++.h>
using namespace std;

struct rect{
	double W, H;
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int idx = 1; idx <= T; idx++){
		printf("Case #%d: ", idx);
		int N;
		double P, ans;
		cin >> N >> P;
		rect arr[N+5];
		double dmin[10000], dmax[10000];
		double start = 0;
		for(int i = 0; i < N; i++){
			cin >> arr[i].W >> arr[i].H;
			start += (arr[i].W + arr[i].H)*2;
		}
		dmin[0] = start;
		dmax[0] = start;
		ans = start;
		int size = 1, p = 1;
		for(int i = 0; i < N; i++){
			double shortest = min(arr[i].W, arr[i].H)*2;
			double longest = (sqrt(arr[i].W*arr[i].W + arr[i].H*arr[i].H))*2;
			for(int j = 0; j < size; j++){
				double a = dmin[j]+shortest;
				double b = dmax[j]+longest;
				if(a <= P && P <= b)
					ans = P;
				if(b < P && ans < b)
					ans = b;
				if(a <= P){
					dmin[size + j + 1] = a;
					dmax[size + j + 1] = b;
				}
			}
			size += p++;
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}