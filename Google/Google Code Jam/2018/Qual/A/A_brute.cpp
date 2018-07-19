#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output-brute.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, D, ans, size, loc, dist, score, base, res, tmp;
	string str;
	cin >> T;
	for(int idx = 1; idx <= T; idx++){
		cin >> D;
		cin >> str;
		ans = -1;
		queue<pair<int, int>> q;
		size = str.size();
		loc = 0;
		for(int i = 0; i < size; i++)
			if(str[i] == 'C')
				loc |= (1 << i);
		bool vis[(1<<25)+1];
		memset(vis, 0, sizeof(vis));
		q.push(pair<int, int>(loc, 0));
		while(!q.empty() && ans == -1){
			loc = q.front().first;
			dist = q.front().second;
			q.pop();
			if(!vis[loc]){
				vis[loc] = true;
				score = 0;
				base = 1;
				for(int i = 0; i < size; i++)
					if((loc >> i) & 1)
						base += base;
					else
						score += base;
				if(score > D){
					for(int i = 0; i < size-1; i++){
						res = (loc & (1 << i) ? 1 : 0) ^ (loc & (1 << (i + 1)) ? 1 : 0);
						if(res){
							tmp = loc;
							tmp ^= ((res << i) | (res << (i + 1)));
							if(!vis[tmp])
								q.push(pair<int, int>(tmp, dist+1));
						}
					}
				}else
					ans = dist;
			}
		}
		cout << "Case #" << idx << ": ";
		if(ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
		/*
		for(int i = 0; i < size; i++)
			cout << ((loc >> i) & 1 ? 1 : 0);
		cout << endl;
		cout << score << endl;
		*/
	}
	return 0;
}