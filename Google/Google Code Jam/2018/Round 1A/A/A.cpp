#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int idx = 1; idx <= T; idx++){
		cout << "Case #" << idx << ": ";
		int R, C, V, H, num = 0;
		cin >> R >> C >> H >> V;
		char mat[R][C];
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				cin >> mat[i][j];
				if(mat[i][j] == '@')
					num++;
			}
		}
		//Not possible for division without check
		bool done = false;
		if(num%(H+1) || (num/(H+1))%(V+1))
			cout << "IMPOSSIBLE" << endl;
		else if(num){
			int need = num/(H+1), acc = 0;
			vector<int> rcut;
			for(int i = 0; i < R && !done; i++){
				for(int j = 0; j < C; j++)
					if(mat[i][j] == '@')
						acc++;
				if(acc == need){
					rcut.push_back(i+1);
					acc = 0;
				}else if(acc > need)
					done = true;
			}
			if(rcut.size() != H+1)
				done = true;
			need /= V+1;
			int arr[H+1], ccut = 0;
			memset(arr, 0, sizeof(arr));
			for(int i = 0; i < C && !done; i++){
				int begin = 0;
				for(int j = 0; j < H+1; j++){
					int end = rcut[j];
					for(int k = begin; k < end; k++)
						if(mat[k][i] == '@')
							arr[j]++;
					begin = end;
				}
				bool less = false;
				for(int j = 0; j < H+1; j++){
					if(arr[j] < need)
						less = true;
				}
				if(!less){
					for(int j = 0; j < H+1; j++)
						if(arr[j] != need)
							done = true;
					if(!less && !done){
						memset(arr, 0, sizeof(arr));
						ccut++;
					}
				}
			}
			if(ccut != V+1)
				done = true;
			if(done)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << "POSSIBLE" << endl;
		}else{
			//0 case
			cout << "POSSIBLE" << endl;
		}
	}
	return 0;
}