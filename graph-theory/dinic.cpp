struct flowEdge{
    int u, v; // vertices of this edge
    ll cap, flow = 0; // capacity and flow
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
        // n: total nodes, s: source node, t: sink node
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
	
    void add_edge(int u, int v, ll cap){
        edgeList.PB(flowEdge(u, v, cap));
        edgeList.PB(flowEdge(v, u, 0)); //residue edge
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

    vector<vector<int> > residual_graph;
    vector<bool> mincut_visited;

    void mincut_dfs(int node){
        mincut_visited[node] = true;
        for (auto it = residual_graph[node].begin(); it != residual_graph[node].end(); it++){
            if (mincut_visited[*it]) continue;
            mincut_dfs(*it); 
        }
    }

    vector<ll> mincut(){ // returns set S of mincut (S, T)
        // run maxflow first
        residual_graph.resize(n);
        mincut_visited.resize(n, false);

        for (auto it = edgeList.begin(); it != edgeList.end(); it++){
            if (it -> cap > 0 && it -> flow == it -> cap) continue;
            if (it -> cap == 0 && it -> flow == 0) continue;
            residual_graph[it -> u].PB(it -> v);
        }
        
        mincut_dfs(s);
        vector<ll> res;
        for (int i = 0; i < n; i++){
            if (mincut_visited[i]) res.PB(i);
        }
        return res;
    }
};

int main(){
    dinic graph = dinic(n + 2, 0, n + 1); // usually, create n + 2 nodes with one sink and one source
    graph.add_edge(0, i, b[i]); // add edge between source and node i with capacity b[i]
    graph.add_edge(i, n + 1, c[i]); // add edge between node i and sink with capacity c[i]
	
    cout << graph.flow() << endl; // max flow
	
    VREP(it, graph.edgeList){
        if (it -> flow == it -> cap && it -> flow > 0){
            // edge is in use and maximum capacity
        } else if (it -> flow > 0){
            // edge is in use
        } else {
            // not in use edges or residue edges
        }
    }

    vector<ll> res = graph.mincut();
    cout << res.size() << endl;
    VREP(it, res){
        cout << *it << endl;
    }
}
