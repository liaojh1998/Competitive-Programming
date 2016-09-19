//Title: Terminator
//Type: BFS, kinda not simulatable since Terminator can destroy obstacles
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct coord{int x, y;} c;
queue<coord> q;
int T, N, x, y, t[32][32], p[32][32];
int vx[8] = {-1, 0, 1, 1, 1, 0, -1, -1}, vy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
char map[32][32];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &x, &y);
		x+= (N-1)/2;
		y+= (N-1)/2;
		//Case: your car is not even on the map, feels bad kappa
		if(x < 0 || y < 0 || x >= N || y >= N){
			getchar();
			for(int i = 0; i < N; i++)
				scanf("%s");
			printf("TERMINATED\n");
		}
		//Terminator that destroys obstacles...
		c.x = 0;
		c.y = (N-1)/2;
		q.push(c);
		memset(t, 1, sizeof(t));
		t[0][(N-1)/2] = 0;
		while(!q.empty()){
			c = q.front();
			q.pop();
			for(int i = 0; i < 8; i++)
				if(c.x+vx[i] >= 0 && c.x+vx[i] < N && c.y+vy[i] >= 0 && c.y+vy[i] < N && t[c.x+vx[i]][c.y+vy[i]] > t[c.x][c.y] + 1){
					t[c.x+vx[i]][c.y+vy[i]] = t[c.x][c.y] + 1;
					coord temp;
					temp.x = c.x+vx[i];
					temp.y = c.y+vy[i];
					q.push(temp);
				}
		}
		//Scan map
		getchar();
		for(int i = N-1; i >= 0; i--){
			for(int j = 0; j < N; j++)
				scanf("%c", &map[j][i]);
			getchar();
		}
		//Person that is blocked by obstacles...
		c.x = c.y = (N-1)/2;
		q.push(c);
		memset(p, 1, sizeof(p));
		p[(N-1)/2][(N-1)/2] = 0;
		while(!q.empty()){
			c = q.front();
			q.pop();
			for(int i = 0; i < 8; i++)
				if(c.x+vx[i] >= 0 && c.x+vx[i] < N && c.y+vy[i] >= 0 && c.y+vy[i] < N && map[c.x+vx[i]][c.y+vy[i]] == '.' && p[c.x+vx[i]][c.y+vy[i]] > p[c.x][c.y] + 1){
					p[c.x+vx[i]][c.y+vy[i]] = p[c.x][c.y] + 1;
					coord temp;
					temp.x = c.x+vx[i];
					temp.y = c.y+vy[i];
					q.push(temp);
				}
		}
		if(p[x][y] < t[x][y])
			printf("ESCAPED\n");
		else
			printf("TERMINATED\n");
	}
	return 0;
}