//Title: Snake
//Type: Computational Geometry
//Solution: Never done segment trees before, suppose might try it for this problem. Read the code for solution.
#include <cstdio>
#include <algorithm>
using namespace std;
struct points{int x, y, i;} p[10001], po[10001];
struct tree{int left, right;} rtree[5001], ctree[5001];
int N, rlen, clen, connect[10001];
bool cmpr(const points &a, const points &b){return (a.y < b.y)||(a.y == b.y && a.x < b.x);}
bool cmpc(const points &a, const points &b){return (a.x < b.x)||(a.x == b.x && a.y < b.y);}
//Find all segments parallel to the x-axis and record them in the x-axis segments array, O(N/2)
//Why pairs of points? Because only pairs can fit the rule that all consecutive segments form a 90 degree
int row(){
	sort(p, p + N, cmpr);
	//Since sorted, search in pairs
	for(int i = 1; i < N; i+=2){
		if(p[i].y == p[i-1].y){
			rtree[rlen].left = p[i-1].i;
			rtree[rlen].right = p[i].i;
			rlen++;
		}else
			return false;
	}
	return true;
}
//Same as above to segments parallel to y-axis
int col(){
	sort(p, p + N, cmpc);
	for(int i = 1; i < N; i+=2){
		if(p[i].x == p[i-1].x){
			ctree[clen].left = p[i-1].i;
			ctree[clen].right = p[i].i;
			clen++;
		}else
			return false;
	}
	return true;
}
int search(int i){
	if(i == connect[i]) return i;
	connect[i] = search(connect[i]);
	return connect[i];
}
//Build the segment tree and see if it connects all the way to the first point
int connectable(){
	//x-axis, O(N/2)
	for(int i = 0; i < rlen; i++){
		int a = search(rtree[i].left), b = search(rtree[i].right);
		connect[max(a, b)] = min(a, b);
	}
	//y-axis, O(N/2 * log(N/2))
	for(int i = 0; i < clen; i++){
		int a = search(ctree[i].left), b = search(ctree[i].right);
		connect[max(a, b)] = min(a, b);
	}
	//Check if connected, O(N * logN)
	for(int i = 0; i < N; i++){
		search(i);
		if(connect[i]) return false;
	}
	return true;
}
//Check if they crossed each other, O((N/2)^2)
int crossed(){
	for(int i = 0; i < rlen; i++){
		for(int j = 0; j < clen; j++){
			int rl = rtree[i].left, rr = rtree[i].right, cl = ctree[j].left, cr = ctree[j].right;
			if(po[rl].x < po[cl].x && po[rr].x > po[cr].x)
				if(po[rl].y > po[cl].y && po[rr].y < po[cr].y)
					return true;
		}
	}
	return false;
}
//Finally, count the length of the whole snake, O(N)
int count(){
	int total = 0;
	for(int i = 0; i < rlen; i++) total+= po[rtree[i].right].x - po[rtree[i].left].x;
	for(int i = 0; i < clen; i++) total+= po[ctree[i].right].y - po[ctree[i].left].y;
	return total;
}
int main(){
	//Instantiation
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].i = connect[i] = i;
		po[i] = p[i];
	}
	//Check everything
	//Only even number of points will create a possible snake.
	//The number of x-axis segments should equal y-axis segments
	if(!(N&1) && row() && col() && (rlen == clen) && connectable() && !crossed())
		printf("%d\n", count());
	else
		printf("0\n");
	return 0;
}