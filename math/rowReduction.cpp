int r, c;
vector<vector<ld> > mat;
const ld eps = 1e-9;
int main(){
	cin >> r >> c;
	mat.resize(r);
	REP(i, 0, r) mat[i].resize(c);
	REP(i, 0, r){
		REP(j, 0, c) cin >> mat[i][j];
	}
	
	int idx = 0;
	
	REP(j, 0, c){
		//find smallest element that is non-zero
		pair<ld, pair<ld, int> > cur = MP(2e9, MP(2e9, -1));
		REP(i, idx, r){
			if (abs(mat[i][j]) < eps) continue;
			cur = min(cur, MP(abs(mat[i][j]), MP(mat[i][j], i)));
		}
		if (cur.se.se == -1) continue; //the column is simply all zero
		mat[idx].swap(mat[cur.se.se]);
		ld mult = 1.0/mat[idx][j];
		REP(k, 0, c) mat[idx][k] *= mult;
		REP(i, 0, r){
			if (i == idx) continue;
			ld pos = mat[i][j];
			REP(k, 0, c) mat[i][k] -= pos*mat[idx][k];
		}
		
		idx++;
	}
	
	REP(i, 0, r){
		REP(j, 0, c){
			if (j != 0) cout << " ";
			if (abs(mat[i][j]) < eps) cout << 0;
			else cout << mat[i][j];
		}
		cout << endl;
	}
}
