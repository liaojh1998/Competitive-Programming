//Title: Dungeon
//Type: Computational Geometry
//Solution: A bunch of math involving vector analysis and spherical computations, read below.
		/*	For those who've done multivariable calculus but forgot the proj u v, or projection of u onto v, search it up.

			Things to do:
			1) Arrive at next sphere from current starting point of ray by using parametric equations of:
				x = mx * t + kx;
				y = my * t + ky;
				z = mz * t + kz;
				and using the sphere equation:
				(x - xlocation)^2 + (y - ylocation)^2 + (z - zlocation)^2 = r^2
				combining them and you'd get a parabolic equation which can be solved using (-b +- sqrt(b^2 - 4ac)) / (2a) to solve for t.
			2) Find the reflection vector by using the projection of ray onto a normal vector of the sphere by first reversing ray direction:
				mx = -mx;
				my = -my;
				mz = -mz; so you can calculate a vector orthogonal to the projection of ray onto the normal vector of the sphere, which is calculated by:
				arrived surface point - sphere center
				normalx = kx - xlocation;
				normaly = ky - ylocation;
				normalz = kz - zlocation;
				then add the orthogonal vector to the projection of ray onto the normal vector to get the reflection vector.

			Note:
			You cannot repeat a sphere, make sure you know what your last sphere was.
			The projection of u onto v is:
				u dot v / norm(v)^2 * vector v //Why is this true? Do calculus and find the proof lol
				Site: http://www.cnblogs.com/graphics/archive/2010/08/03/1791626.html
			There are multiple ways to check b^2 - 4ac (incorporate them if you wish (I didn't and still AC lol)):
				when a == 0, there is only 1 root, -c/b, and it must be positive because t cannot travel in the other direction
				when b^2 < 4ac, there is no root
				if ray dot normal == 0, then the ray is tangent to the sphere and there is no need to change direction
			Roots, t, must be positive because direction of the ray cannot go opposite direction.
			*/
#include <cstdio>
#include <cmath>
#define maxd 40000 //Longest distance possible is 20000 * root(3)
using namespace std;
struct sphere{double x, y, z, r;} spheres[51];
double mx, my, mz, kx, ky, kz, temp_t;
int N, last;
//Norm^2
double sqnorm(double a, double b, double c){
	return a*a + b*b + c*c;
}
//Dot product
double dot_prod(double a1, double a2, double a3, double b1, double b2, double b3){
	return a1*b1 + a2*b2 + a3*b3;
}
//Find t of the parametric equation
bool root(sphere s){
	//Initiate at^2 + bt + c = 0
	double a = mx*mx + my*my + mz*mz;
	double b = 2*(mx*(kx-s.x) + my*(ky-s.y) + mz*(kz-s.z));
	double c = (kx-s.x)*(kx-s.x) + (ky-s.y)*(ky-s.y) + (kz-s.z)*(kz-s.z) - s.r*s.r;
	//b^2 - 4ac check
	double check = b*b-4*a*c;
	if(check < 0) return false;
	//Calc root
	double t1 = (-b + sqrt(check))/(2*a);
	double t2 = (-b - sqrt(check))/(2*a);
	//Note: t cannot be negative or we're going the other direction, checking 1 t is enough since the other must have the same sign
	if(t1 < 0) return false;
	//Check closer root because that's the outer surface of the sphere
	if(t1 < t2) temp_t = t1;
	else temp_t = t2;
	return true;
}
int main(){
	//Instantiation
	scanf("%d\n", &N);
	for(int i = 1; i <= N; i++){
		scanf("%lf %lf %lf %lf\n", &spheres[i].x, &spheres[i].y, &spheres[i].z, &spheres[i].r);
	}
	scanf("%lf %lf %lf %lf %lf %lf", &kx, &ky, &kz, &mx, &my, &mz);
	mx-= kx;
	my-= ky;
	mz-= kz;
	//Moving ray
	for(int spherecount = 1; spherecount <= 11; spherecount++){
		//Find the sphere closest to ray
		double t = maxd;
		int id = 0;
		for(int i = 1; i <= N; i++)
			if(i != last && root(spheres[i]))
				if(temp_t < t){
					t = temp_t;
					id = i;
				}
		//Hit a sphere or not
		if(!id)
			break;
		else{
			if(spherecount == 11){
				printf(" etc.");
				break;
			}else if(spherecount == 1)
				printf("%d", id);
			else
				printf(" %d", id);
		}
		//The sphere must not be the sphere that was hit just before
		last = id;
		//Arrive at next sphere surface
		kx+= mx*t;
		ky+= my*t;
		kz+= mz*t;
		//Find reflection vector
		//Create vector orthogonal to surface of sphere (surface point - center)
		double normalx = kx-spheres[id].x;
		double normaly = ky-spheres[id].y;
		double normalz = kz-spheres[id].z;
		//Projection of ray onto orthogonal vector
		double scale = dot_prod(-mx, -my, -mz, normalx, normaly, normalz)/sqnorm(normalx, normaly, normalz);
		normalx*= scale;
		normaly*= scale;
		normalz*= scale;
		//Find vector orthogonal to projected vector and add it to projected vector for reflection vector
		//Since normalx + normalx - (-mx) is the same as mx += 2*normalx;
		mx+= 2*normalx;
		my+= 2*normaly;
		mz+= 2*normalz;
	}
	printf("\n");
	return 0;
}