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

void FastIO::solve(){
	//Lesson learned: If proven the right logic, start by debugging algorithm with test cases to ensure the output is correct instead of looking for a spoof in the proof.
	//Very interesting tip: The test cases actually have no multiple edges from one vertex to another (problem setters tricked us!), which means the lower_bound is actually not needed, simple push_back works!
	int T, N, M, u, v, size, c;
	vector<int>::iterator loc;
	bool impossible, next;
	readInt(T);
	while(T--){
		readInt(N);
		readInt(M);
		vector<int> edges[N+1];
		impossible = false;
		for(int i = 0; i < M; i++){
			readInt(u);
			readInt(v);
			if(u >= v)
				impossible = true;
			loc = lower_bound(edges[u].begin(), edges[u].end(), v);
			if(loc != edges[u].end() && *loc == v)
				impossible = true;
			else
				edges[u].insert(loc, v);
		}
		if(impossible){
			printf("-1\n");
			continue;
		}
		int str[N+1];
		memset(str, 0, sizeof(str));
		size = edges[0].size();
		c = 1;
		for(int i = 0; i < size; i++)
			str[edges[0][i]] = c++;
		int m[c];
		bool checked[c];
		memset(checked, 0, sizeof(checked));
		for(int i = 0; i < size; i++)
			m[i+1] = edges[0][i];
		for(int i = 1; i <= N && !impossible; i++)
			if(!str[i] || m[str[i]] != i)
				impossible = true;
			else{
				m[str[i]] = -1;
				next = false;
				size = edges[i].size();
				for(int j = 0; j < size && !impossible; j++)
					if(str[edges[i][j]]){
						if(m[str[edges[i][j]]] != edges[i][j])
							impossible = true;
						else
							checked[str[edges[i][j]]] = true;
					}else{
						if(next)
							impossible = true;
						else{
							str[edges[i][j]] = str[i];
							m[str[i]] = edges[i][j];
							checked[str[i]] = true;
							next = true;
						}
					}
				for(int j = 1; j < c && !impossible; j++)
					if(m[j] != -1 && !checked[j])
						impossible = true;
					else if(checked[j])
						checked[j] = false;
			}
		if(impossible)
			printf("-1\n");
		else
			for(int i = 1; i <= N; i++)
				printf("%d%s", str[i], i != N ? " " : "\n");
	}
}