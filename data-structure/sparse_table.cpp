struct sparseTable{
    
	int n, logn;
	vector<vector<int> > v;
    
	sparseTable(vector<int> a){
		n = sz(a);
		int c = 0, cur = 1;
		while (cur <= sz(a)){
			cur *= 2; c++;
		}
		logn = c;
		v.resize(logn);
		REP(i, 0, sz(v)) v[i].resize(n);
		
		
		REP(i, 0, logn){
			if (i == 0){
				REP(j, 0, n) v[i][j] = a[j];
			} else {
				for (int j = 0; j + (1 << i) - 1 < n; j++){
					v[i][j] = gcd(v[i - 1][j], v[i - 1][j + (1 << (i - 1))]);
				}
			}
		}
		
	}
	
	///inclusive, op(a, a) = a
	int query(int l, int r){
		int cur = 1, c = 0;
		while (cur*2 <= (r - l + 1)){
			cur *= 2; c++;
		}
		return gcd(v[c][l], v[c][r - cur + 1]);
	}
	
};

int main(){

	sparseTable s = sparseTable(vv);

	cout << s.query(l, r) << endl;

}
