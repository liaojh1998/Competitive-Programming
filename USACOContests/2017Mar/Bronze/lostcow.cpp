//Title: The Lost Cow
//Type: Simulation
//Complexity: O(N)
//Solution: Fun stuff to simulate, it's actually a problem studied in computer science!
#include <bits/stdc++.h>
using namespace std;

void solve(){
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	int x, y, ans = 0;
	scanf("%d%d", &x, &y);
	int temp = x, cur = x, dist = 1;
	for(int i = 0; !((temp <= y && y <= cur) || (temp >= y && y >= cur)); i++, dist <<= 1){
		temp = cur;
		if(i%2){
			cur = x-dist;
			if(y < x && cur < y)
				cur = y;
			ans += temp-cur;
		}else{
			cur = x+dist;
			if(x < y && cur > y)
				cur = y;
			ans += cur-temp;
		}
	}
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}