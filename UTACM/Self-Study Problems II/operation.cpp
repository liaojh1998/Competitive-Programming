#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N;
double stx, sty, speed, mintime;
struct ves{
	double initx, inity, vx, vy;
}vessels[8];
double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
void dfs(double startx, double starty, bool* checked, double time, vector<int> seq){
	bool has = false;
	for(int i = 0; i < N; i++){
		if(!checked[i]){
			has = true;
			checked[i] = true;
			double nexttime = dist(startx, starty, vessels[i].initx+vessels[i].vx*time, vessels[i].inity+vessels[i].vy*time)/speed;
			seq.push_back(i);
			printf("%d %lf\n", i, time + nexttime + 3600);
			dfs(vessels[i].initx, vessels[i].inity, checked, time+nexttime+3600, seq);
			checked[i] = false;
			seq.pop_back();
		}
	}
	if(!has){
		for(int i = 0; i < seq.size(); i++)
			printf("%d ", seq[i]);
		printf("\n");
		mintime = min(mintime, time + dist(startx, starty, stx, sty)/speed);
		printf("%lf\n", time + dist(startx, starty, stx, sty)/speed);
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cas = 0;
	while(scanf("%d", &N) && N){
		mintime = 1<<28;
		cas++;
		for(int i = 0; i < N; i++){
			scanf("%lf%lf%lf%lf", &vessels[i].initx, &vessels[i].inity, &vessels[i].vx, &vessels[i].vy);
			vessels[i].vx /= 3600;
			vessels[i].vy /= 3600;
		}
		scanf("%lf%lf%lf", &stx, &sty, &speed);
		speed /= 3600;
		bool checked[N];
		memset(checked, 0, sizeof(checked));
		vector<int> seq;
		dfs(stx, sty, checked, 0, seq);
		printf("%lf\n", mintime);
		printf("Case %d: %d hour(s) %d minute(s) %d second(s)\n", cas, ((int)mintime/3600), (((int)mintime%3600)/60), (((int)mintime%3600)%60));
	}
	return 0;
}