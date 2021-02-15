struct tarjan{
	int n, m = 0, vcount = 0; //number of nodes, number of sccs
	vector<vector<int> > adjList, scc;
	vector<set<int> > sccDag; //DAG of SCCs
	vector<int> sccIndex, topo;
	vector<bool> visited;
	vector<pi> vv;
	stack<int> st;
	
	tarjan(int n): n(n){
		adjList.resize(n);
		visited.resize(n);
		vv.resize(n);
		sccIndex.resize(n);
		sccDag.resize(n);
		scc.resize(n);
		REP(i, 0, n){
			visited[i] = false;
			vv[i] = MP(-1, -1);
			sccIndex[i] = -1;
		}
		m = 0; vcount = 0;
	}
	
	void addEdge(int a, int b){
		adjList[a].PB(b);
	}
	
	void dfs(int x){
		if (vv[x].first != -1) return;
		st.push(x);
		visited[x] = true;
		vv[x] = MP(vcount, vcount);
		vcount++;
		VREP(it, adjList[x]){
			if (vv[*it].first == -1) dfs(*it);
			if (visited[*it]) vv[x].second = min(vv[*it].second, vv[x].second);
		}
		
		if (vv[x].first == vv[x].second){
			while (true){
				int cur = st.top();
				st.pop();
				sccIndex[cur] = m;
				scc[m].PB(cur);
				visited[cur] = false;
				if (x == cur) break;
			}
			m++;
		}
	}
	
	void dfs_topo(int x){
		if (visited[x]) return;
		visited[x] = 1;
		VREP(it, sccDag[x]){
			if (visited[*it]) continue;
			dfs_topo(*it);
		}
		topo.PB(x);
	}
	
	void compute(){
		REP(i, 0, n) dfs(i);
		REP(i, 0, n){
			VREP(it, adjList[i]){
				if (sccIndex[i] != sccIndex[*it]) sccDag[sccIndex[i]].insert(sccIndex[*it]);
			}
		}
		REP(i, 0, m) visited[i] = false;
		REP(i, 0, m) dfs_topo(i);
		reverse(topo.begin(), topo.end());
	}
};

int main(){

	tarjan x = tarjan(n);
	x.addEdge(0, 1);
	x.compute();
  
	cout << x.m << endl;
	VREP(it, x.topo){
		cout << sz(x.scc[*it]);
		REP(j, 0, sz(x.scc[*it])) cout << " " << x.scc[*it][j];
		cout << endl;
	}
}
