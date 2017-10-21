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
		while(c < 33 && ~c) c = getchar();
		while(c != 10 && c != 32 && ~c){
			str[len] = c;
			c = getchar();
			len++;
		}
		str[len] = '\0';
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

vector<int> edges[1005];
int dpamount[1005][2];
double val[1005], dp[1005][2];

pair<int, double> dfs(int index, bool matched){
	if(dpamount[index][matched] != -1)
		return pair<int, double>(dpamount[index][matched], dp[index][matched]);
	pair<int, double> ans;
	ans.first = 0;
	ans.second = 0;
	int size = edges[index].size(), v;
	if(!matched && size){
		int amount[size], totalsum = 0;
		double pos[size], sum = 0;
		pair<int, double> temp;
		memset(pos, 0, sizeof(pos));
		memset(amount, 0, sizeof(amount));
		for(int i = 0; i < size; i++){
			v = edges[index][i];
			temp = dfs(v, false);
			amount[i] = temp.first;
			totalsum += amount[i];
			pos[i] = temp.second;
			sum += pos[i];
		}
		ans = pair<int, double>(totalsum, sum);
		for(int i = 0; i < size; i++){
			v = edges[index][i];
			temp = dfs(v, true);
			if(totalsum-amount[i]+temp.first+1 > ans.first || (totalsum-amount[i]+temp.first+1 == ans.first && sum-pos[i]+temp.second+min(val[v], val[index]) > ans.second))
				ans = pair<int, double>(totalsum-amount[i]+temp.first+1, sum-pos[i]+temp.second+min(val[v], val[index]));
		}
	}else{
		for(int i = 0; i < size; i++){
			v = edges[index][i];
			pair<int, double> cur = dfs(v, false);
			ans.first += cur.first;
			ans.second += cur.second;
		}
	}
	dpamount[index][matched] = ans.first;
	dp[index][matched] = ans.second;
	return ans;
}

void FastIO::solve(){
	//Target more matching first, then greater average speed
	int N;
	int c = 1;
	readInt(N);
	unordered_map<string, int> people;
	people["CEO"] = 0;
	for(int i = 0; i < N; i++){
		string a, b;
		cin >> a;
		if(!people.count(a)){
			readDouble(val[c]);
			people[a] = c++;
		}else
			readDouble(val[people[a]]);
		cin >> b;
		if(!people.count(b))
			people[b] = c++;
		edges[people[b]].push_back(people[a]);
	}
	memset(dpamount, -1, sizeof(dpamount));
	pair<int, double> ans = dfs(0, 1);
	printf("%d %.6lf\n", ans.first, ans.second/ans.first);
}