const ll MAX_INT = 500005;
ll mod = 1e9 + 7;
ll f[MAX_INT];
ll invf[MAX_INT];
ll n, m;

ll power(ll a, ll b){
	a %= mod;
	if (b == 0) return 1;
	if (b == 1) return a;
	ll half = power(a, b/2);
	half = (half*half)%mod;
	if (b % 2) half = (half*a)%mod;
	return half;
}

void init(){
	f[0] = 1;
	invf[0] = power(f[0], mod - 2);
	REP(i, 1, MAX_INT){
		f[i] = (f[i - 1]*i)%mod;
		invf[i] = power(f[i], mod - 2);
	}
}

ll choose(ll n, ll k){
	return (((f[n]*invf[k])%mod)*invf[n - k])%mod;
}

ll perm(ll n, ll k){
	return (f[n]*invf[n - k])%mod;
}

int main(){
	init();
	cin >> n >> m;
	cout << choose(n, m) << endl;
	cout << perm(n, m) << endl;
}
