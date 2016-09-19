//Title: Inheritance
//Type: Computational Geometry
//Solution: Graham's Scan + Cross products to scale amount of strips inside the hull
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int N, M, m;
struct Point{
	int x, y;
	double norm(Point a){
		return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
	}
}Ni[401], convex_hull[401], P;
//Operator - for subtracting points
Point operator -(Point a, Point b){
	Point p;
	p.x = a.x-b.x;
	p.y = a.y-b.y;
	return p;
}
//Operator < for min_element
bool operator <(Point a, Point b){
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
//Cross product
int cross_product(Point a, Point b){
	return a.x*b.y-a.y*b.x;
}
//Comparison for 2nd step of Graham's scan
bool cmp(Point a, Point b){
	int sign = cross_product(a-P, b-P);
	//Sign == 0 is just the sort to put the P as the first point
	if(sign == 0)
		return (a.norm(P)-b.norm(P)) < 0;
	return sign > 0;
}
//Determine amount of strip inside the convex hull
double length(Point a, Point b){
	double scalemin = 0;
	double scalemax = 1;
	for(int i = 0; i < m; i++){
		Point p = convex_hull[i];
		Point q = convex_hull[(i+1)%m];
		//determine if strip has crossed the convex_hull
		int seg1 = cross_product(q - p, a - p);
		int seg2 = cross_product(q - p, b - p);
		if(seg1 <= 0 && seg2 <= 0)
			return 0;
		//determine if the strip is not on the convex_hull
		if(cross_product(q - p, b - a) != 0){
			double scale = seg1 == 0 ? 0 : (double)seg1/(seg1 - seg2);
			//Scale should be between 1 and 0 so we can scale the norm later
			if(scale >= 0 && scale <= 1){
				//Determine the end points for the strip
				if(seg1 > 0)
					scalemax = min(scale, scalemax);
				if(seg2 > 0)
					scalemin = max(scale, scalemin);
			}
		}
	}
	return a.norm(b)*max(scalemax-scalemin, 0.0);
}
int main(){
	//Instantiation
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &Ni[i].x, &Ni[i].y);
	//Graham scan step 1: find the lowest y-coordinate point, if more than 1, choose 1 with the lowest x-coordinate
	P = *min_element(Ni, Ni + N);
	//Graham scan step 2: sort in increasing order of angle they and point P make with the x-axis
	sort(Ni, Ni+N, cmp);
	//Step 3: counterclockwise ordering of points into convex_hull
	for(int i = 0; i < N; i++){
		//Find next "left turn" point to put in the convex_hull
		while(m >= 2 && cross_product(convex_hull[m-1]-convex_hull[m-2], Ni[i]-convex_hull[m-2]) <= 0)
			m--;
		convex_hull[m++] = Ni[i];
	}
	//For all strips of minerals
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		Point a, b;
		scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
		printf("%.2lf\n", length(a, b));
	}
	return 0;
}