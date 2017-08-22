#include <bits/stdc++.h>
#define abs(x) ((x) < 0?-(x):(x))
#define uint unsigned int
using namespace std;

int gcd(int x, int y) {
   if(x > y) swap(x,y);
   while(x > 0) {
      int z =x;
      x =y%x;
      y =z;}
   return y;}

int main() {
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
   int N;
   scanf("%d", &N);
   vector<int> start(N);
   for(int i =0; i < N; i++) scanf("%d", &start[i]);
   vector<int> step1s;
   bool added[50005];
   for(int i =0; i < N; i++) for(int j =0; j < N; j++) if(start[i] != start[j]){
   	  if(!added[abs(start[i]-start[j])]){
      	step1s.push_back(abs(start[i]-start[j]));
      	added[abs(start[i]-start[j])] = true;
      }
   }
   start.clear();
   for(auto x: step1s) start.push_back(x);
    N =start.size();
   if(N == 0) {
        printf("1\n"); 
        return 0;}

   int g =start[0];
   for(int i =1; i < N; i++) g =gcd(g,start[i]);
   for(int i =0; i < N; i++) start[i] /=g;

   int K =32, M =200000;
   vector<uint> live(M/K,0);
   for(int i =0; i < N; i++){ for(int j =i+1; j < N; j++){
      live[(start[j]-start[i]-1)/K] |=1<<((start[j]-start[i]-1)%K);
      printf("%u ", live[(start[j]-start[i]-1)/K]);
   }
   printf("\n");
   }

   int t =2, m =start[N-1]-start[0];

   while(m > 0 && (live[0]&1) == 0) {
      vector<uint> liveN(M/K,0);
      bool b =false;
      int m2 =m;
      for(int i =0; i < m; i++) if((live[i/K]>>(i%K))&1) {
         if(!b) m2 =m-(i+1);
         b =true;
         if(i%K < 31) for(int j =i/K; j < M/K; j++) liveN[j-i/K] |=live[j]>>(i%K+1);
         for(int j =i/K+1; j < M/K; j++) liveN[j-i/K-1] |=(live[j]<<(K-1-i%K));
         }
      live =liveN;
      int p =0;
      for(int i =0; i < M; i++) if((live[i/K]>>(i%K))&1) p++;
      printf("%d %d %d\n", t+1, m2, p);
      m =m2;
      t++;}

   printf("%d\n", t+m);
   return 0;}
