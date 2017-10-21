#include <bits/stdc++.h>
using namespace std;

class FastIO{
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
	int T;
	readInt(T);
	while(T--){
		int l1, a1, l2, a2, lt, at;
		readInt(l1);
		readInt(a1);
		readInt(l2);
		readInt(a2);
		readInt(lt);
		readInt(at);
		int sol = 0, x, y;
		//AT LEAST 1 TYPE IN EACH GROUP TFW
		for(int i = 1; at-a1*i >= a2; i++)
			if(!((at-a1*i)%a2) && l1*i+l2*((at-a1*i)/a2) == lt){
				x = i;
				y = (at-a1*i)/a2;
				sol++;
			}
		if(sol == 1)
			printf("%d %d\n", x, y);
		else
			printf("?\n");
	}
}