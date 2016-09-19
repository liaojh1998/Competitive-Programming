//Title: Telecasting station
//Type: Math
//Solution: Weighted Median Algorithm
		/*	https://en.wikipedia.org/wiki/Weighted_median	*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct c{
	double X, P;
	bool operator<(const c &a){
		return X < a.X;
	}
}city[15000];
double sum, tempsum;
int main(){
	//Instantiation
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lf %lf", &city[i].X, &city[i].P);
		sum+= city[i].P;
	}
	sort(city, city+N);
	//Weighted Median Algorithm
	sum /= 2;
	for(int i = 0; i < N; i++){
		tempsum+= city[i].P;
		if(tempsum == sum){
			printf("%.5lf\n", (city[i].X + city[i+1].X)/2);
			break;
		}else if(tempsum > sum){
			printf("%.5lf\n", city[i].X);
			break;
		}
	}
	return 0;
}