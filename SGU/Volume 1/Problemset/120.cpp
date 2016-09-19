//Title: Archipelago
//Type: Computational Geometry
//Solution: http://s5.sinaimg.cn/middle/89a06c7d4b36d64e3b194&690
		/*	http://blog.sina.com.cn/s/blog_89a06c7d0100wert.html
			https://en.wikipedia.org/wiki/Chord_(geometry)	For chords
			https://en.wikipedia.org/wiki/Rotation_matrix	For rotation matrix
			The concept is to determine the origin and rotate to every vertex from that N1 using the same radius since all vertices are points on a circle.	*/
#include <cstdio>
#include <cmath>
#define pi acos(-1)
using namespace std;
struct vertex{double x, y;};
//Rotate function, which is based on the rotation matrix in linear algebra and turned counterclockwise
void rotate(vertex p1, vertex p2, double theta, double scale, vertex *p3){
	double x = p2.x - p1.x;
	double y = p2.y - p1.y;
	double nx = scale*(x*cos(theta) - y*sin(theta));
	double ny = scale*(x*sin(theta) + y*cos(theta));
	p3->x = p1.x + nx;
	p3->y = p1.y + ny;
}
int main(){
	//Instantiation
	int N, N1, N2;
	scanf("%d %d %d", &N, &N1, &N2);
	vertex v[N+1];
	scanf("%lf %lf", &v[N1].x, &v[N1].y);
	scanf("%lf %lf", &v[N2].x, &v[N2].y);
	//Find the origin based on the picture
	//Find alpha, which will be 2pi/N*(N2-N1), but /2 since chord calculation uses theta/2.
	double alpha = pi*(N2-N1)/N;
	//Find beta, which is part of the right triangle, 180 - 90 - alpha = beta
	double beta = pi/2 - alpha;
	//Find origin, which will be rotated beta counterclockwise from chord and then scaled to the size of radius and added from the end point N2
	//Scale chord to origin point, which is ratio of length of radius to length of chord.
	//Since chord = 2*radius*sin(alpha), ratio = radius/(2*radius*sin(alpha)) = 1/(2*sin(alpha))
	vertex o;
	rotate(v[N2], v[N1], beta, 1/(2*sin(alpha)), &o);
	//Get theta, the angle between every chord
	double theta = 2*pi/N;
	int Ni = N1;
	//Since islands are clockwise numerated and rotation goes counterclockwise, go backwards on numeration
	for(int i = 0; i < N; i++){
		int Nlast = Ni;
		Ni = Ni == 1 ? N : Ni-1;
		if(Ni != N2)
			rotate(o, v[Nlast], theta, 1, &v[Ni]);
	}
	for(int i = 1; i <= N; i++){
		printf("%.6f %.6f\n", v[i].x, v[i].y);
	}
	return 0;
}