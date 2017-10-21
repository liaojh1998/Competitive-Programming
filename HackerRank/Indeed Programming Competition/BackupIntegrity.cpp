#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
	//inline if read speed is needed, huge compilation time required though
	//safe no fread implementation
	int readInt(int &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readLL(long long &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readDouble(double &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; c != '.' && ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c != '.' && c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
		double div = 1;
		for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
		n /= div;
		if(neg) n = -n;
		return 1;
	}
	int readStr(char *str){
		register char c = getchar();
		register int len = 0;
		if(!(~c)) return -1;
		while(c < 33 && ~c) c = getchar(); //32 if space should be included
		//32 if stop at space, 10 if stop at next line
		while(c != 10 && c != 32 && ~c){
			str[len] = c;
			c = getchar();
			len++;
		}
		str[len] = '\0';
		//Just in case if needs to return arriving at end of line
		//if(c == 10) return 10;
		return 1;
	}
	int readStr(char *str, int len){
		//Reading string of size len
		for(int i = 0; i < len; i++){
			str[i] = getchar();
			if(!(~str[i])){
				str[i] = '\0';
				return -1;
			}
			//Remove this if str can't go to next line
			/*if(str[i] == 10){
				str[i] = '\0';
				return 10;
			}*/
		}
		str[len] = '\0';
		return 1;
	}

public:
	//Constructor, true if using file input/output, defaulted false
	FastIO(bool useFile = false){
		if(useFile){
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

vector<int> Nedges[15005], Medges[15005];

bool match(int nu, int mu){
	if(Nedges[nu].size() != Medges[mu].size())
		return false;
	int nsize = Nedges[nu].size(), msize = Medges[mu].size();
	bool matched[msize], valid = true;
	memset(matched, 0, sizeof(matched));
	for(int i = 0; i < nsize && valid; i++){
		bool possible = false;
		for(int j = 0; j < msize && !possible; j++){
			if(!matched[j]){
				possible = match(Nedges[nu][i], Medges[mu][j]);
				if(possible){
					matched[j] = true;
					//cout << nu << " " << mu << " " << i << " " << j << endl;
				}
			}
			//cout << i << " " << j << endl;
		}
		if(!possible)
			valid = false;
	}
	return valid;
}

void FastIO::solve(){
	int N, Ncount = 0;
	readInt(N);
	vector<int> Nhead;
	unordered_map<string, int> Nmap;
	string s, token, begin;
	while(N--){
		getline(cin, s);
		stringstream ss(s);
		getline(ss, begin, '/');
		begin += "/";
		if(!Nmap.count(begin)){
			Nmap[begin] = Ncount++;
			Nhead.push_back(Nmap[begin]);
			//cout << Nmap[begin] << " " << begin.substr(0, begin.size()-1) << endl;
		}
		int u = Nmap[begin], v;
		while(getline(ss, token, '/')){
			begin += token;
			if(!Nmap.count(begin)){
				Nmap[begin] = Ncount++;
				v = Nmap[begin];
				Nedges[u].push_back(v);
				u = v;
				//cout << u << " " << token << endl;
			}else
				u = Nmap[begin];
		}
	}
	int M, Mcount = 0;
	readInt(M);
	vector<int> Mhead;
	unordered_map<string, int> Mmap;
	while(M--){
		getline(cin, s);
		stringstream ss(s);
		getline(ss, begin, '/');
		begin += "/";
		if(!Mmap.count(begin)){
			Mmap[begin] = Mcount++;
			Mhead.push_back(Mmap[begin]);
			//cout << Mmap[begin] << " " << begin.substr(0, begin.size()-1) << endl;
		}
		int u = Mmap[begin], v;
		while(getline(ss, token, '/')){
			begin += token;
			if(!Mmap.count(begin)){
				Mmap[begin] = Mcount++;
				v = Mmap[begin];
				Medges[u].push_back(v);
				u = v;
				//cout << u << " " << token << endl;
			}else
				u = Mmap[begin];
		}
	}
	bool valid = true;
	if(N != M || Nhead.size() != Mhead.size())
		valid = false;
	int nsize = Nhead.size(), msize = Mhead.size();
	bool matched[msize];
	memset(matched, 0, sizeof(matched));
	for(int i = 0; i < nsize && valid; i++){
		bool possible = false;
		for(int j = 0; j < msize && !possible; j++){
			if(!matched[j]){
				possible = match(Nhead[i], Mhead[j]);
				if(possible){
					matched[j] = true;
					//cout << i << " " << j << endl;
				}
			}
			//cout << i << " " << j << endl;
		}
		if(!possible)
			valid = false;
	}
	printf("%s\n", valid ? "OK" : "INVALID");
}