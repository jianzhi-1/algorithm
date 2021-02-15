struct flowEdge{
	int u, v;
	ll cap, flow = 0;
	flowEdge(int u, int v, ll cap): u(u), v(v), cap(cap) {}
};

struct dinic{
	const ll flow_inf = 1e18;
	vector<flowEdge> edgeList;
	vector<vector<int> > adj;
	int n, m = 0, s, t;
	vector<int> level, ptr;
	queue<int> q;
	
	dinic(int n, int s, int t): n(n), s(s), t(t){
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}
	
	void add_edge(int u, int v, ll cap){
		edgeList.emplace_back(u, v, cap);
		edgeList.emplace_back(v, u, 0);
		adj[u].PB(m);
		adj[v].PB(m + 1);
		m+=2;
	}
	
	bool bfs(){
		while (!q.empty()){
			int x = q.front();
			q.pop();
			for (int id: adj[x]){
				if (edgeList[id].cap - edgeList[id].flow < 1) continue;
				if (level[edgeList[id].v] != -1) continue;
				level[edgeList[id].v] = level[x] + 1;
				q.push(edgeList[id].v);
			}
		}
		return (level[t] != -1);
	}
	
	ll dfs(int x, ll pushed){
		if (pushed == 0) return 0;
		if (x == t) return pushed;
		for (int& cid = ptr[x]; cid < (int)adj[x].size(); cid++){
			int id = adj[x][cid], v = edgeList[id].v;
			if (level[x] + 1 != level[v] || edgeList[id].cap - edgeList[id].flow < 1) continue;
			ll tr = dfs(v, min(pushed, edgeList[id].cap - edgeList[id].flow));
			if (tr == 0) continue;
			edgeList[id].flow += tr;
			edgeList[id^1].flow -= tr;
			return tr;
		}
		return 0;
	}
	
	ll flow(){
		ll f = 0;
		while (true){
			fill (level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs()) break;
			fill(ptr.begin(), ptr.end(), 0);
			while (ll pushed = dfs(s, flow_inf)) f += pushed;
		}
		return f;
	}
};

int main(){
	dinic m = dinic(n + 2, 0, n + 1);
	m.add_edge(0, i, b[i]);
	cout << m.flow() << endl;
}
