/*
ID: liaojh11
PROG: spin
LANG: C++
*/
//Title: spin
//Type: Simulation
//Solution: When you simulate in a code, you gotta go fast! Simply simulate the process and check if light can pass through or no.
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("spin.in");
ofstream fout("spin.out");
int speed[5], wedges[5], wedgepos[5][5], wedgedeg[5][5];
int range[360];
//If all 5 wedge are open on this point, then range[k % 360] |= (1 << i) should add up to 31.
void check(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < wedges[i]; j++){
			int max = wedgepos[i][j] + wedgedeg[i][j];
			for(int k = wedgepos[i][j]; k <= max; k++){
				range[k % 360] |= (1 << i);
			}
		}
	}
}
int main(){
	//Instantiation
	for(int i = 0; i < 5; i++){
		fin >> speed[i] >> wedges[i];
		for(int j = 0; j < wedges[i]; j++){
			fin >> wedgepos[i][j] >> wedgedeg[i][j];
		}
	}
	//Simulate
	int t = 0;
	while(t < 360){ //After 360 seconds, all wheels should be at their initial position no matter what
		//Assign as no light can pass through
		memset(range, 0, sizeof(range));
		//Check if light can already pass through
		check();
		for(int i = 0; i < 360; i++){
			if(range[i] == 31){
				fout << t << endl;
				return 0;
			}
		}
		//Change position
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < wedges[i]; j++){
				wedgepos[i][j] = (wedgepos[i][j] + speed[i]) % 360;
			}
		}
		//Increment time
		t++;
	}
	fout << "none" << endl;
	return 0;
}