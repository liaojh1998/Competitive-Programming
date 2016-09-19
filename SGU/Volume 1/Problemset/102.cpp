//Title: Coprimes
//Type: Math
//Solution: Loop and check with gcd(). Euclidean Algorithm.
#include <iostream>
using namespace std;
int N;
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
int main(){   
    cin >> N;
    int count = 0;
    for(int i = 1; i <= N; i++){
        if(gcd(i, N) == 1) count++;
    }
    cout << count << endl;
    return 0;
}