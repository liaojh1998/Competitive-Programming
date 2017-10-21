#include <bits/stdc++.h>
using namespace std;

vector<int> edges[26];
vector<string> stuff(25*25+5);
vector<string> ans;
bool checked[26], lastchecked[26];

void dfs(int cur){
	int size = edges[cur].size();
	bool hasUnbuilt = false;
	for(int i = 0; i < size; i++)
		if(!lastchecked[edges[cur][i]]){
			dfs(edges[cur][i]);
			hasUnbuilt = true;
		}else if(!checked[edges[cur][i]]){
			hasUnbuilt = true;
		}
	if(!hasUnbuilt){
		ans.push_back(stuff[cur]);
		lastchecked[cur] = true;
	}
}

int main(){
	string s;
	getline(cin, s);
	unordered_map<string, int> m;
	int size = 0;
	stuff[size] = s;
	m[s] = size++;
	int N;
	cin >> N;
	getchar();
	for(int i = 0; i < N; i++){
		cin >> s;
		if(!m.count(s)){
			stuff[size] = s;
			m[s] = size++;
		}
		int u = m[s];
		int Q;
		cin >> Q;
		while(Q--){
			cin >> s;
			int v;
			if(!m.count(s)){
				stuff[size] = s;
				m[s] = size++;
			}
			v = m[s];
			edges[u].push_back(v);
		}
	}
	int last = 0;
	vector<string> actualans;
	while(!checked[0]){
		dfs(0);
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++)
			actualans.push_back(ans[i]);
		memcpy(checked, lastchecked, sizeof(checked));
		ans.clear();
	}
	for(int i = 0; i < actualans.size(); i++)
		cout << actualans[i] << (i == actualans.size()-1 ? "\n" : " ");
	return 0;
}