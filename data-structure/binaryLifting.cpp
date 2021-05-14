int p[MAX_N][LOGN + 1];

ll query(ll l, ll r){
	for (int i = LOGN; i >= 0; i--){
		if (p[l][i] <= r) return (1 << i) + query(p[l][i], r);
	}
	return 1;
}

int main(){
    
	REP(i, 0, MAX_N){
		REP(j, 0, LOGN + 1){
			p[i][j] = MAX_N;
		}
	}
    
    //fill up the first layer p[i][0]
    
	REP(j, 1, LOGN + 1){
		REP(i, 0, MAX_N) p[i][j] = p[p[i][j - 1]][j - 1];
	}
    
    cout << query(l, r) << endl;
    
}
