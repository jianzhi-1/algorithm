ll power(ll a, ll b){
    a %= mod;
    if (b == 0) return 1;
    if (b == 1) return a;
    ll half = power(a, b/2);
    half = (half*half)%mod;
    if (b % 2) half *= a;
    return half%mod;
}

//mat must be a square matrix
ll determinant(vector<vector<ll> > mat, ll mod){
	
	ll n = sz(mat), num1 = 0, num2 = 0, det = 1, index = 0, total = 1;
    ll temp[n + 1];
 
    REP(i, 0, n){
        
		index = i; 
        while (index < n && mat[index][i] == 0) index++;
        if (index == n) return 0;
        
        if (index != i){
            REP(j, 0, n) swap(mat[index][j], mat[i][j]);
            det *= -1;
            det = ((det%mod)+mod)%mod;
        }
 

        REP(j, 0, n) temp[j] = mat[i][j];
        
        for (int j = i + 1; j < n; j++){
            num1 = temp[i];
            num2 = mat[j][i];
 
            REP(k, 0, n){
                mat[j][k] = (num1 * mat[j][k]) - (num2 * temp[k]);
                mat[j][k] = (mat[j][k] + mod)%mod;
            }
            
            total *= num1;
            total = (total%mod + mod)%mod;
        }
    }
 
    REP(i, 0, n){
    	det *= mat[i][i];
    	det = (det%mod + mod)%mod;
	}
    
    return ((det*power(total, mod - 2))%mod + mod)%mod;
}
