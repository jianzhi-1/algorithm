ll n, mod = 1e9 + 7;

struct matrix {
	
	ll siz, m[50][50];
	
	matrix(int n, ll arr[][50]){
		siz = n;
		REP(i, 0, n){
			REP(j, 0, n) m[i][j] = arr[i][j];
		}
	}
	
	matrix clone(){ return matrix(siz, m); }
	
	ll & operator()(int i, int j){ return m[i][j]; }
	
	matrix operator* (matrix b){

		matrix a = (*this).clone();
		matrix res = b;
		
		REP(i, 0, a.siz){
			REP(j, 0, b.siz){
				res.m[i][j] = 0;
				REP(k, 0, a.siz){
					res.m[i][j] += a.m[i][k]*b.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}
		
		return res;
	}
	
};

matrix expo(matrix a, ll n){
	if (n == 1) return a;
	matrix half = expo(a, n/2);
	half = half*half;
	if (n % 2 == 1) half = half*a;
	return half;
}

int main(){
	
	cin >> n;
	
	ll a[50][50]; //must initialise as a[][50]
	a[0][0] = 19; a[0][1] = 7; a[1][0] = 6; a[1][1] = 20;
	
	matrix fib = matrix(2, a);
	
	matrix ans = expo(fib, n);
	cout << ans(0, 0) << endl;
	
}
