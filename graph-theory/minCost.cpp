struct Edge{
    int from, to, capacity, cost;
    Edge(int f, int t, int c, int cc): from(f), to(t), capacity(c), cost(cc){}
};

vector<vector<int> > adjList, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int> &d, vector<int> &p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        VREP(it, adjList[u]){
            if (capacity[u][*it] > 0 && d[*it] > d[u] + cost[u][*it]) {
                d[*it] = d[u] + cost[u][*it];
                p[*it] = u;
                if (!inq[*it]) {
                    inq[*it] = true;
                    q.push(*it);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
	
    adjList.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    
    VREP(it, edges){
        adjList[it -> from].PB(it -> to);
        adjList[it -> to].PB(it -> from);
        cost[it -> from][it -> to] = it -> cost;
        cost[it -> to][it -> from] = -(it -> cost);
        capacity[it -> from][it -> to] = it -> capacity;
    }

    int flow = 0, cost = 0;
    vector<int> d, p;
    
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF) break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K) return -1;
    else return cost;
}

int main(){
        
    cin >> n; //total number of nodes
	vector<Edge> e;
    
    //set up graph
    e.PB(Edge(startNode, endNode, edge_cap, edge_cost));
    
    //returns -1 if no such flow exists
	cout << min_cost_flow(n, e, desired_flow, source, sink) << endl;
	
}
