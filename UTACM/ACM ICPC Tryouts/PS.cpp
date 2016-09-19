//Title: Personal Space
//Type: Simulation
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T, N, loc[105], oloc[105], nloc[105], maxdist;
bool done;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d", &loc[i]);
		}
		sort(loc, loc+N);
		//Store an original array
		memcpy(oloc, loc, sizeof(loc));
		//Check
		done = true;
		for(int i = 0; i < N-1; i++)
			if(loc[i+1] - loc[i] == 1){
				done = false;
				break;
			}
		while(!done){
			memcpy(nloc, loc, sizeof(loc));
			//Move right
			for(int i = 0; i < N-3; i++){
				if(loc[i+1] - loc[i] == 1 && loc[i+2] - loc[i+1] > 1 && loc[i+3] - loc[i+2] > 1)
					nloc[i+1] = loc[i+1] + 1;
			}
			if(N > 2 && loc[N-2] - loc[N-3] == 1 && loc[N-1] - loc[N-2] > 1)
				nloc[N-2] = loc[N-2] + 1;
			if(N > 1 && loc[N-1] - loc[N-2] == 1)
				nloc[N-1] = loc[N-1] + 1;
			//Move left
			for(int i = N-1; i >= 3; i--){
				if(loc[i] - loc[i-1] == 1 && loc[i-1] - loc[i-2] > 1 && loc[i-2] - loc[i-3] > 1)
					nloc[i-1] = loc[i-1] - 1;
			}
			if(N > 2 && loc[2] - loc[1] == 1 && loc[1] - loc[0] > 1)
				nloc[1] = loc[1] - 1;
			if(N > 1 && loc[1] - loc[0] == 1)
				nloc[0] = loc[0] - 1;
			//Check
			memcpy(loc, nloc, sizeof(nloc));
			done = true;
			for(int i = 0; i < N-1; i++)
				if(loc[i+1] - loc[i] == 1){
					done = false;
					break;
				}
			//Reset
			memset(nloc, 0, sizeof(nloc));
		}
		for(int i = 0; i < N; i++)
			if(oloc[i] > loc[i] && maxdist < oloc[i] - loc[i])
				maxdist = oloc[i] - loc[i];
			else if(maxdist < loc[i] - oloc[i])
				maxdist = loc[i] - oloc[i];
		printf("%d\n", maxdist);
		maxdist = 0;
	}
	return 0;
}