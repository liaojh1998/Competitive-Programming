#include <bits/stdc++.h>
using namespace std;

bool up(char c){
	return c >= 'A' && c <= 'Z';
}

bool cmpwhite(const string& a, const string& b){
	if(up(a[0]) && up(b[0])){
		if(a[0] == b[0]){
			if(a[2] == b[2])
				return a[1] < b[1];
			return a[2] < b[2];
		}else{
			if(a[0] == 'K' || b[0] == 'K')
				return a[0] == 'K';
			else if(a[0] == 'Q' || b[0] == 'Q')
				return a[0] == 'Q';
			else if(a[0] == 'R' || b[0] == 'R')
				return a[0] == 'R';
			else if(a[0] == 'B' || b[0] == 'B')
				return a[0] == 'B';
			return a[0] == 'N';
		}
	}
	if(up(a[0]) || up(b[0]))
		return up(a[0]);
	if(a[1] == b[1])
		return a[0] < b[0];
	return a[1] < b[1];
}

bool cmpblack(const string& a, const string& b){
	if(up(a[0]) && up(b[0])){
		if(a[0] == b[0]){
			if(a[2] == b[2])
				return a[1] < b[1];
			return a[2] > b[2];
		}else{
			if(a[0] == 'K' || b[0] == 'K')
				return a[0] == 'K';
			else if(a[0] == 'Q' || b[0] == 'Q')
				return a[0] == 'Q';
			else if(a[0] == 'R' || b[0] == 'R')
				return a[0] == 'R';
			else if(a[0] == 'B' || b[0] == 'B')
				return a[0] == 'B';
			return a[0] == 'N';
		}
	}
	if(up(a[0]) || up(b[0]))
		return up(a[0]);
	if(a[1] == b[1])
		return a[0] < b[0];
	return a[1] > b[1];
}

int main(){
	char board[8][8];
	string trash;
	for(int i = 0; i < 8; i++){
		getline(cin, trash);
		getline(cin, trash);
		string token;
		stringstream ss(trash);
		getline(ss, token, '|');
		int j = 0;
		while(getline(ss, token, '|'))
			board[i][j++] = token[1];
	}
	getline(cin, trash);
	vector<string> white, black;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(board[i][j] != ':' && board[i][j] != '.'){
				if(up(board[i][j])){
					string t = "";
					if(board[i][j] != 'P')
						t += board[i][j];
					t += static_cast<char>('a'+j);
					t += static_cast<char>(8-i+'0');
					white.push_back(t);
				}else{
					string t = "";
					if(board[i][j] != 'p')
						t += board[i][j]-32;
					t += static_cast<char>('a'+j);
					t += static_cast<char>(8-i+'0');
					black.push_back(t);
				}
			}
		}
	}
	sort(white.begin(), white.end(), cmpwhite);
	sort(black.begin(), black.end(), cmpblack);
	cout << "White: ";
	for(int i = 0; i < white.size(); i++)
		cout << white[i] << (i == white.size()-1 ? "" : ",");
	cout << endl;
	cout << "Black: ";
	for(int i = 0; i < black.size(); i++)
		cout << black[i] << (i == black.size()-1 ? "" : ",");
	cout << endl;
	return 0;
}