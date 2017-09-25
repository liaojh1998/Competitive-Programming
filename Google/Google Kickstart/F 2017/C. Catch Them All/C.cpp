#include <bits/stdc++.h>
using namespace std;

class FastIO{
private:
	int readInt(int &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readDouble(double &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
		double div = 1;
		for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
		n /= div;
		if(neg) n = -n;
		return 1;
	}

public:
	FastIO(bool useFile = false){
		if(useFile){
			freopen("C.in", "r", stdin);
			freopen("C.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

template<typename T> struct matrix{
	T _00, _01, _10, _11;
	matrix(T a, T b, T c, T d){
		_00 = a;
		_01 = b;
		_10 = c;
		_11 = d;
	}
	void operator*=(const matrix& m){
		T a = _00*m._00 + _01*m._10;
		T b = _00*m._01 + _01*m._11;
		T c = _10*m._00 + _11*m._10;
		T d = _10*m._01 + _11*m._11;
		_00 = a; _01 = b; _10 = c; _11 = d;
	}
	matrix<T> operator*(const matrix& m){
		T a = _00*m._00 + _01*m._10;
		T b = _00*m._01 + _01*m._11;
		T c = _10*m._00 + _11*m._10;
		T d = _10*m._01 + _11*m._11;
		return matrix<T>(a, b, c, d);
	}
	void operator+=(const matrix& m){
		_00 += m._00;
		_01 += m._01;
		_10 += m._10;
		_11 += m._11;
	}
	matrix<T> operator+(const matrix& m){
		return matrix<T>(_00+m._00, _01+m._01, _10+m._10, _11+m._11);
	}
};

//Matrix of matrices binary exponentiation
matrix<double> logexp(int N, int P){
	const matrix<double> one = matrix<double>(1.000000, 0.000000, 0.000000, 1.000000);
	const matrix<double> base = matrix<double>(0.000000, 1.000000, 1.000000/(double)N, (double)(N-1.000000)/N);
	matrix<double> sum = matrix<double>(0.000000, 0.000000, 0.000000, 0.000000);
	matrix<double> tempsum = one;
	matrix<double> tempb = one;
	matrix<double> b = base;
	while(P){
		if(P & 1){
			sum = tempsum*tempb+sum;
			tempb *= b;
		}
		tempsum = tempsum*b+tempsum;
		b *= b;
		P >>= 1;
	}
	return sum*base+one;
}

void FastIO::solve(){
	int T;
	readInt(T);
	for(int idx = 1; idx <= T; idx++){
		int N, M, P, u, v;
		double w;
		readInt(N);
		readInt(M);
		readInt(P);
		double dp[N+5][N+5];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				dp[i][j] = 1000.000000;
		for(int i = 0; i < M; i++){
			readInt(u);
			readInt(v);
			readDouble(w);
			dp[u-1][v-1] = dp[v-1][u-1] = w;
		}
		for(int i = 0; i < N; i++)
			dp[i][i] = 0.000000;
		//Floyd-Warshall O(N^3)
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					if(dp[i][j] > dp[i][k]+dp[k][j])
						dp[i][j] = dp[i][k]+dp[k][j];
		//Summation O(N + N^2)
		double s_1 = 0.000000;
		for(int i = 0; i < N; i++)
			s_1 += dp[0][i];
		double s_n = 0.000000;
		for(int i = 1; i < N; i++)
			for(int j = 0; j < N; j++)
				s_n += dp[i][j];
		//Matrix Exponentiation O(log(P))
		matrix<double> sum = logexp(N-1, P-1);
		double inverse = 1.000000/(double)(N-1);
		//In total: O(N^3 + log(P))
		printf("Case #%d: %.6lf\n", idx, s_1*inverse*sum._00 + s_n*inverse*sum._10);
	}
}