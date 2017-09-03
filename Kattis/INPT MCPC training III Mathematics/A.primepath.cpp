#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
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
	bool primes[10000];
	memset(primes, 1, sizeof(primes));
	for(int i = 2; i*i < 10000; i++)
		if(primes[i])
			for(int j = 2; i*j < 10000; j++)
				primes[i*j] = false;
	int N, start, end;
	bool queued[10000];
	readInt(N);
	while(N--){
		readInt(start);
		readInt(end);
		if(!primes[start] || !primes[end])
			printf("Impossible\n");
		else{
			memset(queued, 0, sizeof(queued));
			queue<pair<int, int>> q;
			queued[start] = true;
			q.push(pair<int, int>(start, 0));
			while(!q.empty()){
				pair<int, int> t = q.front(); q.pop();
				if(t.first == end){
					printf("%d\n", t.second);
					break;
				}
				int div = 10;
				for(int i = 0; i < 4; i++){
					for(int j = i == 3 ? 1 : 0; j < 10; j++){
						int next = t.first/div*div + j*(div/10) + t.first%(div/10);
						if(primes[next] && !queued[next]){
							q.push(pair<int, int>(next, t.second+1));
							queued[next] = true;
						}
					}
					div *= 10;
				}
			}
		}
	}
}