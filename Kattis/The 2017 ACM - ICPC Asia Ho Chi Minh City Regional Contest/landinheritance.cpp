#include <bits/stdc++.h>
using namespace std;

struct point{
	double x, y;
};

double polygon_area(point* pts, int N){
	//Using shoelace formula, assuming pts are counterclockwise ordered, the sign is positive
	double area = 0;
	for(int i = 0; i < N; i++)
		area += pts[i].x*pts[(i+1)%N].y - pts[(i+1)%N].x*pts[i].y;
	area /= 2;
	return (area < 0 ? -area : area);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	point pts[N+5];
	for(int i = 0; i < N; i++)
		cin >> pts[i].x >> pts[i].y;
	cout << polygon_area(pts, N) << endl;
	return 0;
}