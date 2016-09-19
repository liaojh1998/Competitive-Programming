/*
ID: liaojh11
PROG: ttwo
LANG: C++
*/
//Title: ttwo
//Type: Simulation
//Solution: Set your conditions and simulate it. Condition for success: F and C land at same area. Condition for repeat: repeating F and C location and direction.
#include <fstream>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
char map[12][12];
int minute = 0, Fx, Fy, Fdir, Cx, Cy, Cdir;
bool mapped[11][11][4][11][11][4] = {0};
int main(){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			if(i == 0 || i == 11 || j == 0 || j == 11){
				map[i][j] = '*';
			}else{
				fin >> map[i][j];
				if(map[i][j] == 'F'){
					Fx = j;
					Fy = i;
					Fdir = 0;
				}
				if(map[i][j] == 'C'){
					Cx = j;
					Cy = i;
					Cdir = 0;
				}
			}
		}
	}
	mapped[Fx][Fy][Fdir][Cx][Cy][Cdir] = 1;
	while(1){
		if(Fdir == 0){
			if(map[Fy - 1][Fx] != '*') Fy -= 1;
			else Fdir = 1;
		}else if(Fdir == 1){
			if(map[Fy][Fx + 1] != '*') Fx += 1;
			else Fdir = 2;
		}else if(Fdir == 2){
			if(map[Fy + 1][Fx] != '*') Fy += 1;
			else Fdir = 3;
		}else if(Fdir == 3){
			if(map[Fy][Fx - 1] != '*') Fx -= 1;
			else Fdir = 0;
		}
		if(Cdir == 0){
			if(map[Cy - 1][Cx] != '*') Cy -= 1;
			else Cdir = 1;
		}else if(Cdir == 1){
			if(map[Cy][Cx + 1] != '*') Cx += 1;
			else Cdir = 2;
		}else if(Cdir == 2){
			if(map[Cy + 1][Cx] != '*') Cy += 1;
			else Cdir = 3;
		}else if(Cdir == 3){
			if(map[Cy][Cx - 1] != '*') Cx -= 1;
			else Cdir = 0;
		}
		minute++;
		if(Fx == Cx && Fy == Cy) break;
		if(mapped[Fx][Fy][Fdir][Cx][Cy][Cdir]){
			fout << 0 << endl;
			return 0;
		}
		mapped[Fx][Fy][Fdir][Cx][Cy][Cdir] = 1;
	}
	fout << minute << endl;
	return 0;
}