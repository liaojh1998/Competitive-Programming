//Title: Colors
//Type: Brute Force
//Complexity: O(NlogN)
//Solution: Convert base 16 to base 10 then sort euclidean distance
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
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
	if(!(~c)) return -1;
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
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

double cvrt(char a, char b){
	double first, second;
	if(a >= '0' && a <= '9')
		first = a - '0';
	else
		first = a - 'A' + 10;
	if(b >= '0' && b <= '9')
		second = b - '0';
	else second = b - 'A' + 10;
	return first*16+second;
}
#define dist(r1, g1, b1, r2, g2, b2) sqrt((r2-r1)*(r2-r1) + (g2-g1)*(g2-g1) + (b2-b1)*(b2-b1))
double dist[10005];
char query[10], colors[10005][10];
bool cmp(int a, int b){
	if(dist[a] == dist[b])
		for(int i = 0; i < 7; i++)
			if(colors[a][i] != colors[b][i])
				return colors[a][i] < colors[b][i];
	return dist[a] < dist[b];
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	readInt(T);
	while(T--){
		memset(dist, 0, sizeof(dist));
		int N;
		readInt(N);
		int arr[N];
		readStr(query);
		double qr = cvrt(query[1], query[2]);
		double qg = cvrt(query[3], query[4]);
		double qb = cvrt(query[5], query[6]);
		//printf("%lf %lf %lf\n", qr, qg, qb);
		for(int i = 0; i < N; i++){
			readStr(colors[i]);
			double r = cvrt(colors[i][1], colors[i][2]);
			double g = cvrt(colors[i][3], colors[i][4]);
			double b = cvrt(colors[i][5], colors[i][6]);
			//printf("%lf %lf %lf\n", r, g, b);
			dist[i] = dist(qr, qg, qb, r, g, b);
			//printf("%lf\n", dist[i]);
			arr[i] = i;
		}
		sort(arr, arr+N, cmp);
		printf("Case %s:\n", query);
		for(int i = 0; i < N; i++)
			printf("%s\n", colors[arr[i]]);
	}
	return 0;
}