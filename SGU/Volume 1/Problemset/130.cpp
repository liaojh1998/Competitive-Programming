//Title: Circle
//Type: Math + DP
//Solution: Catalan numbers for different kind of partitions, or N, and P is always k+1, since no chord can replace another.
		/*	How this this work?
			Imagine a circle with only 2 points, k = 1. There is only 1 way to partition that, and same with k = 0, there is only 1 way to partition that.
			Now imagine a circle with 4 points, k = 2. Number them clockwise from 1 to 4.
			When you connect point 1 to 2, you end up having 2 points, which is a k = 1 solution.
			When you connect point 1 to 4, you end up having 2 points, which is also a k = 1 solution.
			When you connect point 1 to 3, you do not have a minimum partition. Thus k = 2, N = 2.

			Now imagine a circle with 6 points, k = 3. Number them clockwise from 1 to 6.
			When you connect point 1 to 2, you end up having 4 points, which is a k = 2 solution.
			When you connect point 1 to 3, you do not have a minimum partition.
			When you connect point 1 to 4, you end up having 4 points, but each pair is forced to connect to each other for a minimum partition, a k = 1 solution.
			By symmetry,
			1 to 5 is not a minimum partition.
			1 to 6 is the same as 1 to 2.
			Thus k = 3 you have 2 + 1 + 2 = 5.

			By now you should've have come up with the conclusion this is some sum.
			But that's only half the solution, imagine a circle with 10 points, k = 5. Number them clockwise from 1 to 10.
			If you connect 1 to 6, you'll realize you'll have 2 k = 2 partitions to do. However, instead of adding those 2, you'll multiply the 2.
			Why? Because partition can be a k = 0 and k = 0, k = 1 and k = 1, k = 1 and k = 0, and k = 0 and k = 1.
			There are 4 different ways to partition it, but each partition is multiplied by the total the other can partition, enumeration.
			k = 0 will be met with k = 1 and k = 0, k = 1 will be met with k = 1 and k = 0.
			If they were k = 4, you'd have k = 4 * k = 4.

			Keep going down like this and you'll realize each time you'd end with a sum function of
			catalan_sum(k) = sum(catalan_sum(i)*catalan_sum(k-i-1) for(0 <= i < k));
			where catalan_sum(0) = 1 and catalan_sum(1) = 1

			The proof?
			https://en.wikipedia.org/wiki/Catalan_number
			How does 1 write 5 proofs lol, how does 1 even write 1 proof?
			*/
#include <cstdio>
int k;
long long catalan[31];
int main(){
	//Instantiation
	scanf("%d", &k);
	catalan[0] = catalan[1] = 1;
	//Catalan chart: sum up all partitions that can partition into minimum parts
	for(int i = 2; i <= k; i++){
		long long sum = 0;
		for(int j = 0; j < i; j++)
			sum+= catalan[j]*catalan[i-j-1];
		catalan[i] = sum;
	}
	//Print solution
	printf("%lld %d\n", catalan[k], k+1);
	return 0;
}

/*	Of course, there's also the recursive solution
#include <cstdio>
int k;
//Catalan function
long long catalan(int n){
	if(n == 2)
		return k+2;
	return (k+n)*catalan(n-1)/(n-1);
}
int main(){
	//Instantiation
	scanf("%d", &k);
	//Print solution
	printf("%lld %d\n", k == 1 ? 1 : catalan(k)/k, k+1);
	return 0;
}
*/