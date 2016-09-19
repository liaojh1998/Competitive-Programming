//Title: Broken line
//Type: Computational Geometry
//Solution: Really basic problem since "sides parallel to coordinate axes, without self-crossings and self-contacts."
#include <cstdio>
int K, x1[10001], x2[10001], y1[10001], y2[10001];
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int main(){
	//Instantiation
	scanf("%d", &K);
	for(int i = 0; i < K; i++){
		int xa, ya, xb, yb;
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		if(xa > xb) swap(xa, xb);
		if(ya > yb) swap(ya, yb);
		x1[i] = xa;
		x2[i] = xb;
		y1[i] = ya;
		y2[i] = yb;
	}
	int x, y, count = 0;
	scanf("%d %d", &x, &y);
	//Check if on the border, make sure we don't have lines that have no domain and no range
	for(int i = 0; i < K; i++)
		if((x1[i] != x2[i] && x >= x1[i] && x <= x2[i] && y == y1[i]) ||
			(y1[i] != y2[i] && y >= y1[i] && y <= y2[i] && x == x1[i])){
			printf("BORDER\n");
			return 0;
		}
	//Check intersections, notice x > x1[i] since broken lines are like stepwise functions
	for(int i = 0; i < K; i++)
		if((x1[i] != x2[i] && x > x1[i] && x <= x2[i] && y < y1[i]))
			count++;
	//Imagine a line from x and y and see how many times it would intersect a square from the inside and from the outside?
	if(count%2)
		printf("INSIDE\n");
	else
		printf("OUTSIDE\n");
	return 0;
}