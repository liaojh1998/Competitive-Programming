#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
	ios_base::sync_with_stdio(0);
	fin.tie(NULL);
	string s;
	while(getline(fin, s)){
		stringstream ss(s);
		string str;
		vector<string> slist;
		while(getline(ss, str, '\\'))
			slist.push_back(str);
		vector<string> ans;
		int size = 0, idx = 0;
		for(int i = 1; i < slist.size(); i++){
			if(slist[i].size() == 1 && slist[i][0] == '*'){
				idx = 0;
			}else if(slist[i][0] == '.'){
				bool sig = false;
				for(int j = 0; j < slist[i].size() && !sig; j++)
					if(slist[i][j] != '.')
						sig = true;
				if(sig){
					if(idx < size)
						ans[idx++] = slist[i];
					else{
						idx++;
						size++;
						ans.push_back(slist[i]);
					}
				}else{
					int size = slist[i].size()-1;
					while(size--)
						idx--;
					if(idx < 0) idx = 0;
				}
			}else if(slist[i].size()){
				if(idx < size)
					ans[idx++] = slist[i];
				else{
					idx++;
					size++;
					ans.push_back(slist[i]);
				}
			}
		}
		for(int i = 0; i < idx; i++)
			fout << '\\' << ans[i];
		if(idx == 0)
			fout << '\\' << endl;
		else
			fout << endl;
	}
	return 0;
}