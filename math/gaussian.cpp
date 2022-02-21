vector<int> v[4000000];
vector<int> solution;

ll f(char c){
	if ('A' <= c && c <= 'Z') return (int)c - 65;
	if ('0' <= c && c <= '9') return (int)c - 22;
	return 36;
}

ll power(ll x, ll y){
	x %= 37;
	if (y == 0) return 1;
	if (y == 1) return x;
	ll half = power(x, y/2);
	half *= half;
	half %= 37;
	if (y % 2 == 1) half *= x;
	return half % 37;
}

bool checkzero(int x){ // check if row x is zero
	REP(i, 0, v[x].size()){
		if (v[x][i] != 0) return false;
	}
	return true;
}

vector<int> temp;
void switchRow(int x, int y){ //switch row x and row y
	temp.clear();
	REP(i, 0, v[x].size()) temp.PB(v[x][i]);
	v[x].clear();
	REP(i, 0, v[y].size()) v[x].PB(v[y][i]);
	v[y].clear();
	REP(i, 0, temp.size()) v[y].PB(temp[i]);
	temp.clear();
}

void multiplyRow(int x, int k){ //multiply row x by k mod 37
	REP(i, 0, v[x].size()) v[x][i] = (v[x][i]*k)%37;
}

void rowSubstract(int x, int y){ //subtract y from x
	REP(i, 0, v[x].size()){
		v[y][i] -= v[x][i];
		v[y][i] %= 37;
		v[y][i] = (v[y][i] + 37)%37;
	}
}

void rowReduce(int x, int y, int i){ //reduce at pivot column i
	if (v[y][i] == 0) return;
	int inv = power(v[y][i], 35);
	multiplyRow(y, inv);
	rowSubstract(x, y);
}

void rowSubstractMultiple(int x, int y, int i){ //reduce at pivot column i
	if (v[y][i] == 0) return;
	int c = v[y][i];
	REP(j, 0, v[y].size()){
		v[y][j] -= c*v[x][j];
		v[y][j] %= 37;
		v[y][j] = (v[y][j]+37)%37;
	}
}

int gaussian(int nn){
	int mm = v[0].size() - 1; //augmented matrix
	int rank = 0;
	for (int i = 0; i < mm; i++){
		int first = -1;
		for (int j = rank; j < nn; j++){
			if (v[j][i] != 0){
				first = j;
				break;
			}
		}
		if (first == -1) continue;
		multiplyRow(first, power(v[first][i], 35));
		switchRow(first, rank);
		for (int j = rank + 1; j < nn; j++) rowReduce(rank, j, i);
		rank++;
	}
	
	//check for no solutions
	bool nosolution = false;
	for (int i = 0; i < nn; i++){
		bool allzero = true;
		for (int j = 0; j < mm; j++){
			if (v[i][j] != 0){
				allzero = false;
				break;
			}
		}
		if (allzero){
			if (v[i][mm] != 0){
				nosolution = true;
				break;
			}
		}
	}
	
	if (nosolution) return -1;
	if (rank > n) return -1;
	if (rank < n) return -2; //infinite solutions
	
	// backsolve
	vector<int> tt;
	for (int i = n - 1; i >= 0; i--){
		tt.PB(v[i][mm]);
		for (int j = 0; j < mm; j++){
			if (v[i][j] == 1){
				for (int kk = 0; kk < i; kk++){
					rowSubstractMultiple(i, kk, j);
				}
				break;
			}
		}
	}
	
	reverse(tt.begin(), tt.end());
	VREP(it, tt) solution.PB(*it);
	tt.clear();
	return 0;
	
}

void debug(int nn){
	for (int i = 0; i < nn; i++){
		for (int j = 0; j < v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
}
