#include <cstdio>
#include <cstring>
using namespace std;
int q, n, L, R, sl, el, sr, er, t, ansL, ansR;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		L = ansL = ansR = 1;
		for(int i = 1; i <= n; i++){
			//printf("%d\n", t);
			scanf("%d%d%d%d", &sl, &el, &sr, &er);
			if(t < sl && t < sr){
				t = el < er ? el : er;
				R = i;
			}else if(t < sl){
				t = el;
				R = i;
			}else if(t < sr){
				t = er;
				R = i;
			}else{
				if((R - L) > (ansR - ansL)){
					ansL = L;
					ansR = R;
				}
				L = R = i;
				if(el < er)
					t = el;
				else
					t = er;
			}
		}
		if((R - L) > (ansR - ansL)){
			ansL = L;
			ansR = R;
		}
		printf("%d %d\n", ansL, ansR);
		t = 0;
	}
    return 0;
}