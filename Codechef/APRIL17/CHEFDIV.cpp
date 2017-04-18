#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
	//inline if read speed is needed, huge compilation time required though
	//safe no fread implementation
	int readInt(int &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readLL(long long &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readDouble(double &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
		double div = 1;
		for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
		n /= div;
		if(neg) n = -n;
		return 1;
	}
	int readStr(char *str){
		register char c = getchar();
		register int len = 0;
		if(!(~c)) return -1;
		while(c < 33 && ~c) c = getchar(); //32 if space should be included
		//32 if stop at space, 10 if stop at next line
		while(c != 10 && c != 32 && ~c){
			str[len] = c;
			c = getchar();
			len++;
		}
		str[len] = '\0';
		//Just in case if needs to return arriving at end of line
		//if(c == 10) return 10;
		return 1;
	}
	int readStr(char *str, int len){
		//Reading string of size len
		for(int i = 0; i < len; i++){
			str[i] = getchar();
			if(!(~str[i])){
				str[i] = '\0';
				return -1;
			}
			//Remove this if str can't go to next line
			/*if(str[i] == 10){
				str[i] = '\0';
				return 10;
			}*/
		}
		str[len] = '\0';
		return 1;
	}

public:
	//Constructor, true if using file input/output, defaulted false
	FastIO(bool useFile = false){
		if(useFile){
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

/* Subtasks comments:

#1:
Naive brute force search of maximum scores is enough to satisfy this requirement.

#3:
From 1 divisor tree, we can deduce the following observations:
- The degree of the tree of the root = sigma(0, root)-1, where sigma is the divisor function.
- The maximum score of a path from root to one of the leaves takes the maximum addition of every sigma(0, root/=prime) until root = 1 where prime is the mode in the prime factorization.
  This is because the sigma(0, root) = product(exponents of each prime + 1), and subtracting the mode exponent by 1 yield a maximum sigma.
- The score of the tree then can be denoted as f(root) = sigma(0, root) + sum(sigma(0, root /= mode prime), until root = 1) - 1;
  Since sigma(0, root) only concerns with exponents, we can model the function to find only a list of exponents to calculate f(root),
  This gives a O((distinct prime factors)^2 * (biggest prime exponent)) runtime algorithm.
The prime factorization also needs a precomputed prime list which can be made either with Eratostenes or Atkin, and the prime factorization procedure will run in O(sqrt(B)).
This gives a total complexity of O(prime generator + sqrt(B) + (distinct prime factors)^2 * (biggest prime exponent)).

#2:
The focus on this subtask is where B - A < 10^5.
When B becomes 10^6, we can see that sqrt(B) >> (distinct prime factors)^2 * (biggest prime exponent).
Thus our runtime can be roughly estimated to O(prime generator + (B-A)*sqrt(B)).
If we estimate further that prime generator runtime is much less than (B-A)*sqrt(B), we can come up with an algorithm that runs in O((B-A)*sqrt(B)).

#4:
The focus on this subtask is where B <= 10^12.
Obviously, O((B-A)*sqrt(B)) runs in worse case at 10^11 which is TLE.
Observe this simple behavior:
- If a = prime number * 1, and b = prime number * 2, then b - a = the prime number.
- A%prime gives the cycling distance to the next possible number divisible by the prime.
We can effectively remodel the algorithm to change the (B-A) factor to (B-A)/prime of each prime list iteration.

This gives an algorithm with runtime of O(sqrt(B)*(B-A)/prime of each iteration), drastically reducing computation time, enough to receive full AC.

*/

#define LIMIT (1000000)
int s[LIMIT + 1];
void sieve(vector<long long>& primes){
	//Add primes 2, 3
	primes.push_back(2);
	primes.push_back(3);
	//The Sieve of Atkin
	for(long long x = 1; x*x <= LIMIT; x++)
		for(long long y = 1; y*y <= LIMIT; y++){
			long long n = 4*x*x+y*y;
			if(n <= LIMIT && (n%12 == 1 || n%12 == 5))
				s[n] = ~s[n];
			n = 3*x*x+y*y;
			if(n <= LIMIT && n%12 == 7)
				s[n] = ~s[n];
			n = 3*x*x-y*y;
			if(x > y && n <= LIMIT && n%12 == 11)
				s[n] = ~s[n];
		}
	for(long long i = 5; i*i <= LIMIT; i++)
		if(s[i]){
			primes.push_back(i);
			long long j = 1;
			long long k = j++*i*i;
			while(k <= LIMIT){
				s[k] = 0;
				k = j++*i*i;
			}
		}
	for(long long i = sqrt(LIMIT); i <= LIMIT; i++)
		if(s[i])
			primes.push_back(i);
}

void FastIO::solve(){
	//Set up sieve for primes
	vector<long long> primes;
	sieve(primes);
	int psize = primes.size();
	//Read data
	long long A, B;
	readLL(A);
	readLL(B);
	int size = B-A+1;
	//Generate all numbers
	long long nums[size];
	for(long long i = 0; i < size; i++)
		nums[i] = A+i;
	//Generate exponents of sigma(0, n)
	vector<int> primefac[size];
	for(int i = 0; i < psize && primes[i]*primes[i] <= B; i++){
		long long prime = primes[i];
		int cur, begin = A%prime;
		for(int j = (begin ? prime - begin : 0); j < size; j += prime){
			cur = 0;
			while(nums[j]%prime == 0){
				cur++;
				nums[j] /= prime;
			}
			primefac[j].push_back(cur);
		}
	}
	for(int i = 0; i < size; i++){
		if(nums[i] != 1)
			primefac[i].push_back(1); //nums[i] is also a prime
		primefac[i].push_back(0); //Set an end point for calculation
	}
	//Generate maximum divisor tree scores
	int sum = 0;
	for(int i = 0; i < size; i++){
		int pfsize = primefac[i].size(), ans = 0, multi = 1;
		//Multiply and add
		sort(primefac[i].begin(), primefac[i].end(), greater<int>());
		for(int j = 0; j < pfsize-1; j++)
			multi *= (primefac[i][j] + 1);
		ans += multi; //sigma(0, n)
		for(int j = 0; j < pfsize-1; j++)
			while(primefac[i][j] > primefac[i][j+1])
				for(int k = 0; k <= j; k++)
					if(primefac[i][k]){
						multi /= (primefac[i][k]-- + 1);
						multi *= (primefac[i][k] + 1);
						ans += multi;
					}
		sum += ans-1;
	}
	printf("%d\n", sum);
}