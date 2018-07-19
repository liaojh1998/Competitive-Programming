#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "w", stdout);
	mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
	int N = 1000;
	cout << N << endl;
	for(int i = 0; i < N; i++){
		int size = rnd()%25 + 1;
		string str;
		int c = 0, s = 0;
		for(int j = 0; j < size; j++){
			int p = rnd()%100;
			if(p <= 50){
				str += "S";
				s++;
			}else{
				str += "C";
				c++;
			}
		}
		int mod = (1<<c)*s - s;
		if(mod <= 0)
			mod = rnd()%1000+1;
		//cout << "c, s " << c << " " << s << endl;
		cout << (rnd()%(mod)) << " " << str << endl;
	}
	return 0;
}