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

class cmp{
public:
	bool operator()(const pair<int, pair<int, long long> >& a, const pair<int, pair<int, long long> >& b) const{
		return a.second.second < b.second.second;
	}
};

void FastIO::solve(){
	int T, N, D;
	readInt(T);
	while(T--){
		readInt(N);
		readInt(D);
		pair<int, pair<int, long long> > mat[N];
		for(int i = 0; i < N; i++){
			readInt(mat[i].first);
			readInt(mat[i].second.first);
			readLL(mat[i].second.second);
		}
		sort(mat, mat+N);
		priority_queue<pair<int, pair<int, long long> >, vector<pair<int, pair<int, long long> > >, cmp> q;
		int cur = 0;
		for(int i = 0; i < N; i++){
			while(!q.empty() && q.top().second.first <= mat[i].first-cur){
				cur += q.top().second.first;
				q.pop();
			}
			if(!q.empty() && q.top().second.first > mat[i].first-cur){
				pair<int, pair<int, long long> > temp = q.top(); q.pop();
				temp.second.first -= mat[i].first-cur;
				q.push(temp);
			}
			q.push(mat[i]);
			cur = mat[i].first;
		}
		D++;
		while(!q.empty() && cur < D){
			if(cur+q.top().second.first <= D){
				cur += q.top().second.first;
				q.pop();
			}else{
				pair<int, pair<int, long long> > temp = q.top(); q.pop();
				temp.second.first -= D-cur;
				cur = D;
				q.push(temp);
			}
		}
		long long ans = 0;
		while(!q.empty()){
			ans += q.top().second.second*q.top().second.first;
			q.pop();
		}
		printf("%lld\n", ans);
	}
}