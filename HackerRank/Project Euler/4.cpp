#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, T;
vector<int> pal;
bool check(int c){
    int len = 0, temp = c;
    while(c){
        len++;
        c/=10;
    }
    if(len == 5)
        return (temp/10000 == temp%10) && (temp/1000%10 == temp%100/10);
    else
        return (temp/100000 == temp%10) && (temp/10000%10 == temp%100/10) && (temp/1000%10 == temp%1000/100);
}
int main() {
    for(int i = 100; i <= 999; i++)
        for(int j = i; j <= 999; j++)
            if(check(i*j))
                pal.push_back(i*j);
    sort(pal.begin(), pal.end());
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        int i;
        for(i = 0; i < pal.size() && pal[i] < N; i++);
        printf("%d\n", pal[i-1]);
    }
    return 0;
}
