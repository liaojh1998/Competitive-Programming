#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b, ans = 0;
	cin >> a >> b;
	for(long long i = 1; i <= 2000000000; i *= 2)
		for(long long j = 1; i*j <= 2000000000; j *= 3)
			if(i*j >= a && i*j <= b)
				ans++;
	cout << ans << endl;
	return 0;
}