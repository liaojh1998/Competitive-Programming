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
	int T, N, M, nextx, nexty;
	int x[4] = {1, 0, -1, 0};
	int y[4] = {0, -1, 0, 1};
	readInt(T);
	while(T--){
		readInt(N);
		readInt(M);
		int PF[N][M], PT[N][M], sumPF[N][M], sumPT[N][M];
		bool queued[N][M];
		memset(sumPF, 1, sizeof(sumPF));
		memset(queued, 0, sizeof(queued));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				readInt(PF[i][j]);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				readInt(PT[i][j]);
		sumPF[0][0] = PF[0][0];
		sumPT[0][0] = PT[0][0];
		queued[0][0] = true;
		queue<pair<int, int> > q;
		q.push(pair<int, int>(0, 0));
		while(!q.empty()){
			pair<int, int> temp = q.front(); q.pop();
			queued[temp.first][temp.second] = false;
			for(int i = 0; i < 4; i++){
				nexty = temp.first+y[i];
				nextx = temp.second+x[i];
				if(nextx >= 0 && nextx < M && nexty >= 0 && nexty < N){
					if(sumPF[nexty][nextx] > PF[nexty][nextx]+sumPF[temp.first][temp.second]){
						sumPF[nexty][nextx] = PF[nexty][nextx]+sumPF[temp.first][temp.second];
						sumPT[nexty][nextx] = PT[nexty][nextx]+sumPT[temp.first][temp.second];
						if(!queued[nexty][nextx]){
							queued[nexty][nextx] = true;
							q.push(pair<int, int>(nexty, nextx));
						}
					}else if((sumPF[nexty][nextx] == PF[nexty][nextx]+sumPF[temp.first][temp.second]) && (sumPT[nexty][nextx] > PT[nexty][nextx]+sumPT[temp.first][temp.second])){
						sumPT[nexty][nextx] = PT[nexty][nextx]+sumPT[temp.first][temp.second];
						if(!queued[nexty][nextx]){
							queued[nexty][nextx] = true;
							q.push(pair<int, int>(nexty, nextx));
						}
					}
				}
			}
		}
		printf("%d %d\n", sumPF[N-1][M-1], sumPT[N-1][M-1]);
	}
}