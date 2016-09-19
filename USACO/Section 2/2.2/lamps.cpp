/*
ID: liaojh11
PROG: lamps
LANG: C++
*/
//Title: lamps
//Type: Brute Force/Complete Search
//Solution: "The major challenge of this problem is to discover that it is not necessary to “generate” all the
		//	possible combinations of buttons presses because there are no more then 8 possible final
		//	configuration." - IOI '98
		/*	In other words, don't generate button combinations (which would be DFS), look at the repeated results.

			Say we have 8 lamps.

			For no button pressed, only the initial combination of lamps (all ON) will appear:
			11111111

			For 1 button pressed, we can have 4 different combination of lamps:
			- button 1: 00000000
			- button 2: 01010101
			- button 3: 10101010
			- button 4: 01101101

			For 2 buttons pressed, we can have 7 different combination of lamps:
			- button 1, 2: 10101010 <-- realize this is the same as button 3
			- button 1, 3: 01010101 <-- realize this is the same as button 2
			- button 1, 4: 10010010 <-- realize this is the opposite of button 4
			- button 2, 4: 11000111
			- button 3, 4: 00111000 <-- realize this is the opposite of button 2, 4
			- button 1, 1: 11111111 <-- realize the buttons cancel out, as if no button has pressed
			- button 2, 3: 00000000 <-- realize this is the same as button 1

			From this we can inference:
			- The combination of buttons do not matter.
			- The first 6 lamps form a repeated pattern, one may check if lamp n is on or off just by n % 6.
			  This also means the lamps can be stored in a 6 bit integer, using tiny allocation of memory. (Which is not implemented in this solution)
			- Repeated buttons cancel each other out.
			- Congruent buttons:
				Button 1, 2 = Button 3
				Button 1, 3 = Button 2
				Button 2, 3 = Button 1
				Button 2, 4 = Button 1, 3, 4
				Button 3, 4 = Button 1, 2, 4

			For 3 buttons pressed, we can have 7 different combination of lamps:
			- button 1, 2, 3: 11111111 <-- realize these buttons cancel out, as if no button has pressed
			- as shown in inference above, button 1, 3, 4 and button 1, 2, 4 will produce same combination as button 2, 4 and button 3, 4
			- repeated buttons and a new button will form the 4 different combinations same as 1 button pressed,
			  for example: button 1, 1, 4 will give the same result as button 4

			From this we can inference:
			- Because no button cancels the property of button 4, 2 buttons pressed combinations and 3 buttons combinations pressed will have a difference:
			  Button 1, 4: 10010010 is not the same as pressing Button 4 alone: 01101101.

			For 4 buttons pressed, we can have 8 different combination of lamps:
			- button 1, 2, 3 act as if no button has pressed, so the extra button would produce same combination as if 1 button pressed.
			- with 2 repeated buttons which cancel out, we can produce the same combination as if 2 buttons pressed.
			- realize this means all combinations are produced, since Button 1, 4 and Button 4 alone are both in the possible combinations.

			From this we can inference:
			- There is a maximum of 8 different combinations.
			- Any count of buttons pressed bigger than 3 has all 8 combinations since 3 buttons can act as if
			  nothing is pressed: button 1, 2, 3, and repeated buttons also cancels each other out.
			- Some 3 buttons pressed is the same as if 2 buttons pressed, affirming the inference of maximum of 8 different combinations above.

			With that said, the solution to the problem is definitely not to generate all button cases and test all cases,
			but to generate the 8 different lamp combination cases and see which case don't fit the criteria.
		*/
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int N, C;
stack<int> ON, OFF;
int main()
{   
	//Instantiation
	fin >> N;
	fin >> C;
	int i;
	fin >> i;
	while(i != -1){
		ON.push(i);
		fin >> i;
	}
	fin >> i;
	while(i != -1){
		OFF.push(i);
		fin >> i;
	}

	//Generating Cases
	bool cases[8][N+1];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j <= N; j++){
			cases[i][j] = 1;
		}
	}
	//Case 1 generate as button 1, all altered, 00000000...
	for(int i = 1; i <= N; i++){
		cases[0][i] = 0;
	}
	//Cases 2 generate as button 3 and 4 combination, evens and 3k + 1, 00111000...
	for(int i = 2; i <= N; i+=2){
		cases[1][i] = 0;
	}
	for(int i = 1; i <= N; i+=3){
		cases[1][i] = !cases[1][i];
	}
	//Case 3 generate as button 2, all odds altered, 01010101...
	for(int i = 1; i <= N; i+=2){
		cases[2][i] = 0;
	}
	//Case 4 generate as button 4, all 3k + 1 altered, 01101101...
	for(int i = 1; i <= N; i+=3){
		cases[3][i] = 0;
	}
	//Case 5 generate as button 1 and 4, all and 3k + 1, 10010010...
	for(int i = 1; i <= N; i++){
		cases[4][i] = 0;
	}
	for(int i = 1; i <= N; i+=3){
		cases[4][i] = 1;
	}
	//Case 6 generate as button 3, all evens altered, 10101010...
	for(int i = 2; i <= N; i+=2){
		cases[5][i] = 0;
	}
	//Case 7 generate as button 2 and 4 combination, odds and 3k + 1, 11000111...
	for(int i = 1; i <= N; i+=2){
		cases[6][i] = 0;
	}
	for(int i = 1; i <= N; i+=3){
		cases[6][i] = !cases[6][i];
	}
	//Case 8 generate as no button, is already generated as 11111111...

	//Match criteria
	while(!ON.empty()){
		int lamp = ON.top();
		ON.pop();
		for(int i = 0; i < 8; i++){
			if(!cases[i][lamp]) cases[i][0] = 0;
		}
	}
	while(!OFF.empty()){
		int lamp = OFF.top();
		OFF.pop();
		for(int i = 0; i < 8; i++){
			if(cases[i][lamp]) cases[i][0] = 0;
		}
	}
	//Special case for 0 counts, where all are impossible except last case
	if(!C){
		for(int i = 0; i < 7; i++)
			cases[i][0] = 0;
	}
	//Special case for 1 count, where cases 2,5,7,8 are impossible
	if(C == 1){
		cases[1][0] = 0;
		cases[4][0] = 0;
		cases[6][0] = 0;
		cases[7][0] = 0;
	}
	//Special case for 2 counts, where case 4 is impossible
	if(C == 2){
		cases[3][0] = 0;
	}
	//Special case for 3 counts, where case 5 is impossible
	if(C == 3){
		cases[4][0] = 0;
	}
	//All counts > 3 has all possible cases
	bool imp = 1;
	for(int i = 0; i < 8; i++){
		if(cases[i][0]) imp = 0;
	}
	if(imp){
		fout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(int i = 0; i < 8; i++){
		if(cases[i][0]){
			for(int j = 1; j <= N; j++)
				fout << cases[i][j];
			fout << endl;
		}
	}
	return 0;
}

//Note: Rather than using arrays, 6 bit integers can actually be faster.