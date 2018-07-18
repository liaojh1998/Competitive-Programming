#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin1("tourist.txt");
	ifstream fin2("tourist-out.txt");
	
	int T;
	fin1 >> T;
	for(int index = 1; index <= T; index++){
		unordered_map<string, int> m;
		int N, K, dump;
		fin1 >> N;
		fin1 >> K >> dump;
		string str;
		for(int j = 0; j < N; j++){
			fin1 >> str;
			m[str] = j;
			cout << str << ":" << m[str] << endl;
		}
		int start = -1;
		string strdmp;
		fin2 >> strdmp >> strdmp;
		cout << "Case #" << index << ": ";
		bool error = false;
		for(int j = 0; j < K && !error; j++){
			fin2 >> str;
			if(m[str] <= start){
				error = true;
				cout << str << " at " << j << " with " << m[str] << endl;
			}
			start = m[str];
			if(error)
				cout << str << " " << m[str] << " ";
		}
		if(error)
			cout << "WA" << endl;
		else
			cout << "AC" << endl;
	}
	return 0;
}
