// NTT
template <int mod, int primitive_root>
struct NTT {
	
	ll power(ll x, ll n, ll m) {
		ll res = 1;
		if (n > 0) {
	  		res = power(x, n / 2, m);
	  		if (n % 2 == 0) res = (res * res) % m;
	  		else res = (((res * res) % m) * x) % m;
		}
		return res;
	}

	ll mod_inv(ll x, ll m) { return power(x, m - 2, m); }
	
	int get_mod() { return mod; }

	void _ntt(vector<ll> &a, int sign) {
		int n = a.size();
		assert((n ^ (n & -n)) == 0); // n = 2^k
	
		int g = primitive_root, h = (int) power(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int) mod_inv(h, mod); // h = h^-1 % mod

		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; j++) {
			for (int k = n >> 1; k > (i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}

		for (int m = 1; m < n; m *= 2) {
			int m2 = 2 * m;
			ll base = power(h, n / m2, mod), w = 1;
			for (int x = 0; x < m; x++) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s], d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}

		for (auto &x : a) if (x < 0) x += mod;
	}

	void ntt(vector<ll> &input) { _ntt(input, 1); }
	
	void intt(vector<ll> &input) {
		_ntt(input, -1);
		int n_inv = mod_inv(input.size(), mod);
		for (auto &x : input) x = x * n_inv % mod;
	}

	vector<ll> convolution(const vector<ll> &a, const vector<ll> &b){
		int ntt_size = 1;
		while (ntt_size < a.size() + b.size()) ntt_size *= 2;
		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);
		ntt(_a); ntt(_b);
		for (int i = 0; i < ntt_size; i++) (_a[i] *= _b[i]) %= mod;
		intt(_a);
		_a.resize(a.size() + b.size() - 1);
		return _a;
	}
};


ll n, m;
const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<ll> a(n), b(m);
	REP(i, 0, n) cin >> a[i];
	REP(i, 0, m) cin >> b[i];

	NTT<mod, 3> ntt;
	//<998244353, 3>
	//<1000000007, 5>
	//<1000000009, 13>
	
	auto c = ntt.convolution(a, b);

	REP(i, 0, sz(c)){
		if (i) cout << " ";
		cout << c[i];
	}
	cout << endl;
}
