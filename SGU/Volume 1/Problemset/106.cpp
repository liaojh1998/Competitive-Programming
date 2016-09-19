//Title: The equation
//Type: Math
//Solution: Extended Euclidean Algorithm
#include <stdio.h>
long long upperb = 100000000, lowerb = -100000000; //No bigger than 10^8
//Extended Euclidean Algorithm
long long egcd(long long a, long long b, long long &x, long long &y){
	if(!b){
		x = 1; y = 0;
		return a;
	}
	long long d = egcd(b, a%b, y, x);
	y -= a/b*x;
	return d;
}
long long upper(long long num, long long div){
	if(num <= 0)
		return num/div;
	return (num-1)/div + 1;
}
long long lower(long long num, long long div){
	if(num >= 0)
		return num/div;
	return (num+1)/div - 1;
}
//Check bound
void bound(long long l, long long u, long long div){
	if(div < 0){
		long long temp = l;
		l = -u;
		u = -temp;
		div = -div;
	}
	long long up = upper(l, div);
	long long lo = lower(u, div);
	lowerb = lowerb > up ? lowerb : up;
	upperb = upperb < lo ? upperb : lo;
}
int main(){
	//Instantiation;
	long long a, b, c, x, y, x1, x2, y1, y2;
	scanf("%lld %lld %lld\n%lld %lld\n%lld %lld", &a, &b, &c, &x1, &x2, &y1, &y2);
	//Print results
	//Case 1: a = b = c = 0
	if(a == 0 && b == 0 && c == 0){
		printf("%lld\n", (y2 - y1 + 1) * (x2 - x1 + 1));
		return 0;
	}
	//Case 2: a = b = 0
	if(a == 0 && b == 0){
		printf("0\n");
		return 0;
	}
	//Case 3: a = 0
	if(a == 0){
		if(!(c%b) && (c/b) <= y2 && (c/b) >= y1)
			printf("%lld\n", x2 - x1 + 1);
		else
			printf("0\n");
		return 0;
	}
	//Case 4: b = 0
	if(b == 0){
		if(!(c%a) && (c/a) <= x2 && (c/a) >= x1)
			printf("%lld\n", y2 - y1 + 1);
		else
			printf("0\n");
		return 0;
	}
	//Case 5: c is has no common divisor with a and b, proof by Extended Euclidean algorithm that if c % div != 0, then equation has no integer solution.
	long long div = egcd(a, b, x, y);
	if((c % div) != 0){
		printf("0\n");
		return 0;
	}
	//Case 6: all else, use Extended Euclidean algorithm to find 1 integer solution for ax + by = -c, and expand based on that.
	//Now why is Extended Euclidean algorithm great for this?
	//Let's present the case ax + by = -c, now Extended Euclidean helps find a solution such that ax + by = gcd(a, b).
	//Now if c % gcd(a, b) == 0, meaning it's divisible, we will divide the whole equation ax + by = -c by gcd(a, b), which ends up being
	//a/gcd(a, b)x + b/gcd(a, b)y = -c/gcd(a, b)
	//Why is this great? Because the solution for the equation above is also the solution for ax + by = -c.
	//If we divide ax + by = gcd(a, b) by gcd(a, b), we'll end up with a/gcd(a, b)x + b/gcd(a, b)y = 1
	//See this parallelism?
	//a/gcd(a, b)x + b/gcd(a, b)y = 1 & a/gcd(a, b)x + b/gcd(a, b)y = -c/gcd(a, b)
	//Multiply the fore equation with -c/gcd(a, b), you'll end up with a*-c x + b*-c y = -c/gcd(a, b)
	//Which also means a * (-c * x) + b * (-c * y) = -c/gcd(a, b)
	//The -c*x solution and -c*y solution is also a solution for ax + by = -c
	//Thus we found 1 solution
	//If a(-c*x) + b(-c*y) = -c where x and y are the solutions for a/gcd(a, b)x + b/gcd(a, b)y = 1
	//And implement a(-c*x) + ab + b(-c*y) - ab = -c because ab cancels
	//We'll end up with a(-c*x + b) + b(-c*y - a) = -c.
	//Set k as some unknown number for the amount of solutions
	//a(-c*x + k*b) + b(-c*y - k*a) = -c, we can find all the possible solutions for ax + by = -c.
	//How does one figure out k here and end up finding the amount of solutions?
	//We set 2 equations: x = -c*x + k*b, y = -c*y - k*a where we already know -c*x & -c*y.
	//Put in your x1, x2, y1, y2 in respective x and y and solve for kmax and kmin. Since x1 gets k1 and x2 gets k2, k1 < k2.
	//Since y1 gets k3 and y2 gets k4, k3 < k4. Our answer thus will be (min(k2,k4) - max(k1,k3) + 1).
	//Note, on cases where a will be negative and b will be negative these bounds will change.
	a /= div;
	b /= div;
	c /= div;
	//Careful of case of -a and -b where upper and lower bounds would end up being on opposite ends rather than the ends like positive as and bs
	//Pick the upper of the lower bound and lower of the upper bound
	bound(x1 - x*-c, x2 - x*-c, b);
	bound(y1 - y*-c, y2 - y*-c, -a);
	//Case 6a: if k max is less than k min, there is no solution
	if(upperb < lowerb){
		printf("0\n");
		return 0;
	}
	//Case 6b: possible solution
	printf("%lld\n", upperb - lowerb + 1);
	return 0;
}