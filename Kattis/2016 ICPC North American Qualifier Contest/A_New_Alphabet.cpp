#include <bits/stdc++.h>
using namespace std;

string match(char a){
	switch(a){
		case 'a': return "@"; break;
		case 'b': return "8"; break;
		case 'c': return "("; break;
		case 'd': return "|)"; break;
		case 'e': return "3"; break;
		case 'f': return "#"; break;
		case 'g': return "6"; break;
		case 'h': return "[-]"; break;
		case 'i': return "|"; break;
		case 'j': return "_|"; break;
		case 'k': return "|<"; break;
		case 'l': return "1"; break;
		case 'm': return "[]\\/[]"; break;
		case 'n': return "[]\\[]"; break;
		case 'o': return "0"; break;
		case 'p': return "|D"; break;
		case 'q': return "(,)"; break;
		case 'r': return "|Z"; break;
		case 's': return "$"; break;
		case 't': return "']['"; break;
		case 'u': return "|_|"; break;
		case 'v': return "\\/"; break;
		case 'w': return "\\/\\/"; break;
		case 'x': return "}{"; break;
		case 'y': return "`/"; break;
		case 'z': return "2"; break;
	}
	string s;
	s += a;
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, ans;
	getline(cin, s);
	for(int i = 0; i < s.size(); i++)
		ans += match(tolower(s[i]));
	cout << ans << endl;
	return 0;
}