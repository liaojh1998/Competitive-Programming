//Title: The Book
//Type: Hamiltonian Path
//Solution: The first NP-Complete problem found on SGU, oh goodness. I have to admit that this will take a bunch of research and looking at codes.
		/*	https://en.wikipedia.org/wiki/Hamiltonian_path
			First, proven by the Bondy-Chvatal theorem originally formed from Dirac's and Ore's theorem, the problem statement proves the graph is connected.
			The theorem states that a graph contains a Hamiltonian path if we can repeatedly add nonadjacent pairs uv where distinct
			vertices from deg(u) + deg(v) >= vertices in the graph until no more of these pairs can be found.
			Since our problem statement states that no man will have (N+1)/2 friends, any deg(u) + deg(v) >= vertices in the graph.
			Thus, there are no cases of 'No solution' in this problem.
			Next,
			https://en.wikipedia.org/wiki/Ore%27s_theorem
			The proof given for the theorem is a contradiction which finds deg(u) + deg(v) < vertices in graph cannot have a Hamiltonian path.
			We'll use an algorithm that fits Ore's theorem to construct the Hamiltonian Path, founded by Palmer (1997), which takes
			criss-cross pairs of vertices and connect them until no nonadjacent vertex can be found. (Look in references of wikipedia and look at the original document)
			Time complexity: O(V^3)
			A better explanation of the algorithm process can be found on stackoverflow. (I'm lazy)
			http://stackoverflow.com/questions/11273653/palmers-algorithm-for-hamiltonian-cycles	*/
#include <cstdio>
#include <cstring>
using namespace std;
int book[1002], N;
bool visited[1001] = {0}, adj[1001][1001] = {0};
char s[3000]; //I think max is about 2500?
int main(){
	//Instantiation, and do not use the <string> class, because you'll get TLE for just scanning your input
	scanf("%d", &N);
	getchar();
	for(int i = 1; i <= N; i++){
		gets(s);
		int len = strlen(s);
		for(int j = 0; j < len; j++){
			int k = 0;
			if(s[j] == ' ') continue;
			while(j < len && s[j] >= '0' && s[j] <= '9')
				k = k*10 + s[j] - '0', j++;
			adj[i][k] = true;
		}
	}
	//Palmer's algorithm
	//Step 1: arrange the vertices arbitrarily in a cycle, ignoring adjacencies in the graph.
	for(int i = 0; i < N; i++)
		book[i] = i+1;
	book[N] = 1;
	//Step 2: criss-cross algorithm
	int dis = -1, swap;
	//Search for nonadj vertex
	for(int i = 0; i < N && dis == -1; i++)
		if(!adj[book[i]][book[i+1]]){
			dis = i;
		}
	//While such nonadj vertex exists
	while(dis != -1){
		swap = -1;
		for(int j = dis+2 >= N ? 0 : dis+2; j != dis && swap == -1; j++){
			//If Vi adj Vj and Vi+1 adj Vj+1
			if(adj[book[dis]][book[j]] && adj[book[dis+1]][book[j+1]])
				swap = j;
			//Reloop if arrived at N
			if(j == N-1)
				j = -1;
		}
		//Swap Vi+1 with Vj
		int temp = book[dis+1];
		book[dis+1] = book[swap];
		book[swap] = temp;
		if(dis+1 == N)
			book[0] = book[N];
		if(swap == 0)
			book[N] = book[0];
		//Search for next nonadj vertex
		dis = -1;
		for(int i = 0; i < N; i++)
			if(!adj[book[i]][book[i+1]]){
				dis = i;
				break;
			}
	}
	//Print results, presentation error on test 3? Yeah I forgot to print starting from 1 and end with 1
	for(int i = 0; i < N; i++)
		if(book[i] == 1){
			for(int j = i, k = 0; k < N; j = (j+1)%N, k++)
				printf("%d ", book[j]);
			printf("1\n");
			break;
		}
	return 0;
}