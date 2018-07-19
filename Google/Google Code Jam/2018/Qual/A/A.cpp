#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, D, size, mask, score, base, ans;
	bool swapped;
	string str;
	cin >> T;
	for(int idx = 1; idx <= T; idx++){
		cin >> D;
		cin >> str;
		size = str.size();
		mask = 0;
		for(int i = 0; i < size; i++)
			if(str[i] == 'C')
				mask |= (1 << i);
		score = 0;
		base = 1;
		for(int i = 0; i < size; i++)
			if((mask >> i) & 1)
				base += base;
			else
				score += base;
		if(score > D)
			ans = -1;
		else
			ans = 0;
		swapped = true;
		for(int i = 1; ans == -1 && swapped; i++){
			swapped = false;
			for(int k = size-1; k >= 1 && !swapped; k--){
				if(!((mask >> k) & 1) && ((mask >> (k-1)) & 1)){
					mask ^= (1 << k);
					mask ^= (1 << (k-1));
					base = 1;
					score = 0;
					for(int j = 0; j < size; j++)
						if((mask >> j) & 1)
							base += base;
						else
							score += base;
					if(score <= D)
						ans = i;
					swapped = true;
				}
			}
		}
		cout << "Case #" << idx << ": ";
		if(ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
		/*
		for(int i = 0; i < size; i++)
			cout << ((mask >> i) & 1 ? 1 : 0);
		cout << endl;
		cout << score << endl;
		base = 1;
		score = 0;
		for(int i = 0; i < size; i++)
			if(mask & (1 << i))
				base += base;
			else
				score += base;
		cout << score << endl;
		*/
	}
	return 0;
}