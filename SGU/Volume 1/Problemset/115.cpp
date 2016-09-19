//Title: Calendar
//Type: Simulation
//Solution: January 1st, 2001 is a Monday :D, and it's not a leap year.
#include <cstdio>
using namespace std;
int ans[32][13];
int main(){
	//Instantiation
	int N, M;
	scanf("%d %d", &N, &M);
	//Impossible cases
	if(M > 12){
		printf("Impossible\n");
		return 0;
	}else if((M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) && N > 31){
		printf("Impossible\n");
		return 0;
	}else if(M == 2 && N > 28){
		printf("Impossible\n");
		return 0;
	}else if((M == 4 || M == 6 || M == 9 || M == 11) && N > 30){
		printf("Impossible\n");
		return 0;
	}
	//Simulate
	int day = 1, month = 1, date = 1;
	for(int i = 1; i <= 365; i++){
		ans[date][month] = day;
		//Changing day
		if(day == 7)
			day = 1;
		else
			day++;
		//Changing month & date
		if(month == 2 && date == 28){
			month++;
			date = 1;
		}else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date == 31){
			month++;
			date = 1;
		}else if((month == 4 || month == 6 || month == 9 || month == 11) && date == 30){
			month++;
			date = 1;
		}else{
			date++;
		}
	}
	printf("%d\n", ans[N][M]);
	return 0;
}