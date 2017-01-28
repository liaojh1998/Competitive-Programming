/*
ID: liaojh11
PROG: starry
LANG: C++
*/
//Title: Starry Night
//Type: Ad Hoc
//Complexity: O(clusters^2*(cluster size))
//Solution: 1 BFS all clusters and their 8 different starting corner points, 1 BFS through clusters^2 to see which clusters has the same size and shape, 1 BFS to fill letters. A time waster question.
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

struct cluster{
	bool found;
	char letter;
	int cornerx[8], cornery[8], size;
	//0 - TL, 1 - TR, 2 - RT, 3 - RB, 4 - BR, 5 - BL, 6 - LB, 7 - LT
}clusters[505];
int dirx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int diry[8] = {1, 0, -1, -1, -1, 0, 1, 1};
char ans[105][105];
int G[105][105];
void fillgraph(int i){
	queue<pair<int, int> > q;
	q.push(pair<int, int>(clusters[i].cornery[0], clusters[i].cornerx[0]));
	while(!q.empty()){
		pair<int, int> tmp = q.front(); q.pop();
		if(G[tmp.first][tmp.second] != 1) continue;
		G[tmp.first][tmp.second] = ans[tmp.first][tmp.second] = clusters[i].letter;
		for(int k = 0; k < 8; k++)
			if(G[tmp.first+diry[k]][tmp.second+dirx[k]] == 1)
				q.push(pair<int, int>(tmp.first+diry[k], tmp.second+dirx[k]));
	}
}
bool check(int a, int b){
	int possible = (1<<8)-1;
	bool checked[105][105];
	memset(checked, 0, sizeof(checked));
	queue<pair<int, int> > q;
	q.push(pair<int, int>(clusters[a].cornery[0], clusters[a].cornerx[0]));
	while(!q.empty() && possible){
		pair<int, int> temp = q.front(); q.pop();
		if(checked[temp.first][temp.second])
			continue;
		checked[temp.first][temp.second] = true;
		//0 - TL, 1 - TR, 2 - RT, 3 - RB, 4 - BR, 5 - BL, 6 - LB, 7 - LT
		int deltay = temp.first-clusters[a].cornery[0], deltax = temp.second-clusters[a].cornerx[0];
		if((possible & 1) && G[temp.first][temp.second]^G[clusters[b].cornery[0]+deltay][clusters[b].cornerx[0]+deltax])
			possible -= 1;
		if((possible & (1 << 1)) && G[temp.first][temp.second]^G[clusters[b].cornery[1]+deltay][clusters[b].cornerx[1]-deltax])
			possible -= (1 << 1);
		if((possible & (1 << 2)) && G[temp.first][temp.second]^G[clusters[b].cornery[2]+deltax][clusters[b].cornerx[2]-deltay])
			possible -= (1 << 2);
		if((possible & (1 << 3)) && G[temp.first][temp.second]^G[clusters[b].cornery[3]-deltax][clusters[b].cornerx[3]-deltay])
			possible -= (1 << 3);
		if((possible & (1 << 4)) && G[temp.first][temp.second]^G[clusters[b].cornery[4]-deltay][clusters[b].cornerx[4]-deltax])
			possible -= (1 << 4);
		if((possible & (1 << 5)) && G[temp.first][temp.second]^G[clusters[b].cornery[5]-deltay][clusters[b].cornerx[5]+deltax])
			possible -= (1 << 5);
		if((possible & (1 << 6)) && G[temp.first][temp.second]^G[clusters[b].cornery[6]-deltax][clusters[b].cornerx[6]+deltay])
			possible -= (1 << 6);
		if((possible & (1 << 7)) && G[temp.first][temp.second]^G[clusters[b].cornery[7]+deltax][clusters[b].cornerx[7]+deltay])
			possible -= (1 << 7);
		for(int i = 0; i < 8 && possible; i++)
			if(G[temp.first+diry[i]][temp.second+dirx[i]])
				q.push(pair<int, int>(temp.first+diry[i], temp.second+dirx[i]));
	}
	return possible;
}
void solve(){
	freopen("starry.in", "r", stdin);
	freopen("starry.out", "w", stdout);
	int W, H;
	readInt(W);
	readInt(H);
	bool checked[H+5][W+5];
	int ccount = 0;
	memset(checked, 0, sizeof(checked));
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++)
			G[i][j] = getchar()-'0';
		getchar();
	}
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			if(G[i][j] && !checked[i][j]){
				queue<pair<int, int> > q;
				fill_n(clusters[ccount].cornerx, 8, j);
				fill_n(clusters[ccount].cornery, 8, i);
				clusters[ccount].size = 0;
				q.push(pair<int, int>(i, j));
				while(!q.empty()){
					pair<int, int> cur = q.front(); q.pop();
					if(checked[cur.first][cur.second])
						continue;
					checked[cur.first][cur.second] = true;
					//0 - TL, 1 - TR, 2 - RT, 3 - RB, 4 - BR, 5 - BL, 6 - LB, 7 - LT
					if(cur.first == clusters[ccount].cornery[1] && cur.second > clusters[ccount].cornerx[1])
						clusters[ccount].cornerx[1] = cur.second;
					if(cur.second > clusters[ccount].cornerx[2] || (cur.second == clusters[ccount].cornerx[2] && cur.first < clusters[ccount].cornery[2])){
						clusters[ccount].cornerx[2] = cur.second;
						clusters[ccount].cornery[2] = cur.first;
					}
					if(cur.second > clusters[ccount].cornerx[3] || (cur.second == clusters[ccount].cornerx[3] && cur.first > clusters[ccount].cornery[3])){
						clusters[ccount].cornerx[3] = cur.second;
						clusters[ccount].cornery[3] = cur.first;
					}
					if(cur.first > clusters[ccount].cornery[4] || (cur.first == clusters[ccount].cornery[4] && cur.second > clusters[ccount].cornerx[4])){
						clusters[ccount].cornerx[4] = cur.second;
						clusters[ccount].cornery[4] = cur.first;
					}
					if(cur.first > clusters[ccount].cornery[5] || (cur.first == clusters[ccount].cornery[5] && cur.second < clusters[ccount].cornerx[5])){
						clusters[ccount].cornerx[5] = cur.second;
						clusters[ccount].cornery[5] = cur.first;
					}
					if(cur.second < clusters[ccount].cornerx[6] || (cur.second == clusters[ccount].cornerx[6] && cur.first > clusters[ccount].cornery[6])){
						clusters[ccount].cornerx[6] = cur.second;
						clusters[ccount].cornery[6] = cur.first;
					}
					if(cur.second < clusters[ccount].cornerx[7] || (cur.second == clusters[ccount].cornerx[7] && cur.first < clusters[ccount].cornery[7])){
						clusters[ccount].cornerx[7] = cur.second;
						clusters[ccount].cornery[7] = cur.first;
					}
					clusters[ccount].size++;
					for(int k = 0; k < 8; k++)
						if(G[cur.first+diry[k]][cur.second+dirx[k]])
							q.push(pair<int, int>(cur.first+diry[k], cur.second+dirx[k]));
				}
				ccount++;
			}
	char curletter = 'a';
	for(int i = 0; i < ccount; i++)
		if(!clusters[i].found){
			clusters[i].found = true;
			clusters[i].letter = curletter++;
			for(int j = i+1; j < ccount; j++)
				if(clusters[i].size == clusters[j].size)
					if(check(i, j)){
						clusters[j].found = true;
						clusters[j].letter = clusters[i].letter;
					}
		}
	for(int i = 0; i < ccount; i++)
		fillgraph(i);
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			printf("%c%s", ans[i][j] ? ans[i][j] : '0', j == W ? "\n" : "");
}
int main(){
	solve();
	return 0;
}