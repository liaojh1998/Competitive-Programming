#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, temp;
	int T, size;
	cin >> T;
	cin.ignore();
	while(T--){
		getline(cin, str);
		vector<string> s;
		stringstream ss(str);
		while(ss.good()){
			ss >> temp;
			s.push_back(temp);
		}
		size = s.size();
		for(int i = 0; i < size; i++)
			if(i == size-1){
				cout << (char)toupper(s[i][0]);
				for(int j = 1; j < s[i].size(); j++)
					cout << (char)tolower(s[i][j]);
				cout << endl;
			}else{
				cout << (char)toupper(s[i][0]);
				cout << ". ";
			}
	}
	return 0;
}