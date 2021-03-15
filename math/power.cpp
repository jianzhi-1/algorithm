ll mod = 1e9 + 7;

ll power(ll a, ll b){
    a %= mod;
    if (b == 0) return 1;
    if (b == 1) return a;
    ll half = power(a, b/2);
    half = (half*half)%mod;
    if (b % 2) half *= a;
    return half%mod;
}
