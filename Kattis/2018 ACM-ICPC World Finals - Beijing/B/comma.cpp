#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, word;
	getline(cin, str);
	stringstream ss(str);
	vector<string> s;
	unordered_map<string, unordered_set<string>> prev, post;
	while(ss.good()){
		ss >> word;
		s.push_back(word);
	}
	int size = s.size();
	string a, b;
	unordered_set<string> queued[2], needcomma;
	queue<pair<int, string>> q;
	for(int i = 0; i < size-1; i++){
		if(s[i][s[i].size()-1] != '.'){
			if(s[i][s[i].size()-1] == ',')
				a = s[i].substr(0, s[i].size()-1);
			else
				a = s[i];
			if(s[i+1][s[i+1].size()-1] == ',' || s[i+1][s[i+1].size()-1] == '.')
				b = s[i+1].substr(0, s[i+1].size()-1);
			else
				b = s[i+1];
			post[a].insert(b);
			if(s[i][s[i].size()-1] != ',')
				prev[b].insert(a);
			if(s[i][s[i].size()-1] == ',' && !queued[0].count(a)){
				q.push(pair<int, string>(0, a));
				queued[0].insert(a);
			}
		}
	}
	while(!q.empty()){
		pair<int, string> tmp = q.front();
		q.pop();
		str = tmp.second;
		if(tmp.first){
			unordered_set<string>::iterator end = prev[str].end();
			for(unordered_set<string>::iterator it = prev[str].begin(); it != end; it++){
				if(!queued[0].count(*it)){
					q.push(pair<int, string>(0, *it));
					queued[0].insert(*it);
				}
			}
		}else{
			needcomma.insert(str);
			unordered_set<string>::iterator end = post[str].end();
			for(unordered_set<string>::iterator it = post[str].begin(); it != end; it++){
				if(!queued[1].count(*it)){
					q.push(pair<int, string>(1, *it));
					queued[1].insert(*it);
				}
			}
		}
	}
	for(int i = 0; i < size; i++){
		cout << s[i];
		if(needcomma.count(s[i]))
			cout << ',';
		if(i == size-1)
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}