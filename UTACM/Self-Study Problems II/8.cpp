 #include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cassert>
 
 using namespace std;
 
 int N;
 double shipx[15], shipy[15];
 double vx[15], vy[15];
 double hx, hy, hs;
 
 double intersect(double sx, double sy, double vx, double vy,
                  double hx, double hy)
 {
   // the location of ship at time t is (sx,sy) + t*(vx,vy)
   // the distance from (hx,hy) to the ship at time t should be t*hs
   // equate the two to arrive at a quadratic.
   double dx = sx - hx, dy = sy - hy;
   double a = vx*vx + vy*vy - hs*hs;
   double b = 2*dx*vx + 2*dy*vy;
   double c = dx*dx + dy*dy;
 
   double disc = b*b - 4*a*c;
   assert(disc >= 0);
   double root1 = (-b + sqrt(disc))/(2*a);
   double root2 = (-b - sqrt(disc))/(2*a);
   //cout << disc << endl << root1 << endl  << root2 << endl;
   double root[2];
   int numroot = 0;
   if (root1 >= 0)
     {
       root[numroot++] = root1;
     }
   if (root2 >= 0)
     {
       root[numroot++] = root2;
     }
   assert(numroot > 0);
   return *min_element(root, root+numroot);
 }
 
 double compute(int perm[])
 {
   double t = 0;
   double currx = hx, curry = hy;    // current location of helicopter
 
   for (int i = 0; i < N; i++)
     {
       int ship = perm[i];
       double sx = shipx[ship] + vx[ship]*t;
       double sy = shipy[ship] + vy[ship]*t;
 
       t += intersect(sx, sy, vx[ship], vy[ship], currx, curry);
       t += 3600;                      // 5 minutes to unload
       currx = shipx[ship] + vx[ship]*t;
       curry = shipy[ship] + vy[ship]*t;
     }
 
   t += hypot(currx - hx, curry - hy) / hs;
   return t;
 }
 
 bool solve(int id)
 {
   //cout << "reading number of entries" << endl;
   cin >> N;
   //cout << "number of entries is " << N << endl;
   if (!N) return false;
 
   for (int i = 0; i < N; i++)
     {
       cin >> shipx[i] >> shipy[i] >> vx[i] >> vy[i];
 
       // convert to km/s
       vx[i] /= 3600.0;
       vy[i] /= 3600.0;
     }
   cin >> hx >> hy >> hs;
   hs /= 3600.0;
 
   int perm[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
   double best = -1;
   do
     {
       double t = compute(perm);
       if (best < 0 || t < best)
         {
           best = t;
         }
     }
   while (next_permutation(perm, perm+N));
 
   long long int secs = (long long int)ceil(best);
   cout << "Case " << id << ": "
        << secs/3600 << " hour(s) "
        << (secs%3600)/60 << " minute(s) "
        << secs % 60 << " second(s)" << endl;
 
   return true;
 }
 
 int main()
 {
   int id = 1;
   while (solve(id++))
     ;
 
   return 0;
 }