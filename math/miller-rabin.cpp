ll power(ll x, ll y, ll p){
    ll res = 1;
    x %= p; 
    while (y > 0){
        if (y&1) res = (res*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
 
bool millerTest(ll d, ll n){
  
    ll a = 2 + rand()%(n - 4);
    ll x = power(a, d, n);
 
    if (x == 1 || x == n - 1) return true;
 
    while (d != n - 1){
        x = (x*x) % n;
        d *= 2;
 
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
 
    return false;
}
 
bool isPrime(ll n, ll k){
    
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
  
    REP(i, 0, k){
        if (!millerTest(d, n)) return false;
    }
 
    return true;
}
 
