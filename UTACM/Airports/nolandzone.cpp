#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(!(~c)) return -1;
	if(c == '-') neg = true, c = getchar();
	if(c != '.'){
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
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
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	if(!(~c)) return -1;
	//32 if stop at space, 10 if stop at next line
	while(c != 10 && c != 32 && ~c){
		str[len++] = c;
		c = getchar();
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
void readIntArr(int *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readInt(n[i]))){
			n[i] = 0;
			return;
		}
}
void readLLArr(long long *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readLL(n[i]))){
			n[i] = 0;
			return;
		}
}
void readDoubleArr(double *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readDouble(n[i]))){
			n[i] = 0;
			return;
		}
}

#define INF (2500)
long long getNum(char i){
	if(i >= 'A' && i <= 'Z')
		return i - 'A';
	return i-'a'+26;
}
long long exp52[10] = {1, 52, 52*52, 52*52*52, 52*52*52*52, 52*52*52*52*52, (long long)52*52*52*52*52*52, (long long)52*52*52*52*52*52*52, (long long)52*52*52*52*52*52*52*52, (long long)52*52*52*52*52*52*52*52*52};
long long hashing(char *str){
	long long sum = 0, size = strlen(str);
	for(int i = 0; i < size; i++)
		sum += getNum(str[i])*exp52[i];
	return sum;
}
struct path{
	int v1, v2, weight;
	path(int a, int b, int c){
		v1 = a;
		v2 = b;
		weight = c;
	}
};
class cmp{
	public:
	bool operator()(const path *a, const path *b){
		//Change this if not shortest-path
		return a->weight > b->weight;
	}
};
bool check(const int &a, const int &b){
	return a < b;
}
void solve(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	readInt(T);
	while(T--){
		int F, R, Q;
		readInt(F);
		readInt(R);
		readInt(Q);
		map<long long, int> cities[50];
		map<long long, int> countries;
		int citysize[50], countrysize = 0, u1, u2, v1, v2;
		memset(citysize, 0, sizeof(citysize));
		pair<int, int>* G[50][50][200];
		int Gsize[50][50];
		memset(Gsize, 0, sizeof(Gsize));
		char city[15], country[15], trash[15];
		for(int i = 0; i < F; i++){
			readStr(city);
			readStr(country);
			readStr(trash);
			long long cihash = hashing(city);
			long long cohash = hashing(country);
			if(countries.count(cohash))
				u1 = countries[cohash];
			else{
				u1 = countrysize++;
				countries[cohash] = u1;
			}
			if(cities[u1].count(cihash))
				u2 = cities[u1][cihash];
			else{
				u2 = citysize[u1]++;
				cities[u1][cihash] = u2;
			}
			/*printf("%s %d\n", country, u1);
			printf("%s %d %d\n", city, u1, u2);*/
			readStr(city);
			readStr(country);
			cihash = hashing(city);
			cohash = hashing(country);
			if(countries.count(cohash))
				v1 = countries[cohash];
			else{
				v1 = countrysize++;
				countries[cohash] = v1;
			}
			if(cities[v1].count(cihash))
				v2 = cities[v1][cihash];
			else{
				v2 = citysize[v1]++;
				cities[v1][cihash] = v2;
			}
			/*printf("%s %d\n", country, v1);
			printf("%s %d %d\n", city, v1, v2);*/
			G[u1][u2][Gsize[u1][u2]++] = new pair<int, int>(v1, v2);
		}
		bool banned[100][100];
		memset(banned, 0, sizeof(banned));
		for(int i = 0; i < R; i++){
			readStr(country);
			long long c1hash = hashing(country);
			readStr(trash);
			readStr(country);
			long long c2hash = hashing(country);
			if(!countries.count(c1hash))
				countries[c1hash] = countrysize++;
			if(!countries.count(c2hash))
				countries[c2hash] = countrysize++;
			banned[countries[c1hash]][countries[c2hash]] = true;
		}
		int sp[50][50], na;
		bool checked[50][50], queued[50][50];
		char nationality[15];
		for(int i = 0; i < Q; i++){
			readStr(nationality);
			na = countries[hashing(nationality)];
			u1 = u2 = v1 = v2 = -1;
			readStr(city);
			readStr(country);
			long long cohash = hashing(country);
			if(countries.count(cohash))
				u1 = countries[cohash];
			long long cihash = hashing(city);
			if(u1 != -1 && cities[u1].count(cihash))
				u2 = cities[u1][cihash];
			readStr(trash);
			readStr(city);
			readStr(country);
			cohash = hashing(country);
			if(countries.count(cohash))
				v1 = countries[cohash];
			cihash = hashing(city);
			if(v1 != -1 && cities[v1].count(cihash))
				v2 = cities[v1][cihash];
			if((u1 == -1) || (u2 == -1) || (v1 == -1) || (v2 == -1) || (banned[na][v1] && u1 != v1)){
				printf("IMPOSSIBLE\n");
				continue;
			}
			memset(sp, -1, sizeof(sp));
			memset(checked, 0, sizeof(checked));
			memset(queued, 0, sizeof(queued));
			priority_queue<path*, vector<path*>, cmp> q;
			sp[u1][u2] = 0;
			q.push(new path(u1, u2, 0));
			checked[u1][u2] = true;
			bool found = false;
			while(!q.empty() && !found){
				path* p = q.top(); q.pop();
				int ut1 = p->v1;
				int ut2 = p->v2;
				queued[ut1][ut2] = false;
				int len = Gsize[ut1][ut2];
				for(int k = 0; k < len && !found; k++){
					int vt1 = G[ut1][ut2][k]->first;
					int vt2 = G[ut1][ut2][k]->second;
					if((ut1 == vt1 || !banned[na][vt1]) && (!checked[vt1][vt2] || check(p->weight + 1, sp[vt1][vt2]))){
						checked[vt1][vt2] = true;
						sp[vt1][vt2] = p->weight + 1;
						if(vt1 == v1 && vt2 == v2)
							found = true;
						if(!queued[vt1][vt2]){
							queued[vt1][vt2] = true;
							q.push(new path(vt1, vt2, sp[vt1][vt2]));
						}
					}
				}
				delete p;
			}
			if(sp[v1][v2] == -1)
				printf("IMPOSSIBLE\n");
			else
				printf("%d\n", sp[v1][v2]-1);
		}
		/*printf("%d\n", countrysize);
		for(int i = 0; i < countrysize; i++){
			printf("%d ", citysize[i]);
		}*/
		if(T > 0)
			printf("\n");
	}
}
int main(){
	solve();
	return 0;
}