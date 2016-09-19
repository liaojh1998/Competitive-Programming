//Problem: Fence Painting (Bronze)
//Type: Math
//Solution: Basic Math
#include <fstream>
using namespace std;
ifstream fin("paint.in");
ofstream fout("paint.out");
int a, b, c, d;
int main(){
	//Instantiation
	fin >> a >> b >> c >> d;
	if(b < c || d < a){
		fout << b - a + d - c << endl;
		return 0;
	}
	a = a < c ? a : c;
	d = b > d ? b : d;
	fout << d - a << endl;
	return 0;
}