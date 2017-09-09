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
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
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

char str[100][1000];
bool cmp(const pair<long long, int>& a, const pair<long long, int>& b){
	for(int i = 0; i < strlen(str[a.second]) && i < strlen(str[b.second]); i++)
		if(str[a.second][i] != str[b.second][i])
			return str[a.second][i] < str[b.second][i];
	return strlen(str[a.second]) < strlen(str[b.second]);
}

void FastIO::solve(){
	long long R, D;
	int G;
	readLL(R);
	readInt(G);
	readLL(D);
	long long a[G], b[G], c[G];
	for(int i = 0; i < G; i++){
		readStr(str[i]);
		readLL(a[i]);
		readLL(b[i]);
		readLL(c[i]);
	}
	long long lo = 0, hi = R+1, mid;
	while(lo < hi){
		long long mid = (lo+hi)/2, cost = 0;
		for(int i = 0; i < G; i++)
			if((mid*a[i]-b[i]) > 0)
				cost += c[i]*(mid*a[i]-b[i]);
		if(cost <= D)
			lo = mid + 1;
		else
			hi = mid;
	}
	printf("%lld\n", lo ? lo-1 : lo);
	pair<long long, int> ans[G];
	for(int i = 0; i < G; i++){
		ans[i].first = lo && ((lo-1)*a[i]-b[i] > 0) ? (lo-1)*a[i]-b[i] : 0;
		ans[i].second = i;
	}
	sort(ans, ans+G, cmp);
	for(int i = 0; i < G; i++)
		printf("%s %lld\n", str[ans[i].second], ans[i].first);
}