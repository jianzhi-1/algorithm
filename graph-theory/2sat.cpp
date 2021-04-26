struct TwoSat{
	
	int n; //number of real and conjugate nodes
	vector<vector<int> > g, gt; //graph of implication and transposed
	vector<bool> used;
	vector<int> order, comp;
	vector<bool> assignment; //assignment of true/false for real nodes
    
    //all even nodes are real
    //all odd nodes are conjugate
    //conjugate of 2*x is 2*x + 1 (or equivalently (2x)^1)
	
	TwoSat(int nn){
		//nn - number of nodes (not including conjugate)
		n = 2*nn; //real node and conjugate node
		g.resize(n);
		gt.resize(n);
	}
	
	void addOrEdge(int x, int y){
		//(x or y), equivalently if not x then y, if not y then x
		int notx = (x^1), noty = (y^1);
		g[noty].PB(x); g[notx].PB(y);
		gt[x].PB(noty); gt[y].PB(notx);
	}
	
	void addImplicationEdge(int x, int y){
		//if x then y
		int notx = (x^1), noty = (y^1);
		g[x].PB(y); gt[y].PB(x);
		g[noty].PB(notx); gt[notx].PB(noty);
	}
	
	void dfs1(int v){
		used[v] = true;
		VREP(it, g[v]){
			if (!used[*it]) dfs1(*it);
		}
		order.PB(v);
	}
	
	void dfs2(int v, int cl){
		comp[v] = cl;
		VREP(it, gt[v]){
			if (comp[*it] == -1) dfs2(*it, cl);
		}
	}
	
	bool solve(){
		used.assign(n, false);
		comp.assign(n, -1);
		REP(i, 0, n){
			if (!used[i]) dfs1(i);
		}
		int j = 0;
		REP(i, 0, n){
			int v = order[n - 1 - i];
			if (comp[v] == -1) dfs2(v, j++);
		}
		assignment.assign(n/2, false);
		for (int i = 0; i < n; i+=2){
			if (comp[i] == comp[i + 1]) return false;
			assignment[i/2] = (comp[i] > comp[i + 1]);
		}
		return true;
	}
};

int main(){

	TwoSat h = TwoSat(n);
    
	h.addOrEdge(x, y); //(x OR y)
    h.addImplicationEdge(x, y) //x implies y
    
	bool ans = h.solve();
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
    
	REP(i, 0, n) cout << h.assignment[i] << endl;
    
}
