//Simple Computational Geometry, yet tedious af, UGH
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
int P;
struct o{
	char type;
	double x1, y1, x2, y2;
}objects[101];
struct vec{
	int last;
	double startx, starty, vx, vy;
};
double dist(double x1, double y1, double x2, double y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
double dotprod(double x1, double y1, double x2, double y2){
	return x1*x2 + y1*y2;
}
bool between(double x, double x1, double x2, double y, double y1, double y2){
	if(x2 < x1){
		double t = x1;
		x1 = x2;
		x2 = t;
	}
	if(y2 < y1){
		double t = y2;
		y2 = y1;
		y1 = t;
	}
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		double startx, starty, vx, vy;
		scanf("%lf,%lf%lf,%lf", &startx, &starty, &vx, &vy);
		scanf("%d", &P);
		for(int i = 1; i <= P; i++){
			getchar();
			scanf("%c", &objects[i].type);
			scanf("%lf,%lf%lf,%lf", &objects[i].x1, &objects[i].y1, &objects[i].x2, &objects[i].y2);
		}
		set<int> data;
		vec start;
		start.startx = startx;
		start.starty = starty;
		start.vx = vx;
		start.vy = vy;
		start.last = 0;
		queue<vec> q;
		q.push(start);
		while(!q.empty()){
			vec tmp = q.front(); q.pop();
			if(tmp.vx == 0 && tmp.vy == 0) continue;
			//Which object is first hit?
			int next = 0;
			double endx, endy, cur = 1<<28;
			for(int i = 1; i <= P; i++){
				if(i != tmp.last){
					double t, tendx, tendy, m1 = objects[i].x2 - objects[i].x1, m2 = objects[i].y2 - objects[i].y1;
					if(m1 == 0 && m2 == 0) continue; //Though I don't think there's such a case, keep it tho
					if(m1 == 0){
						if(tmp.vx == 0) continue; //Parallel case
						tendx = objects[i].x1;
						t = (objects[i].x1-tmp.startx)/tmp.vx;
						tendy = tmp.starty + tmp.vy*t;
					}else if(m2 == 0){
						if(tmp.vy == 0) continue; //Parallel case
						tendy = objects[i].y1;
						t = (objects[i].y1-tmp.starty)/tmp.vy;
						tendx = tmp.startx + tmp.vx*t;
					}else{
						if(tmp.vx/m1 == tmp.vy/m2) continue; //Parallel case
						double yint = (tmp.starty - objects[i].y1)/m2 - (tmp.startx - objects[i].x1)/m1;
						double m = tmp.vx/m1 - tmp.vy/m2;
						t = yint/m;
						tendx = tmp.startx + tmp.vx*t;
						tendy = tmp.starty + tmp.vy*t;
					}
					double tmpdist = dist(tmp.startx, tmp.starty, tendx, tendy);
					if(t > 0
						&& between(tendx, objects[i].x1, objects[i].x2, tendy, objects[i].y1, objects[i].y2)
						&& tmpdist < cur){
						endx = tendx;
						endy = tendy;
						cur = tmpdist;
						next = i;
					}
					//printf("%lf %lf %lf\n", t, tendx, tendy);
				}
			}
			if(!next) continue;
			if(objects[next].type == 'D'){
				data.insert(next);
				continue;
			}
			//Now for reflection vector, use the projection vector
			double orthox = objects[next].y2-objects[next].y1;
			double orthoy = objects[next].x1-objects[next].x2;
			double scalar = dotprod(tmp.startx-endx, tmp.starty-endy, orthox, orthoy)/dotprod(orthox, orthoy, orthox, orthoy);
			//printf("%lf %lf %lf\n", orthox, orthoy, scalar);
			vec nextvec;
			nextvec.last = next;
			nextvec.startx = endx;
			nextvec.starty = endy;
			nextvec.vx = 2*scalar*orthox - (tmp.startx - endx);
			nextvec.vy = 2*scalar*orthoy - (tmp.starty - endy);
			//printf("%d %lf %lf %lf %lf\n", nextvec.last, nextvec.startx, nextvec.starty, nextvec.vx, nextvec.vy);
			q.push(nextvec);
			if(objects[next].type == 'S'){
				nextvec.vx = tmp.vx;
				nextvec.vy = tmp.vy;
				q.push(nextvec);
			}
		}
		printf("DATA SET #%d\n", cas);
		if(data.size() == 0){
			printf("NO BEAMS DETECTED\n");
			continue;
		}
		for(set<int>::iterator it = data.begin(); it != data.end(); it++)
			printf("%d\n", *it);
	}
	return 0;
}