#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long series(long long m, long long len){
    return len <= 0 ? 0 : m*((len*(1+len))/2);
}
int main() {
    int test;
    scanf("%d", &test);
    long long N;
    for(int i = 0; i < test; i++){
        scanf("%lld", &N);
        printf("%lld\n", series(3, (N-1)/3) - series(15, (N-1)/15) + series(5, (N-1)/5));
    }
    return 0;
}