/*
ID: liaojh11
PROG: camelot
LANG: C++
*/
//Title: camelot
//Type: BFS
//Solution: Trying so hard
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
char temp;
int R, C, Kc, Kr, kcount, dist[4][31][27], kr[4], kc[4], akr, akc;
int kdirc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int kdirr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
struct p{
	int k, r, c, p;
}pt, pt2;
queue<p> q;
int main(){
	//Instantiation
	fin >> R >> C;
	fin >> temp >> Kr;
	Kc = temp - 64;
	while(!fin.eof()){
		fin >> temp >> kr[kcount];
		kc[kcount] = temp - 64;
		kcount++;
	}
	for(int i = 0; i < kcount; i++){
		for(int j = 0; j <= R; j++){
			for(int k = 0; k <= C; k++){
				dist[i][j][k] = -1;
			}
		}
	}
	for(int i = 0; i < kcount; i++){
		dist[i][kr[i]][kc[i]] = 0;
		pt.k = i;
		pt.r = kr[i];
		pt.c = kc[i];
		q.push(pt);
	}
	//BFS for knights only
	while(!q.empty()){
		pt = q.front();
		q.pop();
		bool br = 1;
		for(int i = 0; i < kcount; i++){
			if(dist[i][pt.r][pt.c] == -1){
				br = 0;
				break;
			}
		}
		if(br){
			akr = pt.r;
			akc = pt.c;
			break;
		}
		for(int i = 0; i < 8; i++){
			pt2.k = pt.k;
			pt2.r = pt.r+kdirr[i];
			pt2.c = pt.c+kdirc[i];
			if(pt.r+kdirr[i] >= 1 && pt.r+kdirr[i] <= R && pt.c+kdirc[i] >= 1 && pt.c+kdirc[i] <= C
				&& dist[pt.k][pt.r+kdirr[i]][pt.c+kdirc[i]] == -1){
				dist[pt.k][pt.r+kdirr[i]][pt.c+kdirc[i]] = dist[pt.k][pt.r][pt.c]+1;
				q.push(pt2);
			}
		}
	}
	return 0;
}