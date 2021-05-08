//on the fly if necessary
ll memo[MAX_K][MAX_N];
int opt[MAX_N];

//l and r inclusive
//optl and optr inclusive
void dnc(int l, int r, int optl, int optr, int k){
	if (l > r) return;
	int mid = (l + r)/2;
    
    //do NOT set INF as base, always set to a possible value
	pi cur;
	if (mid == 0) cur = MP(0, 0);
	else cur = MP(memo[k - 1][mid - 1], mid - 1);
	
	REP(i, optl, min(mid - 1, optr) + 1){
        //cur = min(cur, MP(cost function, opt index))
		cur = min(cur, MP(memo[k - 1][i] + (rs[mid][mid] - rs[i][mid] - rs[mid][i] + rs[i][i])/2, (ll)i));
	}
    
	opt[mid] = cur.S;
	memo[k][mid] = cur.F;
	dnc(l, mid - 1, optl, opt[mid], k);
	dnc(mid + 1, r, opt[mid], optr, k);
	
}

int main(){
    //prepare cost function
	
	REP(i, 0, k + 1){
		if (i == 0){
			memo[0][0] = 0;
			REP(j, 1, n + 1) memo[0][j] = INF;
			continue;
		}
		dnc(0, n, 0, n, i);
	}
    
    cout << memo[k][n] << endl;

}
