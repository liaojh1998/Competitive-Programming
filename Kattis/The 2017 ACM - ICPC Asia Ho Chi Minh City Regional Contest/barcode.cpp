#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct matrix{
	T _00, _01, _10, _11, mod;
	matrix(const T& M){
		_00 = 1;
		_01 = 0;
		_10 = 0;
		_11 = 1;
		mod = M;
	}
	matrix(const T& a, const T& b, const T& c, const T& d, const T& M){
		_00 = a;
		_01 = b;
		_10 = c;
		_11 = d;
		mod = M;
	}
	matrix<T> operator*(matrix<T> m){
		matrix<T> tmp(mod);
		tmp._00 = ((_00*m._00)%mod + (_01*m._10)%mod)%mod;
		tmp._01 = ((_00*m._01)%mod + (_01*m._11)%mod)%mod;
		tmp._10 = ((_10*m._00)%mod + (_11*m._10)%mod)%mod;
		tmp._11 = ((_10*m._01)%mod + (_11*m._11)%mod)%mod;
		return tmp;
	}
	matrix<T> operator+(matrix<T> m){
		matrix<T> tmp(mod);
		tmp._00 = (_00+m._00)%mod;
		tmp._01 = (_01+m._01)%mod;
		tmp._10 = (_10+m._10)%mod;
		tmp._11 = (_11+m._11)%mod;
		return tmp;
	}
	matrix<T> operator=(matrix<T> m){
		mod = m.mod;
		_00 = m._00;
		_01 = m._01;
		_10 = m._10;
		_11 = m._11;
		return (*this);
	}
	matrix<T> fexp(T p){
		matrix<T> b = (*this), ans(mod);
		while(p){
			if(p&1)
				ans = (b*ans);
			b = (b*b);
			p >>= 1;
		}
		return ans;
	}
};

long long fexp(long long b, long long p, long long MOD){
	long long ans = 1;
	while(p){
		if(p&1)
			ans = (ans * b)%MOD;
		b = (b * b)%MOD;
		p >>= 1;
	}
	return ans;
}

long long fact(long long p, long long q, long long MOD, long long& count){
	if(p == q){
		while(!(p%MOD)){
			count++;
			p /= MOD;
		}
		return p%MOD;
	}
	return (fact(p, (p+q)/2, MOD, count)*fact((p+q)/2+1, q, MOD, count))%MOD;
}

long long nCr(long long n, long long r, long long MOD){
	//cout << "n, r: " << n << " " << r << endl;
	//cout << "top: " << fact(r+1, n, MOD) << endl;
	//cout << "bottom: " << fact(1, n-r, MOD) << endl;
	//cout << "n-r: " << n-r << endl;
	long long countnum = 0, countdem = 0, num = fact(r+1, n, MOD, countnum), dem = fact(1, n-r, MOD, countdem);
	//cout << "nCr(n, r): " << ((countnum > countdem) ? 0 : (num*fexp(dem, MOD-2, MOD))%MOD) << endl;
	if(countnum > countdem)
		return 0;
	return (num*fexp(dem, MOD-2, MOD))%MOD;
}

/*long long fib(long long a, long long b, long long N, long long M){
	if(N)
		return fib(b, (a+b)%M, N-1, M);
	return b;
}

long long fib(long long N, long long M){
	return fib(2, 3, N, M);
}*/

long long solve(long long N, long long M){
	if(N == 1)
		return 2%M;
	if(N == 2)
		return 3%M;
	matrix<long long> m(1, 1, 1, 0, M), ans(M);
	ans = m.fexp(N-2);
	//cout << "compare: fib(N-2) == matrix(N-2): " << fib(N-2, M) << "==" << ((3*ans._00)%M + (2*ans._01)%M)%M << endl;
	return (((3*ans._00)%M + (2*ans._01)%M)%M + ((N&1) ? 0 : (nCr(N, N/2, M) + (((N/2)/M+1)*M - N/2) + (M - 1))%M))%M;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	long long N, M;
	cin >> T;
	while(T--){
		cin >> N >> M;
		cout << solve(N, M) << endl;
	}
	return 0;
}